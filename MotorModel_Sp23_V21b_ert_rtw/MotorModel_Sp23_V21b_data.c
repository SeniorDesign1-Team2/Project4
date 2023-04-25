/*
 * MotorModel_Sp23_V21b_data.c
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

/* Block parameters (default storage) */
P_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S41>/Derivative Gain'
   */
  0.03,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S89>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S137>/Derivative Gain'
   */
  0.03,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S44>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S92>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S140>/Integral Gain'
   */
  0.003,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S42>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S90>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S138>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_o
   * Referenced by: '<S47>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_h
   * Referenced by: '<S95>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_o
   * Referenced by: '<S143>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S50>/Filter Coefficient'
   */
  200.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S98>/Filter Coefficient'
   */
  200.0,

  /* Mask Parameter: PIDController2_N
   * Referenced by: '<S146>/Filter Coefficient'
   */
  200.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S52>/Proportional Gain'
   */
  0.9,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S100>/Proportional Gain'
   */
  0.8,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S148>/Proportional Gain'
   */
  0.9,

  /* Expression: 0.001
   * Referenced by: '<S1>/MATLAB System'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S2>/MATLAB System'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S3>/MATLAB System'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/desiredPosition'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S1>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S1>/Saturation'
   */
  -5.0,

  /* Expression: 77/3
   * Referenced by: '<S1>/Gain'
   */
  25.666666666666668,

  /* Expression: 0
   * Referenced by: '<Root>/desiredPosition1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S2>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/Saturation'
   */
  -5.0,

  /* Expression: 255/3
   * Referenced by: '<S2>/Gain'
   */
  85.0,

  /* Expression: 0
   * Referenced by: '<Root>/desiredPosition2'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S3>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Saturation'
   */
  -5.0,

  /* Expression: 255/3
   * Referenced by: '<S3>/Gain'
   */
  85.0,

  /* Computed Parameter: angular_positionrelative_countC
   * Referenced by: '<S1>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1236950581,

  /* Computed Parameter: angular_positionrelative_coun_f
   * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1105604738,

  /* Computed Parameter: angular_positionrelative_coun_c
   * Referenced by: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1308942414,

  /* Start of '<S3>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S13>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S13>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S3>/Constant Position' */

  /* Start of '<S3>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S14>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S14>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S3>/Motor Direction 2' */

  /* Start of '<S3>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S15>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S15>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S3>/Motor Direction1' */

  /* Start of '<S2>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S10>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S10>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Constant Position' */

  /* Start of '<S2>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S11>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S11>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S2>/Motor Direction 2' */

  /* Start of '<S2>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S12>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S12>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Motor Direction1' */

  /* Start of '<S1>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S7>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S7>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S1>/Constant Position' */

  /* Start of '<S1>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S8>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S8>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S1>/Motor Direction 2' */

  /* Start of '<S1>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S9>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S9>/Constant1'
     */
    0.0
  }
  /* End of '<S1>/Motor Direction1' */
};
