/*
 * MotorModel_Sp23_V21b.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorModel_Sp23_V21b".
 *
 * Model version              : 21
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Apr 23 18:14:43 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorModel_Sp23_V21b_h_
#define RTW_HEADER_MotorModel_Sp23_V21b_h_
#include <math.h>
#include <string.h>
#ifndef MotorModel_Sp23_V21b_COMMON_INCLUDES_
#define MotorModel_Sp23_V21b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif                               /* MotorModel_Sp23_V21b_COMMON_INCLUDES_ */

#include "MotorModel_Sp23_V21b_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S1>/Motor Direction1' */
typedef struct {
  int8_T MotorDirection1_SubsysRanBC;  /* '<S1>/Motor Direction1' */
} DW_MotorDirection1_MotorModel_T;

/* Block signals (default storage) */
typedef struct {
  real_T IntegralGain;                 /* '<S44>/Integral Gain' */
  real_T ProportionalGain_f;           /* '<S100>/Proportional Gain' */
  real_T DerivativeGain_e;             /* '<S89>/Derivative Gain' */
  real_T FilterCoefficient_g;          /* '<S98>/Filter Coefficient' */
  real_T IntegralGain_b;               /* '<S92>/Integral Gain' */
  real_T ProportionalGain_c;           /* '<S148>/Proportional Gain' */
  real_T DerivativeGain_n;             /* '<S137>/Derivative Gain' */
  real_T FilterCoefficient_e;          /* '<S146>/Filter Coefficient' */
  real_T IntegralGain_h;               /* '<S140>/Integral Gain' */
  real_T Abs1;                         /* '<S3>/Abs1' */
  real_T ErrorSignal;                  /* '<Root>/Sum3' */
  real_T Abs;                          /* '<S3>/Abs' */
  real_T Merge2_m;                     /* '<S3>/Merge2' */
  real_T Merge1_n;                     /* '<S3>/Merge1' */
  int64m_T angular_positionrelative_countC;
  /* '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  int64m_T angular_positionrelative_coun_o;
  /* '<S1>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  int64m_T angular_positionrelative_coun_j;
  /* '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
  real_T ProportionalGain;             /* '<S52>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S41>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S50>/Filter Coefficient' */
  int32_T MATLABSystem;                /* '<S3>/MATLAB System' */
  int32_T MATLABSystem_d;              /* '<S2>/MATLAB System' */
  int32_T MATLABSystem_b;              /* '<S1>/MATLAB System' */
} B_MotorModel_Sp23_V21b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_MotorModel_Sp_T obj; /* '<S3>/MATLAB System' */
  Encoder_arduino_MotorModel_Sp_T obj_p;/* '<S2>/MATLAB System' */
  Encoder_arduino_MotorModel_Sp_T obj_m;/* '<S1>/MATLAB System' */
  codertarget_arduinobase_block_T obj_h;/* '<S3>/Driver In2' */
  codertarget_arduinobase_block_T obj_a;/* '<S3>/Driver In1' */
  codertarget_arduinobase_block_T obj_pb;/* '<S2>/Driver In2' */
  codertarget_arduinobase_block_T obj_b;/* '<S2>/Driver In1' */
  codertarget_arduinobase_block_T obj_f;/* '<S1>/Driver In2' */
  codertarget_arduinobase_block_T obj_l;/* '<S1>/Driver In1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S3>/Enable' */
  codertarget_arduinobase_inter_T obj_lb;/* '<S2>/Enable' */
  codertarget_arduinobase_inter_T obj_bm;/* '<S1>/Enable' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Motor;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MATLA;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mot_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MAT_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mot_k;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_MA_og;   /* synthesized block */

  int8_T ChooseDirection_ActiveSubsystem;/* '<S1>/Choose Direction' */
  int8_T ChooseDirection_ActiveSubsyst_m;/* '<S2>/Choose Direction' */
  int8_T ChooseDirection_ActiveSubsyst_p;/* '<S3>/Choose Direction' */
  boolean_T objisempty;                /* '<S3>/MATLAB System' */
  boolean_T objisempty_j;              /* '<S3>/Enable' */
  boolean_T objisempty_h;              /* '<S3>/Driver In2' */
  boolean_T objisempty_n;              /* '<S3>/Driver In1' */
  boolean_T objisempty_m;              /* '<S2>/MATLAB System' */
  boolean_T objisempty_d;              /* '<S2>/Enable' */
  boolean_T objisempty_mb;             /* '<S2>/Driver In2' */
  boolean_T objisempty_g;              /* '<S2>/Driver In1' */
  boolean_T objisempty_p;              /* '<S1>/MATLAB System' */
  boolean_T objisempty_k;              /* '<S1>/Enable' */
  boolean_T objisempty_e;              /* '<S1>/Driver In2' */
  boolean_T objisempty_b;              /* '<S1>/Driver In1' */
  DW_MotorDirection1_MotorModel_T ConstantPosition_b;/* '<S3>/Constant Position' */
  DW_MotorDirection1_MotorModel_T MotorDirection2_h;/* '<S3>/Motor Direction 2' */
  DW_MotorDirection1_MotorModel_T MotorDirection1_i;/* '<S3>/Motor Direction1' */
  DW_MotorDirection1_MotorModel_T ConstantPosition_f;/* '<S2>/Constant Position' */
  DW_MotorDirection1_MotorModel_T MotorDirection2_a;/* '<S2>/Motor Direction 2' */
  DW_MotorDirection1_MotorModel_T MotorDirection1_l;/* '<S2>/Motor Direction1' */
  DW_MotorDirection1_MotorModel_T ConstantPosition;/* '<S1>/Constant Position' */
  DW_MotorDirection1_MotorModel_T MotorDirection2;/* '<S1>/Motor Direction 2' */
  DW_MotorDirection1_MotorModel_T MotorDirection1;/* '<S1>/Motor Direction1' */
} DW_MotorModel_Sp23_V21b_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S47>/Integrator' */
  real_T Filter_CSTATE;                /* '<S42>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S95>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S90>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S143>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S138>/Filter' */
} X_MotorModel_Sp23_V21b_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S47>/Integrator' */
  real_T Filter_CSTATE;                /* '<S42>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S95>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S90>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S143>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S138>/Filter' */
} XDot_MotorModel_Sp23_V21b_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S47>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S42>/Filter' */
  boolean_T Integrator_CSTATE_g;       /* '<S95>/Integrator' */
  boolean_T Filter_CSTATE_f;           /* '<S90>/Filter' */
  boolean_T Integrator_CSTATE_f;       /* '<S143>/Integrator' */
  boolean_T Filter_CSTATE_c;           /* '<S138>/Filter' */
} XDis_MotorModel_Sp23_V21b_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S1>/Motor Direction1' */
struct P_MotorDirection1_MotorModel__T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_MotorModel_Sp23_V21b_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S41>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S89>/Derivative Gain'
                                        */
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S137>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S44>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S92>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S140>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S42>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S90>/Filter'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S138>/Filter'
                               */
  real_T PIDController_InitialConditio_o;
                              /* Mask Parameter: PIDController_InitialConditio_o
                               * Referenced by: '<S47>/Integrator'
                               */
  real_T PIDController1_InitialConditi_h;
                              /* Mask Parameter: PIDController1_InitialConditi_h
                               * Referenced by: '<S95>/Integrator'
                               */
  real_T PIDController2_InitialConditi_o;
                              /* Mask Parameter: PIDController2_InitialConditi_o
                               * Referenced by: '<S143>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S50>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S98>/Filter Coefficient'
                                        */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S146>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S52>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S100>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S148>/Proportional Gain'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<S1>/MATLAB System'
                                        */
  real_T MATLABSystem_SampleTime_l;    /* Expression: 0.001
                                        * Referenced by: '<S2>/MATLAB System'
                                        */
  real_T MATLABSystem_SampleTime_p;    /* Expression: 0.001
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T desiredPosition_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/desiredPosition'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 77/3
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T desiredPosition1_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/desiredPosition1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 255/3
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T desiredPosition2_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/desiredPosition2'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 255/3
                                        * Referenced by: '<S3>/Gain'
                                        */
  int32_T angular_positionrelative_countC;
                          /* Computed Parameter: angular_positionrelative_countC
                           * Referenced by: '<S1>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  int32_T angular_positionrelative_coun_f;
                          /* Computed Parameter: angular_positionrelative_coun_f
                           * Referenced by: '<S3>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  int32_T angular_positionrelative_coun_c;
                          /* Computed Parameter: angular_positionrelative_coun_c
                           * Referenced by: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  P_MotorDirection1_MotorModel__T ConstantPosition_b;/* '<S3>/Constant Position' */
  P_MotorDirection1_MotorModel__T MotorDirection2_h;/* '<S3>/Motor Direction 2' */
  P_MotorDirection1_MotorModel__T MotorDirection1_i;/* '<S3>/Motor Direction1' */
  P_MotorDirection1_MotorModel__T ConstantPosition_f;/* '<S2>/Constant Position' */
  P_MotorDirection1_MotorModel__T MotorDirection2_a;/* '<S2>/Motor Direction 2' */
  P_MotorDirection1_MotorModel__T MotorDirection1_l;/* '<S2>/Motor Direction1' */
  P_MotorDirection1_MotorModel__T ConstantPosition;/* '<S1>/Constant Position' */
  P_MotorDirection1_MotorModel__T MotorDirection2;/* '<S1>/Motor Direction 2' */
  P_MotorDirection1_MotorModel__T MotorDirection1;/* '<S1>/Motor Direction1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorModel_Sp23_V21b_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_MotorModel_Sp23_V21b_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_P;

/* Block signals (default storage) */
extern B_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_B;

/* Continuous states (default storage) */
extern X_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_X;

/* Block states (default storage) */
extern DW_MotorModel_Sp23_V21b_T MotorModel_Sp23_V21b_DW;

/* Model entry point functions */
extern void MotorModel_Sp23_V21b_initialize(void);
extern void MotorModel_Sp23_V21b_step(void);
extern void MotorModel_Sp23_V21b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorModel_Sp23_V21b_T *const MotorModel_Sp23_V21b_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MotorModel_Sp23_V21b'
 * '<S1>'   : 'MotorModel_Sp23_V21b/Motor'
 * '<S2>'   : 'MotorModel_Sp23_V21b/Motor1'
 * '<S3>'   : 'MotorModel_Sp23_V21b/Motor2'
 * '<S4>'   : 'MotorModel_Sp23_V21b/PID Controller'
 * '<S5>'   : 'MotorModel_Sp23_V21b/PID Controller1'
 * '<S6>'   : 'MotorModel_Sp23_V21b/PID Controller2'
 * '<S7>'   : 'MotorModel_Sp23_V21b/Motor/Constant Position'
 * '<S8>'   : 'MotorModel_Sp23_V21b/Motor/Motor Direction 2'
 * '<S9>'   : 'MotorModel_Sp23_V21b/Motor/Motor Direction1'
 * '<S10>'  : 'MotorModel_Sp23_V21b/Motor1/Constant Position'
 * '<S11>'  : 'MotorModel_Sp23_V21b/Motor1/Motor Direction 2'
 * '<S12>'  : 'MotorModel_Sp23_V21b/Motor1/Motor Direction1'
 * '<S13>'  : 'MotorModel_Sp23_V21b/Motor2/Constant Position'
 * '<S14>'  : 'MotorModel_Sp23_V21b/Motor2/Motor Direction 2'
 * '<S15>'  : 'MotorModel_Sp23_V21b/Motor2/Motor Direction1'
 * '<S16>'  : 'MotorModel_Sp23_V21b/PID Controller/Anti-windup'
 * '<S17>'  : 'MotorModel_Sp23_V21b/PID Controller/D Gain'
 * '<S18>'  : 'MotorModel_Sp23_V21b/PID Controller/Filter'
 * '<S19>'  : 'MotorModel_Sp23_V21b/PID Controller/Filter ICs'
 * '<S20>'  : 'MotorModel_Sp23_V21b/PID Controller/I Gain'
 * '<S21>'  : 'MotorModel_Sp23_V21b/PID Controller/Ideal P Gain'
 * '<S22>'  : 'MotorModel_Sp23_V21b/PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'MotorModel_Sp23_V21b/PID Controller/Integrator'
 * '<S24>'  : 'MotorModel_Sp23_V21b/PID Controller/Integrator ICs'
 * '<S25>'  : 'MotorModel_Sp23_V21b/PID Controller/N Copy'
 * '<S26>'  : 'MotorModel_Sp23_V21b/PID Controller/N Gain'
 * '<S27>'  : 'MotorModel_Sp23_V21b/PID Controller/P Copy'
 * '<S28>'  : 'MotorModel_Sp23_V21b/PID Controller/Parallel P Gain'
 * '<S29>'  : 'MotorModel_Sp23_V21b/PID Controller/Reset Signal'
 * '<S30>'  : 'MotorModel_Sp23_V21b/PID Controller/Saturation'
 * '<S31>'  : 'MotorModel_Sp23_V21b/PID Controller/Saturation Fdbk'
 * '<S32>'  : 'MotorModel_Sp23_V21b/PID Controller/Sum'
 * '<S33>'  : 'MotorModel_Sp23_V21b/PID Controller/Sum Fdbk'
 * '<S34>'  : 'MotorModel_Sp23_V21b/PID Controller/Tracking Mode'
 * '<S35>'  : 'MotorModel_Sp23_V21b/PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'MotorModel_Sp23_V21b/PID Controller/Tsamp - Integral'
 * '<S37>'  : 'MotorModel_Sp23_V21b/PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'MotorModel_Sp23_V21b/PID Controller/postSat Signal'
 * '<S39>'  : 'MotorModel_Sp23_V21b/PID Controller/preSat Signal'
 * '<S40>'  : 'MotorModel_Sp23_V21b/PID Controller/Anti-windup/Passthrough'
 * '<S41>'  : 'MotorModel_Sp23_V21b/PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'MotorModel_Sp23_V21b/PID Controller/Filter/Cont. Filter'
 * '<S43>'  : 'MotorModel_Sp23_V21b/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S44>'  : 'MotorModel_Sp23_V21b/PID Controller/I Gain/Internal Parameters'
 * '<S45>'  : 'MotorModel_Sp23_V21b/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'MotorModel_Sp23_V21b/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'MotorModel_Sp23_V21b/PID Controller/Integrator/Continuous'
 * '<S48>'  : 'MotorModel_Sp23_V21b/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'MotorModel_Sp23_V21b/PID Controller/N Copy/Disabled'
 * '<S50>'  : 'MotorModel_Sp23_V21b/PID Controller/N Gain/Internal Parameters'
 * '<S51>'  : 'MotorModel_Sp23_V21b/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'MotorModel_Sp23_V21b/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'MotorModel_Sp23_V21b/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'MotorModel_Sp23_V21b/PID Controller/Saturation/Passthrough'
 * '<S55>'  : 'MotorModel_Sp23_V21b/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'MotorModel_Sp23_V21b/PID Controller/Sum/Sum_PID'
 * '<S57>'  : 'MotorModel_Sp23_V21b/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'MotorModel_Sp23_V21b/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'MotorModel_Sp23_V21b/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'MotorModel_Sp23_V21b/PID Controller/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'MotorModel_Sp23_V21b/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'MotorModel_Sp23_V21b/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'MotorModel_Sp23_V21b/PID Controller/preSat Signal/Forward_Path'
 * '<S64>'  : 'MotorModel_Sp23_V21b/PID Controller1/Anti-windup'
 * '<S65>'  : 'MotorModel_Sp23_V21b/PID Controller1/D Gain'
 * '<S66>'  : 'MotorModel_Sp23_V21b/PID Controller1/Filter'
 * '<S67>'  : 'MotorModel_Sp23_V21b/PID Controller1/Filter ICs'
 * '<S68>'  : 'MotorModel_Sp23_V21b/PID Controller1/I Gain'
 * '<S69>'  : 'MotorModel_Sp23_V21b/PID Controller1/Ideal P Gain'
 * '<S70>'  : 'MotorModel_Sp23_V21b/PID Controller1/Ideal P Gain Fdbk'
 * '<S71>'  : 'MotorModel_Sp23_V21b/PID Controller1/Integrator'
 * '<S72>'  : 'MotorModel_Sp23_V21b/PID Controller1/Integrator ICs'
 * '<S73>'  : 'MotorModel_Sp23_V21b/PID Controller1/N Copy'
 * '<S74>'  : 'MotorModel_Sp23_V21b/PID Controller1/N Gain'
 * '<S75>'  : 'MotorModel_Sp23_V21b/PID Controller1/P Copy'
 * '<S76>'  : 'MotorModel_Sp23_V21b/PID Controller1/Parallel P Gain'
 * '<S77>'  : 'MotorModel_Sp23_V21b/PID Controller1/Reset Signal'
 * '<S78>'  : 'MotorModel_Sp23_V21b/PID Controller1/Saturation'
 * '<S79>'  : 'MotorModel_Sp23_V21b/PID Controller1/Saturation Fdbk'
 * '<S80>'  : 'MotorModel_Sp23_V21b/PID Controller1/Sum'
 * '<S81>'  : 'MotorModel_Sp23_V21b/PID Controller1/Sum Fdbk'
 * '<S82>'  : 'MotorModel_Sp23_V21b/PID Controller1/Tracking Mode'
 * '<S83>'  : 'MotorModel_Sp23_V21b/PID Controller1/Tracking Mode Sum'
 * '<S84>'  : 'MotorModel_Sp23_V21b/PID Controller1/Tsamp - Integral'
 * '<S85>'  : 'MotorModel_Sp23_V21b/PID Controller1/Tsamp - Ngain'
 * '<S86>'  : 'MotorModel_Sp23_V21b/PID Controller1/postSat Signal'
 * '<S87>'  : 'MotorModel_Sp23_V21b/PID Controller1/preSat Signal'
 * '<S88>'  : 'MotorModel_Sp23_V21b/PID Controller1/Anti-windup/Passthrough'
 * '<S89>'  : 'MotorModel_Sp23_V21b/PID Controller1/D Gain/Internal Parameters'
 * '<S90>'  : 'MotorModel_Sp23_V21b/PID Controller1/Filter/Cont. Filter'
 * '<S91>'  : 'MotorModel_Sp23_V21b/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'MotorModel_Sp23_V21b/PID Controller1/I Gain/Internal Parameters'
 * '<S93>'  : 'MotorModel_Sp23_V21b/PID Controller1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'MotorModel_Sp23_V21b/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'MotorModel_Sp23_V21b/PID Controller1/Integrator/Continuous'
 * '<S96>'  : 'MotorModel_Sp23_V21b/PID Controller1/Integrator ICs/Internal IC'
 * '<S97>'  : 'MotorModel_Sp23_V21b/PID Controller1/N Copy/Disabled'
 * '<S98>'  : 'MotorModel_Sp23_V21b/PID Controller1/N Gain/Internal Parameters'
 * '<S99>'  : 'MotorModel_Sp23_V21b/PID Controller1/P Copy/Disabled'
 * '<S100>' : 'MotorModel_Sp23_V21b/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'MotorModel_Sp23_V21b/PID Controller1/Reset Signal/Disabled'
 * '<S102>' : 'MotorModel_Sp23_V21b/PID Controller1/Saturation/Passthrough'
 * '<S103>' : 'MotorModel_Sp23_V21b/PID Controller1/Saturation Fdbk/Disabled'
 * '<S104>' : 'MotorModel_Sp23_V21b/PID Controller1/Sum/Sum_PID'
 * '<S105>' : 'MotorModel_Sp23_V21b/PID Controller1/Sum Fdbk/Disabled'
 * '<S106>' : 'MotorModel_Sp23_V21b/PID Controller1/Tracking Mode/Disabled'
 * '<S107>' : 'MotorModel_Sp23_V21b/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'MotorModel_Sp23_V21b/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S109>' : 'MotorModel_Sp23_V21b/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'MotorModel_Sp23_V21b/PID Controller1/postSat Signal/Forward_Path'
 * '<S111>' : 'MotorModel_Sp23_V21b/PID Controller1/preSat Signal/Forward_Path'
 * '<S112>' : 'MotorModel_Sp23_V21b/PID Controller2/Anti-windup'
 * '<S113>' : 'MotorModel_Sp23_V21b/PID Controller2/D Gain'
 * '<S114>' : 'MotorModel_Sp23_V21b/PID Controller2/Filter'
 * '<S115>' : 'MotorModel_Sp23_V21b/PID Controller2/Filter ICs'
 * '<S116>' : 'MotorModel_Sp23_V21b/PID Controller2/I Gain'
 * '<S117>' : 'MotorModel_Sp23_V21b/PID Controller2/Ideal P Gain'
 * '<S118>' : 'MotorModel_Sp23_V21b/PID Controller2/Ideal P Gain Fdbk'
 * '<S119>' : 'MotorModel_Sp23_V21b/PID Controller2/Integrator'
 * '<S120>' : 'MotorModel_Sp23_V21b/PID Controller2/Integrator ICs'
 * '<S121>' : 'MotorModel_Sp23_V21b/PID Controller2/N Copy'
 * '<S122>' : 'MotorModel_Sp23_V21b/PID Controller2/N Gain'
 * '<S123>' : 'MotorModel_Sp23_V21b/PID Controller2/P Copy'
 * '<S124>' : 'MotorModel_Sp23_V21b/PID Controller2/Parallel P Gain'
 * '<S125>' : 'MotorModel_Sp23_V21b/PID Controller2/Reset Signal'
 * '<S126>' : 'MotorModel_Sp23_V21b/PID Controller2/Saturation'
 * '<S127>' : 'MotorModel_Sp23_V21b/PID Controller2/Saturation Fdbk'
 * '<S128>' : 'MotorModel_Sp23_V21b/PID Controller2/Sum'
 * '<S129>' : 'MotorModel_Sp23_V21b/PID Controller2/Sum Fdbk'
 * '<S130>' : 'MotorModel_Sp23_V21b/PID Controller2/Tracking Mode'
 * '<S131>' : 'MotorModel_Sp23_V21b/PID Controller2/Tracking Mode Sum'
 * '<S132>' : 'MotorModel_Sp23_V21b/PID Controller2/Tsamp - Integral'
 * '<S133>' : 'MotorModel_Sp23_V21b/PID Controller2/Tsamp - Ngain'
 * '<S134>' : 'MotorModel_Sp23_V21b/PID Controller2/postSat Signal'
 * '<S135>' : 'MotorModel_Sp23_V21b/PID Controller2/preSat Signal'
 * '<S136>' : 'MotorModel_Sp23_V21b/PID Controller2/Anti-windup/Passthrough'
 * '<S137>' : 'MotorModel_Sp23_V21b/PID Controller2/D Gain/Internal Parameters'
 * '<S138>' : 'MotorModel_Sp23_V21b/PID Controller2/Filter/Cont. Filter'
 * '<S139>' : 'MotorModel_Sp23_V21b/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S140>' : 'MotorModel_Sp23_V21b/PID Controller2/I Gain/Internal Parameters'
 * '<S141>' : 'MotorModel_Sp23_V21b/PID Controller2/Ideal P Gain/Passthrough'
 * '<S142>' : 'MotorModel_Sp23_V21b/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S143>' : 'MotorModel_Sp23_V21b/PID Controller2/Integrator/Continuous'
 * '<S144>' : 'MotorModel_Sp23_V21b/PID Controller2/Integrator ICs/Internal IC'
 * '<S145>' : 'MotorModel_Sp23_V21b/PID Controller2/N Copy/Disabled'
 * '<S146>' : 'MotorModel_Sp23_V21b/PID Controller2/N Gain/Internal Parameters'
 * '<S147>' : 'MotorModel_Sp23_V21b/PID Controller2/P Copy/Disabled'
 * '<S148>' : 'MotorModel_Sp23_V21b/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S149>' : 'MotorModel_Sp23_V21b/PID Controller2/Reset Signal/Disabled'
 * '<S150>' : 'MotorModel_Sp23_V21b/PID Controller2/Saturation/Passthrough'
 * '<S151>' : 'MotorModel_Sp23_V21b/PID Controller2/Saturation Fdbk/Disabled'
 * '<S152>' : 'MotorModel_Sp23_V21b/PID Controller2/Sum/Sum_PID'
 * '<S153>' : 'MotorModel_Sp23_V21b/PID Controller2/Sum Fdbk/Disabled'
 * '<S154>' : 'MotorModel_Sp23_V21b/PID Controller2/Tracking Mode/Disabled'
 * '<S155>' : 'MotorModel_Sp23_V21b/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S156>' : 'MotorModel_Sp23_V21b/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S157>' : 'MotorModel_Sp23_V21b/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S158>' : 'MotorModel_Sp23_V21b/PID Controller2/postSat Signal/Forward_Path'
 * '<S159>' : 'MotorModel_Sp23_V21b/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_MotorModel_Sp23_V21b_h_ */
