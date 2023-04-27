%% find webcam 
% cam_list = webcamlist;
% 
% cam_name = cam_list{1};
% 
% cam = webcam(cam_name);
% 
% 
% preview(cam);


%% testing other methods
% clc;
% close all;
% clear;

global selectedButton;
app.Label.Text = selectedButton.Text;
display(selectedButton.Text);
%selectedButton.Text = "Grey";

%%
rgb = imread("background.png");


[centersBright,radiiBright,metricBright] = imfindcircles(rgb,[10 35], ...
    "ObjectPolarity","bright","Sensitivity",0.91,"EdgeThreshold",0.15);
imshow(rgb)

%h = viscircles(centersBright, radiiBright);
hold on;

%Update when camera moved
topLeft = [50,76];
topRight = [628, 90];
bottomLeft = [34, 396];
bottomRight = [639, 402];

gantryAngleLimit = [0 -2800];
% gantryDegressPerPixel = ((gantryAngleLimit(1) - gantryAngleLimit(2))) / (gantryPixelLimit(2) - gantryPixelLimit(1));
gantryDegreesPerPixel = 8.69;

removed = 0;
for i=1:length(centersBright)
    if (centersBright(i, 2) >= topRight(2)) && (centersBright(i, 2) <= bottomLeft(2) && centersBright(i, 1) >= topLeft(1))
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
    
    %Find the closest color
    STATS(i).lowestEuclideanDistance = 1000000;
    for j = 1:size(colorsName,2)
        currDistance = round(sqrt((colorsNum{j}(1) - double(STATS(i).centroidColor(1)))^2 + (colorsNum{j}(2) - double(STATS(i).centroidColor(2)))^2 + (colorsNum{j}(3) - double(STATS(i).centroidColor(3)))^2));
        if currDistance < STATS(i).lowestEuclideanDistance
            STATS(i).colorIndex = j;
            %The reference points needs to have an x value less than 200
            %and be white
            if (STATS(i).colorIndex == 3 && STATS(i).Centroid(1) <= 200)
                referecePoint = STATS(i).Centroid;
            end
            STATS(i).lowestEuclideanDistance = currDistance;
        end
        STATS(i).Color = colorsName{STATS(i).colorIndex};
        if STATS(i).Color == "White" && STATS(i).Centroid(1) > 200
            STATS(i).Color = "Grey";
        end
    end

    plot(STATS(i).Centroid(1),STATS(i).Centroid(2),'kO','MarkerFaceColor', 'k', 'MarkerSize', 3);
    text(STATS(i).Centroid(1) - 10,STATS(i).Centroid(2) + 25, "Circle", 'Color', colorsNum{1,STATS(i).colorIndex}/255);
    viscircles(STATS(i).Centroid, STATS(i).Radii,"Color", "k");
end

%Calculate the angle, distance, and arrow
for i = 1:items
    if (STATS(i).Centroid == referecePoint)
        STATS(i).DistanceAway = 0;
        STATS(i).Dot = 0;
        STATS(i).Det = 0;
        STATS(i).MotorAngle = 0;
    else
        slope =  (((topRight(2) - topLeft(2)) / (topRight(1) - topLeft(1))) *  ((bottomRight(2) - bottomLeft(2)) / (bottomRight(1) - bottomLeft(1)))) / 2;
        %relativePoint1 = [(bottomRight(2) - referecePoint(1)), bottomRight(2)/bottomLeft(2)];
        relativePoint1 = [(bottomRight(2) - referecePoint(1)), slope *(bottomRight(2) - referecePoint(1))];
        relativePoint2 = [-(referecePoint(1) - STATS(i).Centroid(1)), (referecePoint(2) - STATS(i).Centroid(2))];
        quiver(referecePoint(1), referecePoint(2), relativePoint1(1), relativePoint1(2), 0, "LineWidth", 2, "Color", 'k');
        quiver(referecePoint(1), referecePoint(2), relativePoint2(1), -(relativePoint2(2)), 0, "LineWidth", 2, "Color", colorsNum{1,STATS(i).colorIndex}/255);

        STATS(i).DistanceAway = sqrt((STATS(i).Centroid(1) - referecePoint(1))^2 + (STATS(i).Centroid(2) - referecePoint(2))^2);

        STATS(i).Dot = relativePoint1(1)*relativePoint2(1) + relativePoint1(2)*relativePoint2(2);
        STATS(i).Det = relativePoint1(1)*relativePoint2(2) - relativePoint1(2)*relativePoint2(1);
        motorAngle = atan2(STATS(i).Det, STATS(i).Dot);
        STATS(i).MotorAngle = round((motorAngle * 180 / pi), 2);
        text((referecePoint(1) + relativePoint2(1) + 20), (referecePoint(2) - relativePoint2(2)), "\theta = " + STATS(i).MotorAngle, 'Color', colorsNum{1,STATS(i).colorIndex}/255, 'FontSize', 12);
    end
    
end
hold off;

%%

% selectedButton.Text = "Grey";
for k = 1:items
    if strcmp(STATS(k).Color, selectedButton.Text) == 1
        club_angle = (STATS(k).MotorAngle);
        %club_angle = club_angle + abs(club_angle)/20;
        break
    else
        continue
    end
end

for k = 1:items
    if STATS(k).DistanceAway == 0
        y_position = STATS(k).Centroid(2);
        %Change
        y_degrees = -1 * (y_position - 109) * gantryDegreesPerPixel;
        if (club_angle) < -8
            y_degrees = y_degrees + (abs(club_angle)/30) * 500;
        elseif (club_angle) > 8
            y_degrees = y_degrees - (abs(club_angle)/30) * 500;
        end
        if y_degrees > 0
            y_degrees = 0;
        end
        if y_degrees < -2800
            y_degrees = -2800;
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
%degressPerSecond = 2800/3;
% pause((club_angle*degressPerSecond + .5))
pause(3)

set_param('MotorModel_Sp23_V21b/desiredPosition1', 'Value', num2str(club_angle));
pause(1)

set_param('MotorModel_Sp23_V21b/desiredPosition', 'Value', '-235');
pause(3)

set_param('MotorModel_Sp23_V21b/desiredPosition', 'Value', '0');
pause(1)
set_param('MotorModel_Sp23_V21b/desiredPosition1', 'Value', '0');
pause(1)
set_param('MotorModel_Sp23_V21b/desiredPosition2', 'Value', '0');



