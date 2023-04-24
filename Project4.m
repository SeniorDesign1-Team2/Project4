% close all
% clc
% clear
% clear('cam')
% 
% % find webcam 
% cam_list = webcamlist;
% 
% cam_name = cam_list{1};
% 
% cam = webcam(cam_name);
% 
% 
% preview(cam);
% 
%%
% %% take picture of image before shapes
% closePreview(cam);
% data.orig = snapshot(cam);
% 
% %% read in image before shapes
% data.orig = imread("Images/PutPutBackground.jpg");
% figure();
% imshow(data.orig)
% [height,width,depth] = size(data.orig);
% 
% %% take picture of camera after shapes are included
% %data.cur = snapshot(cam);
% data.cur = imread("Images/PutPutObjects.jpg");
% figure();
% imshow(data.cur)

%% testing other methods
% clc;
% close all;
% clear;

%Global Vars
% global rgb;

global selectedButton;
app.Label.Text = selectedButton.Text;
display(selectedButton.Text);

%imageCapture();
%data.cur = imread("Images/PutPutObjects.jpg");
% rgb = imread("Images/PutPutObjects.jpg");
% imshow(rgb)


% w = waitforbuttonpress;

% rgb = imread("PutPutObjects.jpg");
rgb = imread("background.png");

[centersBright,radiiBright,metricBright] = imfindcircles(rgb,[10 35], ...
    "ObjectPolarity","bright","Sensitivity",0.91,"EdgeThreshold",0.15);
imshow(rgb)

h = viscircles(centersBright, radiiBright);

hold on;

bottomEdge = {[184, 457], [821, 462]};
gantryPixelLimit = [144, 483];
gantryAngleLimit = [0 -2800];
% gantryDegressPerPixel = ((gantryAngleLimit(1) - gantryAngleLimit(2))) / (gantryPixelLimit(2) - gantryPixelLimit(1));
gantryDegreesPerPixel = 8.69;

removed = 0;
for i=1:length(centersBright)
    if (centersBright(i, 2) >= 90) && (centersBright(i, 2) <= 400)
        STATS(i - removed).Centroid(1) = centersBright(i,1);
        STATS(i - removed).Centroid(2) = centersBright(i,2);
        STATS(i - removed).Radii = radiiBright(i,1);
    else
        removed = removed + 1;
    end
end

colorsNum = {[255,175,175], [175,175,255], [255,255,255], [255, 237, 233]};
colorsName = ["Red", "Blue", "White", "Grey"];


items = 4;
for i = 1:items

    [x,y, STATS(i).centroidColor] = impixel(rgb, STATS(i).Centroid(1),STATS(i).Centroid(2));

    STATS(i).lowestEuclideanDistance = 1000000;
    for j = 1:size(colorsName,2)
        currDistance = round(sqrt((colorsNum{j}(1) - double(STATS(i).centroidColor(1)))^2 + (colorsNum{j}(2) - double(STATS(i).centroidColor(2)))^2 + (colorsNum{j}(3) - double(STATS(i).centroidColor(3)))^2));
        if currDistance < STATS(i).lowestEuclideanDistance
            STATS(i).colorIndex = j;
            if (STATS(i).colorIndex == 3 && STATS(i).Centroid(1) <= 200)
                referecePoint = STATS(i).Centroid;
            end
            STATS(i).lowestEuclideanDistance = currDistance;
        end
        STATS(i).Color = colorsName{STATS(i).colorIndex};
    end

    plot(STATS(i).Centroid(1),STATS(i).Centroid(2),'kO','MarkerFaceColor', 'k', 'MarkerSize', 3);
    text(STATS(i).Centroid(1) - 10,STATS(i).Centroid(2) + 25, "Circle", 'Color', colorsNum{1,STATS(i).colorIndex}/255);
    viscircles(STATS(i).Centroid, STATS(i).Radii,"Color", "k");
end

for i = 1:items
    if (STATS(i).Centroid == referecePoint)
        STATS(i).DistanceAway = 0;
        STATS(i).Dot = 0;
        STATS(i).Det = 0;
        STATS(i).MotorAngle = 0;
    else
        relativePoint1 = [(bottomEdge{2}(1) - referecePoint(1)), bottomEdge{2}(2)/bottomEdge{1}(2)];
        relativePoint2 = [-(referecePoint(1) - STATS(i).Centroid(1)), (referecePoint(2) - STATS(i).Centroid(2))];

        quiver(referecePoint(1), referecePoint(2), relativePoint1(1), relativePoint1(2), 0, "LineWidth", 2, "Color", 'k');
        quiver(referecePoint(1), referecePoint(2), relativePoint2(1), -(relativePoint2(2)), 0, "LineWidth", 2, "Color", colorsNum{1,STATS(i).colorIndex}/255);

        STATS(i).DistanceAway = sqrt((STATS(i).Centroid(1) - referecePoint(1))^2 + (STATS(i).Centroid(2) - referecePoint(2))^2);

        STATS(i).Dot = relativePoint1(1)*relativePoint2(1) + relativePoint1(2)*relativePoint2(2);
        STATS(i).Det = relativePoint1(1)*relativePoint2(2) - relativePoint1(2)*relativePoint2(1);
        motorAngle = atan2(STATS(i).Det, STATS(i).Dot);
        STATS(i).MotorAngle = round((motorAngle * 180 / pi), 2);
        text((referecePoint(1) + relativePoint2(1) + 20), (referecePoint(2) - relativePoint2(2)), "\theta = " + STATS(i).MotorAngle, 'Color', colorsNum{1,STATS(i).colorIndex}/255, 'FontSize', 12);
        
        %Arrow in opposite direction
        %r = 200;
        %quiver(referecePoint(1), referecePoint(2), r*cos(STATS(i).MotorAngle + 3*pi/2), r*sin(STATS(i).MotorAngle + 3*pi/2), 0, "LineWidth", 2, "Color", 'k');
    end
    
end

for k = 1:items
    if strcmp(STATS(k).Color, selectedButton.Text) == 1
        club_angle = num2str(STATS(k).MotorAngle);
        break
    else
        continue
    end
end

for k = 1:items
    if STATS(k).DistanceAway == 0
        y_position = STATS(k).Centroid(2);
        y_degrees = -1 * (y_position - 109) * gantryDegreesPerPixel;
        if y_degrees > 0
            y_degrees = 0;
        end
        if str2double(club_angle) > abs(10)
            y_degrees = y_degrees - 200;
        end

        y_str = num2str(y_degrees);
        set_param('MotorModel_Sp23_V21b/desiredPosition2', 'Value', y_str);
        break
    else
        continue
    end
end

%%
pause('on')
pause(3)

set_param('MotorModel_Sp23_V21b/desiredPosition1', 'Value', club_angle);

pause(3)

set_param('MotorModel_Sp23_V21b/desiredPosition', 'Value', '-235');
pause(3)

set_param('MotorModel_Sp23_V21b/desiredPosition', 'Value', '0');
pause(1)
set_param('MotorModel_Sp23_V21b/desiredPosition1', 'Value', '0');
pause(1)
set_param('MotorModel_Sp23_V21b/desiredPosition2', 'Value', '0');




% function imageCapture()
% 
%     global rgb;
%     rgb = imread("Images/PutPutObjects.jpg");
% %     rgb = snapshot(cam);
% %     imshow(rgb)
% end

% hold off;
% global buttonValue;
% buttonValue = 1;
% 
% buttonFunction();
% % w = waitforbuttonpress;
% % w = waitforbuttonpress;
% % fprintf("After function, value is %d\n", buttonValue);
% 
% 
% fig = uifigure;
% bg = uibuttongroup(fig, 'SelectionChangedFcn', @displaySelection, 'Position', [137,113,123,85]);
% r1 = uiradiobutton(bg, 'Text', 'Blue', 'Position', [10,50,100,22]);
% r2 = uiradiobutton(bg, 'Text', 'Grey', 'Position', [10,28,100,22]);
% r3 = uiradiobutton(bg, 'Text', 'Red', 'Position', [10,6,100,22]);
% 
% function displaySelection(src,event)
%     disp(['Previous: ' event.OldValue.Text]);
%     disp(['Current: ', event.NewValue.Text]);
% end
% 
% function buttonFunction()
%     global buttonValue;
%     uicontrol('Position', [100 10 200 30], 'String', 'Blue', 'Callback', @(src,evnt)buttonCallback(1));
%     uicontrol('Position', [500 10 200 30], 'String', 'Grey', 'Callback', @(src,evnt)buttonCallback(2));
%     uicontrol('Position', [900 10 200 30], 'String', 'Red', 'Callback', @(src,evnt)buttonCallback(3));
%     uicontrol('Position', [100 100 200 30], 'String', 'Start', 'Callback', @(src,evnt)startCallback);
% 
%     function buttonCallback(bValue)
%         buttonValue = bValue;
%     end
%     function startCallback()
%         fprintf("After test value is %d\n", buttonValue);
%     end
% end




% function myButtonTest()
% 
%     global buttonValue;
%     buttonValue = 0;
%     pushBlue = uicontrol(gcf,'Style', 'push', 'String', 'Blue','Position', [100 10 200 30],'CallBack', @blueButton);
%     pushGrey = uicontrol(gcf,'Style', 'push', 'String', 'Grey','Position', [500 10 200 30],'CallBack', @greyButton);
%     pushRed = uicontrol(gcf,'Style', 'push', 'String', 'Red','Position', [900 10 200 30],'CallBack', @redButton);
%     %w = waitforbuttonpress;
%     %fprintf("After test value is %d\n", buttonValue);
% end
% 
% function blueButton(source,event)
%     global buttonValue;
%     display('I pushed the Blue Button');
%     buttonValue = 1;
% end
% 
% function greyButton(source,event)
%     global buttonValue;
%     display('I pushed the Grey Button');
%     buttonValue = 2;
% end
% 
% function redButton(source,event)
%     global buttonValue;
%     display('I pushed the Red Button');
%     buttonValue = 3;
% end


%% TODO
% Location of Gantry
%     Line for Gantry
%     Arrow for Direction
%     Find Intersection Point
% Extend Arrows in opposite direction
% Calculate power coefficient
% GUI
% Physical buttons
% Home location for angle and gantry

