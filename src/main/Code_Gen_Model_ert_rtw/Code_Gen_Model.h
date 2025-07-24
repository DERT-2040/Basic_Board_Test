/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.404
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul 24 18:08:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Code_Gen_Model_h_
#define RTW_HEADER_Code_Gen_Model_h_
#ifndef Code_Gen_Model_COMMON_INCLUDES_
#define Code_Gen_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Code_Gen_Model_COMMON_INCLUDES_ */

#include "Code_Gen_Model_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add_tp;                       /* '<Root>/Add' */
  real_T Motor_DutyCycle;              /* '<S10>/Chart' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Prev_State;                   /* '<S10>/Chart' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c3_Code_Gen_Model; /* '<S10>/Chart' */
  uint8_T is_c3_Code_Gen_Model;        /* '<S10>/Chart' */
  uint8_T is_On_State;                 /* '<S10>/Chart' */
} DW_Code_Gen_Model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T GameState;                    /* '<Root>/GameState' */
  real_T Limit_Switch_Motor_OnOff;     /* '<Root>/Limit_Switch_Motor_OnOff' */
  real_T Limit_Switch_Motor_FwdRev;    /* '<Root>/Limit_Switch_Motor_FwdRev' */
  real_T TOF_Distance;                 /* '<Root>/TOF_Distance' */
  real_T Motor_Speed;                  /* '<Root>/Motor_Speed' */
  real_T Motor_Revolutions;            /* '<Root>/Motor_Revolutions' */
} ExtU_Code_Gen_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Motor_DutyCycle;              /* '<Root>/Motor_DutyCycle' */
  real_T Signal_two;                   /* '<Root>/Signal_two' */
} ExtY_Code_Gen_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_Code_Gen_Model_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Code_Gen_Model_T Code_Gen_Model_B;

/* Block states (default storage) */
extern DW_Code_Gen_Model_T Code_Gen_Model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Code_Gen_Model_T Code_Gen_Model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Code_Gen_Model_T Code_Gen_Model_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Auto_Signal_two;         /* Variable: Auto_Signal_two
                                        * Referenced by: '<S7>/Constant1'
                                        */
extern real_T Teleop_Signal_two;       /* Variable: Teleop_Signal_two
                                        * Referenced by: '<S10>/Constant1'
                                        */

/* Model entry point functions */
extern void Code_Gen_Model_initialize(void);
extern void Code_Gen_Model_step(void);
extern void Code_Gen_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M;

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
 * '<Root>' : 'Code_Gen_Model'
 * '<S1>'   : 'Code_Gen_Model/RoboRio Controls'
 * '<S2>'   : 'Code_Gen_Model/RoboRio Controls/Autonomous'
 * '<S3>'   : 'Code_Gen_Model/RoboRio Controls/Disabled'
 * '<S4>'   : 'Code_Gen_Model/RoboRio Controls/Merge Subsystem'
 * '<S5>'   : 'Code_Gen_Model/RoboRio Controls/Teleop'
 * '<S6>'   : 'Code_Gen_Model/RoboRio Controls/Test'
 * '<S7>'   : 'Code_Gen_Model/RoboRio Controls/Autonomous/Autonomous_sub'
 * '<S8>'   : 'Code_Gen_Model/RoboRio Controls/Autonomous/Autonomous_sub/Compare To Zero'
 * '<S9>'   : 'Code_Gen_Model/RoboRio Controls/Autonomous/Autonomous_sub/Compare To Zero1'
 * '<S10>'  : 'Code_Gen_Model/RoboRio Controls/Teleop/Teleop_sub'
 * '<S11>'  : 'Code_Gen_Model/RoboRio Controls/Teleop/Teleop_sub/Chart'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
