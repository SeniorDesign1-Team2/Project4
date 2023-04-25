/*
 * MotorModel_Sp23_V21b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorModel_Sp23_V21b".
 *
 * Model version              : 23
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 25 17:04:51 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorModel_Sp23_V21b.h"
#include "MotorModel_Sp23_V21b_private.h"

/* Block signals (default storage) */
B_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_B;

/* Continuous states */
X_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_X;

/* Block states (default storage) */
DW_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_DW;

/* Real-time model */
static RT_MODEL_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_M_;
RT_MODEL_MotorModel_Sp23_V21b_T *const MotorModel_Sp23_V21b_M =
  &MotorModel_Sp23_V21b_M_;
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  MotorModel_Sp23_V21b_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  MotorModel_Sp23_V21b_step();
  MotorModel_Sp23_V21b_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  MotorModel_Sp23_V21b_step();
  MotorModel_Sp23_V21b_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S1>/Motor Direction1'
 *    '<S1>/Motor Direction 2'
 *    '<S1>/Constant Position'
 *    '<S2>/Motor Direction1'
 *    '<S2>/Motor Direction 2'
 *    '<S2>/Constant Position'
 *    '<S3>/Motor Direction1'
 *    '<S3>/Motor Direction 2'
 *    '<S3>/Constant Position'
 */
void MotorModel_Sp23_MotorDirection1(RT_MODEL_MotorModel_Sp23_V21b_T * const
  MotorModel_Sp23_V21b_M, real_T *rty_IN1, real_T *rty_IN2,
  P_MotorDirection1_MotorModel__T *localP)
{
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* Constant: '<S9>/Constant' */
    *rty_IN1 = localP->Constant_Value;

    /* Constant: '<S9>/Constant1' */
    *rty_IN2 = localP->Constant1_Value;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void MotorModel_Sp23_V21b_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge1;
  real_T rtb_Merge2;
  real_T rtb_Merge1_a;
  real_T rtb_Merge2_b;
  codertarget_arduinobase_inter_T *obj;
  int64m_T *tmp_2;
  uint32_T tmp;
  uint32_T tmp_0;
  uint8_T tmp_1;
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* set solver stop time */
    if (!(MotorModel_Sp23_V21b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MotorModel_Sp23_V21b_M->solverInfo,
                            ((MotorModel_Sp23_V21b_M->Timing.clockTickH0 + 1) *
        MotorModel_Sp23_V21b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MotorModel_Sp23_V21b_M->solverInfo,
                            ((MotorModel_Sp23_V21b_M->Timing.clockTick0 + 1) *
        MotorModel_Sp23_V21b_M->Timing.stepSize0 +
        MotorModel_Sp23_V21b_M->Timing.clockTickH0 *
        MotorModel_Sp23_V21b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MotorModel_Sp23_V21b_M)) {
    MotorModel_Sp23_V21b_M->Timing.t[0] = rtsiGetT
      (&MotorModel_Sp23_V21b_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(MotorModel_Sp23_V21b_DW.MotorDirection1.MotorDirection1_SubsysRanBC);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* MATLABSystem: '<S1>/MATLAB System' */
    if (MotorModel_Sp23_V21b_DW.obj_m.SampleTime !=
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime) {
      MotorModel_Sp23_V21b_DW.obj_m.SampleTime =
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime;
    }

    /* MATLABSystem: '<S1>/MATLAB System' */
    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    MotorModel_Sp23_V21b_B.MATLABSystem_b = enc_output(0.0);

    /* Gain: '<S1>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    tmp = (uint32_T)MotorModel_Sp23_V21b_P.angular_positionrelative_countC;
    tmp_0 = (uint32_T)MotorModel_Sp23_V21b_B.MATLABSystem_b;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &MotorModel_Sp23_V21b_B.angular_positionrelative_coun_o.chunks[
                  0U], 2);

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/desiredPosition'
     *  Gain: '<S1>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
     *  Sum: '<Root>/Sum2'
     *  Sum: '<Root>/Sum3'
     */
    tmp_2 = &MotorModel_Sp23_V21b_B.angular_positionrelative_coun_o;
    MotorModel_Sp23_V21b_B.ErrorSignal =
      MotorModel_Sp23_V21b_P.desiredPosition_Value - sMultiWord2Double
      (&tmp_2->chunks[0U], 2, 0) * 1.1641532182693481E-10;

    /* Gain: '<S52>/Proportional Gain' */
    MotorModel_Sp23_V21b_B.ProportionalGain =
      MotorModel_Sp23_V21b_P.PIDController_P *
      MotorModel_Sp23_V21b_B.ErrorSignal;

    /* Gain: '<S41>/Derivative Gain' */
    MotorModel_Sp23_V21b_B.DerivativeGain =
      MotorModel_Sp23_V21b_P.PIDController_D *
      MotorModel_Sp23_V21b_B.ErrorSignal;
  }

  /* Gain: '<S50>/Filter Coefficient' incorporates:
   *  Integrator: '<S42>/Filter'
   *  Sum: '<S42>/SumD'
   */
  MotorModel_Sp23_V21b_B.FilterCoefficient =
    (MotorModel_Sp23_V21b_B.DerivativeGain -
     MotorModel_Sp23_V21b_X.Filter_CSTATE) *
    MotorModel_Sp23_V21b_P.PIDController_N;

  /* Sum: '<S56>/Sum' incorporates:
   *  Integrator: '<S47>/Integrator'
   */
  MotorModel_Sp23_V21b_B.Abs1 = (MotorModel_Sp23_V21b_B.ProportionalGain +
    MotorModel_Sp23_V21b_X.Integrator_CSTATE) +
    MotorModel_Sp23_V21b_B.FilterCoefficient;

  /* Abs: '<S1>/Abs1' */
  MotorModel_Sp23_V21b_B.Abs = fabs(MotorModel_Sp23_V21b_B.Abs1);

  /* Saturate: '<S1>/Saturation' */
  if (MotorModel_Sp23_V21b_B.Abs1 > MotorModel_Sp23_V21b_P.Saturation_UpperSat)
  {
    MotorModel_Sp23_V21b_B.Abs1 = MotorModel_Sp23_V21b_P.Saturation_UpperSat;
  } else if (MotorModel_Sp23_V21b_B.Abs1 <
             MotorModel_Sp23_V21b_P.Saturation_LowerSat) {
    MotorModel_Sp23_V21b_B.Abs1 = MotorModel_Sp23_V21b_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* If: '<S1>/Choose Direction' */
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    if ((MotorModel_Sp23_V21b_B.Abs1 > 0.0) && (MotorModel_Sp23_V21b_B.Abs > 3.0))
    {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsystem = 0;
    } else if ((MotorModel_Sp23_V21b_B.Abs1 < 0.0) &&
               (MotorModel_Sp23_V21b_B.Abs > 3.0)) {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsystem = 1;
    } else {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsystem = 2;
    }
  }

  switch (MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Motor Direction1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1,
      &rtb_Merge2, &MotorModel_Sp23_V21b_P.MotorDirection1);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection1.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/Motor Direction1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Motor Direction 2' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1,
      &rtb_Merge2, &MotorModel_Sp23_V21b_P.MotorDirection2);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection2.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/Motor Direction 2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Constant Position' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1,
      &rtb_Merge2, &MotorModel_Sp23_V21b_P.ConstantPosition);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.ConstantPosition.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S1>/Constant Position' */
    break;
  }

  /* End of If: '<S1>/Choose Direction' */

  /* MATLABSystem: '<S1>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_bm;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Gain: '<S1>/Gain' incorporates:
   *  Abs: '<S1>/Abs'
   */
  MotorModel_Sp23_V21b_B.Abs1 = MotorModel_Sp23_V21b_P.Gain_Gain * fabs
    (MotorModel_Sp23_V21b_B.Abs1);

  /* MATLABSystem: '<S1>/Enable' */
  if (!(MotorModel_Sp23_V21b_B.Abs1 <= 255.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 255.0;
  }

  if (!(MotorModel_Sp23_V21b_B.Abs1 >= 0.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 0.0;
  }

  MW_PWM_SetDutyCycle(MotorModel_Sp23_V21b_DW.obj_bm.PWMDriverObj.MW_PWM_HANDLE,
                      MotorModel_Sp23_V21b_B.Abs1);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* Gain: '<S44>/Integral Gain' */
    MotorModel_Sp23_V21b_B.IntegralGain = MotorModel_Sp23_V21b_P.PIDController_I
      * MotorModel_Sp23_V21b_B.ErrorSignal;

    /* MATLABSystem: '<S1>/Driver In1' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf(rtb_Merge1);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(30, tmp_1);

    /* End of MATLABSystem: '<S1>/Driver In1' */

    /* MATLABSystem: '<S1>/Driver In2' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf(rtb_Merge2);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(31, tmp_1);

    /* End of MATLABSystem: '<S1>/Driver In2' */

    /* MATLABSystem: '<S2>/MATLAB System' */
    if (MotorModel_Sp23_V21b_DW.obj_p.SampleTime !=
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_l) {
      MotorModel_Sp23_V21b_DW.obj_p.SampleTime =
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_l;
    }

    /* MATLABSystem: '<S2>/MATLAB System' */
    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    MotorModel_Sp23_V21b_B.MATLABSystem_d = enc_output(1.0);

    /* Gain: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    tmp = (uint32_T)MotorModel_Sp23_V21b_P.angular_positionrelative_coun_c;
    tmp_0 = (uint32_T)MotorModel_Sp23_V21b_B.MATLABSystem_d;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &MotorModel_Sp23_V21b_B.angular_positionrelative_countC.chunks[
                  0U], 2);

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/desiredPosition1'
     *  Gain: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<Root>/Sum3'
     */
    tmp_2 = &MotorModel_Sp23_V21b_B.angular_positionrelative_countC;
    MotorModel_Sp23_V21b_B.ErrorSignal =
      MotorModel_Sp23_V21b_P.desiredPosition1_Value - sMultiWord2Double
      (&tmp_2->chunks[0U], 2, 0) * 5.8207660913467407E-11;

    /* Gain: '<S100>/Proportional Gain' */
    MotorModel_Sp23_V21b_B.ProportionalGain_f =
      MotorModel_Sp23_V21b_P.PIDController1_P *
      MotorModel_Sp23_V21b_B.ErrorSignal;

    /* Gain: '<S89>/Derivative Gain' */
    MotorModel_Sp23_V21b_B.DerivativeGain_e =
      MotorModel_Sp23_V21b_P.PIDController1_D *
      MotorModel_Sp23_V21b_B.ErrorSignal;
  }

  /* Gain: '<S98>/Filter Coefficient' incorporates:
   *  Integrator: '<S90>/Filter'
   *  Sum: '<S90>/SumD'
   */
  MotorModel_Sp23_V21b_B.FilterCoefficient_g =
    (MotorModel_Sp23_V21b_B.DerivativeGain_e -
     MotorModel_Sp23_V21b_X.Filter_CSTATE_f) *
    MotorModel_Sp23_V21b_P.PIDController1_N;

  /* Sum: '<S104>/Sum' incorporates:
   *  Integrator: '<S95>/Integrator'
   */
  MotorModel_Sp23_V21b_B.Abs = (MotorModel_Sp23_V21b_B.ProportionalGain_f +
    MotorModel_Sp23_V21b_X.Integrator_CSTATE_g) +
    MotorModel_Sp23_V21b_B.FilterCoefficient_g;

  /* Abs: '<S2>/Abs1' */
  MotorModel_Sp23_V21b_B.Abs1 = fabs(MotorModel_Sp23_V21b_B.Abs);

  /* Saturate: '<S2>/Saturation' */
  if (MotorModel_Sp23_V21b_B.Abs > MotorModel_Sp23_V21b_P.Saturation_UpperSat_c)
  {
    MotorModel_Sp23_V21b_B.Abs = MotorModel_Sp23_V21b_P.Saturation_UpperSat_c;
  } else if (MotorModel_Sp23_V21b_B.Abs <
             MotorModel_Sp23_V21b_P.Saturation_LowerSat_a) {
    MotorModel_Sp23_V21b_B.Abs = MotorModel_Sp23_V21b_P.Saturation_LowerSat_a;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* If: '<S2>/Choose Direction' */
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    if ((MotorModel_Sp23_V21b_B.Abs > 0.0) && (MotorModel_Sp23_V21b_B.Abs1 > 3.0))
    {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_m = 0;
    } else if ((MotorModel_Sp23_V21b_B.Abs < 0.0) &&
               (MotorModel_Sp23_V21b_B.Abs1 > 3.0)) {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_m = 1;
    } else {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_m = 2;
    }
  }

  switch (MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_m) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Motor Direction1' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1_a,
      &rtb_Merge2_b, &MotorModel_Sp23_V21b_P.MotorDirection1_l);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection1_l.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S2>/Motor Direction1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Motor Direction 2' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1_a,
      &rtb_Merge2_b, &MotorModel_Sp23_V21b_P.MotorDirection2_a);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection2_a.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S2>/Motor Direction 2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/Constant Position' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M, &rtb_Merge1_a,
      &rtb_Merge2_b, &MotorModel_Sp23_V21b_P.ConstantPosition_f);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.ConstantPosition_f.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S2>/Constant Position' */
    break;
  }

  /* End of If: '<S2>/Choose Direction' */

  /* MATLABSystem: '<S2>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_lb;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Gain: '<S2>/Gain' incorporates:
   *  Abs: '<S2>/Abs'
   */
  MotorModel_Sp23_V21b_B.Abs1 = MotorModel_Sp23_V21b_P.Gain_Gain_c * fabs
    (MotorModel_Sp23_V21b_B.Abs);

  /* MATLABSystem: '<S2>/Enable' */
  if (!(MotorModel_Sp23_V21b_B.Abs1 <= 255.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 255.0;
  }

  if (!(MotorModel_Sp23_V21b_B.Abs1 >= 0.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 0.0;
  }

  MW_PWM_SetDutyCycle(MotorModel_Sp23_V21b_DW.obj_lb.PWMDriverObj.MW_PWM_HANDLE,
                      MotorModel_Sp23_V21b_B.Abs1);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* Gain: '<S92>/Integral Gain' */
    MotorModel_Sp23_V21b_B.IntegralGain_b =
      MotorModel_Sp23_V21b_P.PIDController1_I *
      MotorModel_Sp23_V21b_B.ErrorSignal;

    /* MATLABSystem: '<S2>/Driver In1' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf(rtb_Merge1_a);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(32, tmp_1);

    /* End of MATLABSystem: '<S2>/Driver In1' */

    /* MATLABSystem: '<S2>/Driver In2' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf(rtb_Merge2_b);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(33, tmp_1);

    /* End of MATLABSystem: '<S2>/Driver In2' */

    /* MATLABSystem: '<S3>/MATLAB System' */
    if (MotorModel_Sp23_V21b_DW.obj.SampleTime !=
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_p) {
      MotorModel_Sp23_V21b_DW.obj.SampleTime =
        MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_p;
    }

    /* MATLABSystem: '<S3>/MATLAB System' */
    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    MotorModel_Sp23_V21b_B.MATLABSystem = enc_output(2.0);

    /* Gain: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    tmp = (uint32_T)MotorModel_Sp23_V21b_P.angular_positionrelative_coun_f;
    tmp_0 = (uint32_T)MotorModel_Sp23_V21b_B.MATLABSystem;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &MotorModel_Sp23_V21b_B.angular_positionrelative_coun_j.chunks[
                  0U], 2);

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/desiredPosition2'
     *  Gain: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<Root>/Sum2'
     */
    tmp_2 = &MotorModel_Sp23_V21b_B.angular_positionrelative_coun_j;
    MotorModel_Sp23_V21b_B.ErrorSignal =
      MotorModel_Sp23_V21b_P.desiredPosition2_Value - sMultiWord2Double
      (&tmp_2->chunks[0U], 2, 0) * 1.1641532182693481E-10;

    /* Gain: '<S148>/Proportional Gain' */
    MotorModel_Sp23_V21b_B.ProportionalGain_c =
      MotorModel_Sp23_V21b_P.PIDController2_P *
      MotorModel_Sp23_V21b_B.ErrorSignal;

    /* Gain: '<S137>/Derivative Gain' */
    MotorModel_Sp23_V21b_B.DerivativeGain_n =
      MotorModel_Sp23_V21b_P.PIDController2_D *
      MotorModel_Sp23_V21b_B.ErrorSignal;
  }

  /* Gain: '<S146>/Filter Coefficient' incorporates:
   *  Integrator: '<S138>/Filter'
   *  Sum: '<S138>/SumD'
   */
  MotorModel_Sp23_V21b_B.FilterCoefficient_e =
    (MotorModel_Sp23_V21b_B.DerivativeGain_n -
     MotorModel_Sp23_V21b_X.Filter_CSTATE_c) *
    MotorModel_Sp23_V21b_P.PIDController2_N;

  /* Sum: '<S152>/Sum' incorporates:
   *  Integrator: '<S143>/Integrator'
   */
  MotorModel_Sp23_V21b_B.Abs = (MotorModel_Sp23_V21b_B.ProportionalGain_c +
    MotorModel_Sp23_V21b_X.Integrator_CSTATE_f) +
    MotorModel_Sp23_V21b_B.FilterCoefficient_e;

  /* Abs: '<S3>/Abs1' */
  MotorModel_Sp23_V21b_B.Abs1 = fabs(MotorModel_Sp23_V21b_B.Abs);

  /* Saturate: '<S3>/Saturation' */
  if (MotorModel_Sp23_V21b_B.Abs > MotorModel_Sp23_V21b_P.Saturation_UpperSat_m)
  {
    MotorModel_Sp23_V21b_B.Abs = MotorModel_Sp23_V21b_P.Saturation_UpperSat_m;
  } else if (MotorModel_Sp23_V21b_B.Abs <
             MotorModel_Sp23_V21b_P.Saturation_LowerSat_g) {
    MotorModel_Sp23_V21b_B.Abs = MotorModel_Sp23_V21b_P.Saturation_LowerSat_g;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* If: '<S3>/Choose Direction' */
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    if ((MotorModel_Sp23_V21b_B.Abs > 0.0) && (MotorModel_Sp23_V21b_B.Abs1 > 3.0))
    {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_p = 0;
    } else if ((MotorModel_Sp23_V21b_B.Abs < 0.0) &&
               (MotorModel_Sp23_V21b_B.Abs1 > 3.0)) {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_p = 1;
    } else {
      MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_p = 2;
    }
  }

  switch (MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_p) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S3>/Motor Direction1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M,
      &MotorModel_Sp23_V21b_B.Merge1_n, &MotorModel_Sp23_V21b_B.Merge2_m,
      &MotorModel_Sp23_V21b_P.MotorDirection1_i);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection1_i.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Motor Direction1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/Motor Direction 2' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M,
      &MotorModel_Sp23_V21b_B.Merge1_n, &MotorModel_Sp23_V21b_B.Merge2_m,
      &MotorModel_Sp23_V21b_P.MotorDirection2_h);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.MotorDirection2_h.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Motor Direction 2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/Constant Position' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    MotorModel_Sp23_MotorDirection1(MotorModel_Sp23_V21b_M,
      &MotorModel_Sp23_V21b_B.Merge1_n, &MotorModel_Sp23_V21b_B.Merge2_m,
      &MotorModel_Sp23_V21b_P.ConstantPosition_b);
    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
      srUpdateBC
        (MotorModel_Sp23_V21b_DW.ConstantPosition_b.MotorDirection1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S3>/Constant Position' */
    break;
  }

  /* End of If: '<S3>/Choose Direction' */

  /* MATLABSystem: '<S3>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_d;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Gain: '<S3>/Gain' incorporates:
   *  Abs: '<S3>/Abs'
   */
  MotorModel_Sp23_V21b_B.Abs1 = MotorModel_Sp23_V21b_P.Gain_Gain_h * fabs
    (MotorModel_Sp23_V21b_B.Abs);

  /* MATLABSystem: '<S3>/Enable' */
  if (!(MotorModel_Sp23_V21b_B.Abs1 <= 255.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 255.0;
  }

  if (!(MotorModel_Sp23_V21b_B.Abs1 >= 0.0)) {
    MotorModel_Sp23_V21b_B.Abs1 = 0.0;
  }

  MW_PWM_SetDutyCycle(MotorModel_Sp23_V21b_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                      MotorModel_Sp23_V21b_B.Abs1);
  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    /* Gain: '<S140>/Integral Gain' */
    MotorModel_Sp23_V21b_B.IntegralGain_h =
      MotorModel_Sp23_V21b_P.PIDController2_I *
      MotorModel_Sp23_V21b_B.ErrorSignal;

    /* MATLABSystem: '<S3>/Driver In1' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf
      (MotorModel_Sp23_V21b_B.Merge1_n);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(34, tmp_1);

    /* End of MATLABSystem: '<S3>/Driver In1' */

    /* MATLABSystem: '<S3>/Driver In2' */
    MotorModel_Sp23_V21b_B.ErrorSignal = rt_roundd_snf
      (MotorModel_Sp23_V21b_B.Merge2_m);
    if (MotorModel_Sp23_V21b_B.ErrorSignal < 256.0) {
      if (MotorModel_Sp23_V21b_B.ErrorSignal >= 0.0) {
        tmp_1 = (uint8_T)MotorModel_Sp23_V21b_B.ErrorSignal;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint8_T;
    }

    writeDigitalPin(35, tmp_1);

    /* End of MATLABSystem: '<S3>/Driver In2' */
  }

  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((MotorModel_Sp23_V21b_M->Timing.clockTick0+
           MotorModel_Sp23_V21b_M->Timing.clockTickH0* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((MotorModel_Sp23_V21b_M->Timing.clockTick1+
           MotorModel_Sp23_V21b_M->Timing.clockTickH1* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(MotorModel_Sp23_V21b_M)) {
    rt_ertODEUpdateContinuousStates(&MotorModel_Sp23_V21b_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++MotorModel_Sp23_V21b_M->Timing.clockTick0)) {
      ++MotorModel_Sp23_V21b_M->Timing.clockTickH0;
    }

    MotorModel_Sp23_V21b_M->Timing.t[0] = rtsiGetSolverStopTime
      (&MotorModel_Sp23_V21b_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      MotorModel_Sp23_V21b_M->Timing.clockTick1++;
      if (!MotorModel_Sp23_V21b_M->Timing.clockTick1) {
        MotorModel_Sp23_V21b_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void MotorModel_Sp23_V21b_derivatives(void)
{
  XDot_MotorModel_Sp23_V21b_T *_rtXdot;
  _rtXdot = ((XDot_MotorModel_Sp23_V21b_T *) MotorModel_Sp23_V21b_M->derivs);

  /* Derivatives for Integrator: '<S47>/Integrator' */
  _rtXdot->Integrator_CSTATE = MotorModel_Sp23_V21b_B.IntegralGain;

  /* Derivatives for Integrator: '<S42>/Filter' */
  _rtXdot->Filter_CSTATE = MotorModel_Sp23_V21b_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S95>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = MotorModel_Sp23_V21b_B.IntegralGain_b;

  /* Derivatives for Integrator: '<S90>/Filter' */
  _rtXdot->Filter_CSTATE_f = MotorModel_Sp23_V21b_B.FilterCoefficient_g;

  /* Derivatives for Integrator: '<S143>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = MotorModel_Sp23_V21b_B.IntegralGain_h;

  /* Derivatives for Integrator: '<S138>/Filter' */
  _rtXdot->Filter_CSTATE_c = MotorModel_Sp23_V21b_B.FilterCoefficient_e;
}

/* Model initialize function */
void MotorModel_Sp23_V21b_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MotorModel_Sp23_V21b_M, 0,
                sizeof(RT_MODEL_MotorModel_Sp23_V21b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MotorModel_Sp23_V21b_M->solverInfo,
                          &MotorModel_Sp23_V21b_M->Timing.simTimeStep);
    rtsiSetTPtr(&MotorModel_Sp23_V21b_M->solverInfo, &rtmGetTPtr
                (MotorModel_Sp23_V21b_M));
    rtsiSetStepSizePtr(&MotorModel_Sp23_V21b_M->solverInfo,
                       &MotorModel_Sp23_V21b_M->Timing.stepSize0);
    rtsiSetdXPtr(&MotorModel_Sp23_V21b_M->solverInfo,
                 &MotorModel_Sp23_V21b_M->derivs);
    rtsiSetContStatesPtr(&MotorModel_Sp23_V21b_M->solverInfo, (real_T **)
                         &MotorModel_Sp23_V21b_M->contStates);
    rtsiSetNumContStatesPtr(&MotorModel_Sp23_V21b_M->solverInfo,
      &MotorModel_Sp23_V21b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MotorModel_Sp23_V21b_M->solverInfo,
      &MotorModel_Sp23_V21b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&MotorModel_Sp23_V21b_M->solverInfo,
      &MotorModel_Sp23_V21b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MotorModel_Sp23_V21b_M->solverInfo,
      &MotorModel_Sp23_V21b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MotorModel_Sp23_V21b_M->solverInfo,
                          (&rtmGetErrorStatus(MotorModel_Sp23_V21b_M)));
    rtsiSetRTModelPtr(&MotorModel_Sp23_V21b_M->solverInfo,
                      MotorModel_Sp23_V21b_M);
  }

  rtsiSetSimTimeStep(&MotorModel_Sp23_V21b_M->solverInfo, MAJOR_TIME_STEP);
  MotorModel_Sp23_V21b_M->intgData.y = MotorModel_Sp23_V21b_M->odeY;
  MotorModel_Sp23_V21b_M->intgData.f[0] = MotorModel_Sp23_V21b_M->odeF[0];
  MotorModel_Sp23_V21b_M->intgData.f[1] = MotorModel_Sp23_V21b_M->odeF[1];
  MotorModel_Sp23_V21b_M->intgData.f[2] = MotorModel_Sp23_V21b_M->odeF[2];
  MotorModel_Sp23_V21b_M->contStates = ((X_MotorModel_Sp23_V21b_T *)
    &MotorModel_Sp23_V21b_X);
  rtsiSetSolverData(&MotorModel_Sp23_V21b_M->solverInfo, (void *)
                    &MotorModel_Sp23_V21b_M->intgData);
  rtsiSetSolverName(&MotorModel_Sp23_V21b_M->solverInfo,"ode3");
  rtmSetTPtr(MotorModel_Sp23_V21b_M, &MotorModel_Sp23_V21b_M->Timing.tArray[0]);
  rtmSetTFinal(MotorModel_Sp23_V21b_M, -1);
  MotorModel_Sp23_V21b_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  MotorModel_Sp23_V21b_M->Sizes.checksums[0] = (794067058U);
  MotorModel_Sp23_V21b_M->Sizes.checksums[1] = (3339076395U);
  MotorModel_Sp23_V21b_M->Sizes.checksums[2] = (2459761153U);
  MotorModel_Sp23_V21b_M->Sizes.checksums[3] = (2076132985U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    MotorModel_Sp23_V21b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.ConstantPosition.MotorDirection1_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection2.MotorDirection1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection1.MotorDirection1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.ConstantPosition_f.MotorDirection1_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection2_a.MotorDirection1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection1_l.MotorDirection1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.ConstantPosition_b.MotorDirection1_SubsysRanBC;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection2_h.MotorDirection1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &MotorModel_Sp23_V21b_DW.MotorDirection1_i.MotorDirection1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(MotorModel_Sp23_V21b_M->extModeInfo,
      &MotorModel_Sp23_V21b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MotorModel_Sp23_V21b_M->extModeInfo,
                        MotorModel_Sp23_V21b_M->Sizes.checksums);
    rteiSetTPtr(MotorModel_Sp23_V21b_M->extModeInfo, rtmGetTPtr
                (MotorModel_Sp23_V21b_M));
  }

  /* block I/O */
  (void) memset(((void *) &MotorModel_Sp23_V21b_B), 0,
                sizeof(B_MotorModel_Sp23_V21b_T));

  /* states (continuous) */
  {
    (void) memset((void *)&MotorModel_Sp23_V21b_X, 0,
                  sizeof(X_MotorModel_Sp23_V21b_T));
  }

  /* states (dwork) */
  (void) memset((void *)&MotorModel_Sp23_V21b_DW, 0,
                sizeof(DW_MotorModel_Sp23_V21b_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<S1>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    MotorModel_Sp23_V21b_DW.obj_m.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_p = true;

    /*  Do not generate code for sprintf */
    MotorModel_Sp23_V21b_DW.obj_m.SampleTime =
      MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime;
    MotorModel_Sp23_V21b_DW.obj_m.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(0.0, 2.0, 3.0);
    MotorModel_Sp23_V21b_DW.obj_m.isSetupComplete = true;

    /* Start for If: '<S1>/Choose Direction' */
    MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<S1>/Enable' */
    MotorModel_Sp23_V21b_DW.obj_bm.matlabCodegenIsDeleted = true;
    MotorModel_Sp23_V21b_DW.obj_bm.isInitialized = 0L;
    MotorModel_Sp23_V21b_DW.obj_bm.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_k = true;
    obj = &MotorModel_Sp23_V21b_DW.obj_bm;
    MotorModel_Sp23_V21b_DW.obj_bm.isSetupComplete = false;
    MotorModel_Sp23_V21b_DW.obj_bm.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    MotorModel_Sp23_V21b_DW.obj_bm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Driver In1' */
    MotorModel_Sp23_V21b_DW.obj_l.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_b = true;
    MotorModel_Sp23_V21b_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(30, 1);
    MotorModel_Sp23_V21b_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Driver In2' */
    MotorModel_Sp23_V21b_DW.obj_f.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_e = true;
    MotorModel_Sp23_V21b_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(31, 1);
    MotorModel_Sp23_V21b_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    MotorModel_Sp23_V21b_DW.obj_p.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_m = true;

    /*  Do not generate code for sprintf */
    MotorModel_Sp23_V21b_DW.obj_p.SampleTime =
      MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_l;
    MotorModel_Sp23_V21b_DW.obj_p.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(1.0, 18.0, 19.0);
    MotorModel_Sp23_V21b_DW.obj_p.isSetupComplete = true;

    /* Start for If: '<S2>/Choose Direction' */
    MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_m = -1;

    /* Start for MATLABSystem: '<S2>/Enable' */
    MotorModel_Sp23_V21b_DW.obj_lb.matlabCodegenIsDeleted = true;
    MotorModel_Sp23_V21b_DW.obj_lb.isInitialized = 0L;
    MotorModel_Sp23_V21b_DW.obj_lb.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_d = true;
    obj = &MotorModel_Sp23_V21b_DW.obj_lb;
    MotorModel_Sp23_V21b_DW.obj_lb.isSetupComplete = false;
    MotorModel_Sp23_V21b_DW.obj_lb.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
    MotorModel_Sp23_V21b_DW.obj_lb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Driver In1' */
    MotorModel_Sp23_V21b_DW.obj_b.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_g = true;
    MotorModel_Sp23_V21b_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(32, 1);
    MotorModel_Sp23_V21b_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Driver In2' */
    MotorModel_Sp23_V21b_DW.obj_pb.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_mb = true;
    MotorModel_Sp23_V21b_DW.obj_pb.isInitialized = 1L;
    digitalIOSetup(33, 1);
    MotorModel_Sp23_V21b_DW.obj_pb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    MotorModel_Sp23_V21b_DW.obj.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty = true;

    /*  Do not generate code for sprintf */
    MotorModel_Sp23_V21b_DW.obj.SampleTime =
      MotorModel_Sp23_V21b_P.MATLABSystem_SampleTime_p;
    MotorModel_Sp23_V21b_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(2.0, 20.0, 21.0);
    MotorModel_Sp23_V21b_DW.obj.isSetupComplete = true;

    /* Start for If: '<S3>/Choose Direction' */
    MotorModel_Sp23_V21b_DW.ChooseDirection_ActiveSubsyst_p = -1;

    /* Start for MATLABSystem: '<S3>/Enable' */
    MotorModel_Sp23_V21b_DW.obj_d.matlabCodegenIsDeleted = true;
    MotorModel_Sp23_V21b_DW.obj_d.isInitialized = 0L;
    MotorModel_Sp23_V21b_DW.obj_d.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_j = true;
    obj = &MotorModel_Sp23_V21b_DW.obj_d;
    MotorModel_Sp23_V21b_DW.obj_d.isSetupComplete = false;
    MotorModel_Sp23_V21b_DW.obj_d.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    MotorModel_Sp23_V21b_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Driver In1' */
    MotorModel_Sp23_V21b_DW.obj_a.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_n = true;
    MotorModel_Sp23_V21b_DW.obj_a.isInitialized = 1L;
    digitalIOSetup(34, 1);
    MotorModel_Sp23_V21b_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Driver In2' */
    MotorModel_Sp23_V21b_DW.obj_h.matlabCodegenIsDeleted = false;
    MotorModel_Sp23_V21b_DW.objisempty_h = true;
    MotorModel_Sp23_V21b_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(35, 1);
    MotorModel_Sp23_V21b_DW.obj_h.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<S47>/Integrator' */
  MotorModel_Sp23_V21b_X.Integrator_CSTATE =
    MotorModel_Sp23_V21b_P.PIDController_InitialConditio_o;

  /* InitializeConditions for Integrator: '<S42>/Filter' */
  MotorModel_Sp23_V21b_X.Filter_CSTATE =
    MotorModel_Sp23_V21b_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S95>/Integrator' */
  MotorModel_Sp23_V21b_X.Integrator_CSTATE_g =
    MotorModel_Sp23_V21b_P.PIDController1_InitialConditi_h;

  /* InitializeConditions for Integrator: '<S90>/Filter' */
  MotorModel_Sp23_V21b_X.Filter_CSTATE_f =
    MotorModel_Sp23_V21b_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S143>/Integrator' */
  MotorModel_Sp23_V21b_X.Integrator_CSTATE_f =
    MotorModel_Sp23_V21b_P.PIDController2_InitialConditi_o;

  /* InitializeConditions for Integrator: '<S138>/Filter' */
  MotorModel_Sp23_V21b_X.Filter_CSTATE_c =
    MotorModel_Sp23_V21b_P.PIDController2_InitialCondition;
}

/* Model terminate function */
void MotorModel_Sp23_V21b_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/MATLAB System' */
  if (!MotorModel_Sp23_V21b_DW.obj_m.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S1>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_bm;
  if (!MotorModel_Sp23_V21b_DW.obj_bm.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_bm.matlabCodegenIsDeleted = true;
    if ((MotorModel_Sp23_V21b_DW.obj_bm.isInitialized == 1L) &&
        MotorModel_Sp23_V21b_DW.obj_bm.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (MotorModel_Sp23_V21b_DW.obj_bm.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(MotorModel_Sp23_V21b_DW.obj_bm.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Enable' */
  /* Terminate for MATLABSystem: '<S1>/Driver In1' */
  if (!MotorModel_Sp23_V21b_DW.obj_l.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Driver In1' */

  /* Terminate for MATLABSystem: '<S1>/Driver In2' */
  if (!MotorModel_Sp23_V21b_DW.obj_f.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Driver In2' */

  /* Terminate for MATLABSystem: '<S2>/MATLAB System' */
  if (!MotorModel_Sp23_V21b_DW.obj_p.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S2>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_lb;
  if (!MotorModel_Sp23_V21b_DW.obj_lb.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_lb.matlabCodegenIsDeleted = true;
    if ((MotorModel_Sp23_V21b_DW.obj_lb.isInitialized == 1L) &&
        MotorModel_Sp23_V21b_DW.obj_lb.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (MotorModel_Sp23_V21b_DW.obj_lb.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(MotorModel_Sp23_V21b_DW.obj_lb.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Enable' */
  /* Terminate for MATLABSystem: '<S2>/Driver In1' */
  if (!MotorModel_Sp23_V21b_DW.obj_b.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Driver In1' */

  /* Terminate for MATLABSystem: '<S2>/Driver In2' */
  if (!MotorModel_Sp23_V21b_DW.obj_pb.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_pb.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Driver In2' */

  /* Terminate for MATLABSystem: '<S3>/MATLAB System' */
  if (!MotorModel_Sp23_V21b_DW.obj.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S3>/Enable' */
  obj = &MotorModel_Sp23_V21b_DW.obj_d;
  if (!MotorModel_Sp23_V21b_DW.obj_d.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((MotorModel_Sp23_V21b_DW.obj_d.isInitialized == 1L) &&
        MotorModel_Sp23_V21b_DW.obj_d.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (MotorModel_Sp23_V21b_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(MotorModel_Sp23_V21b_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Enable' */
  /* Terminate for MATLABSystem: '<S3>/Driver In1' */
  if (!MotorModel_Sp23_V21b_DW.obj_a.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Driver In1' */

  /* Terminate for MATLABSystem: '<S3>/Driver In2' */
  if (!MotorModel_Sp23_V21b_DW.obj_h.matlabCodegenIsDeleted) {
    MotorModel_Sp23_V21b_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Driver In2' */
}
