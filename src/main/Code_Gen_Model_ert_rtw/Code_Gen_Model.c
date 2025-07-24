/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.403
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul 17 19:02:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S10>/Chart' */
#define Code_Gen_Mod_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Code_Gen_Model_IN_Forward      ((uint8_T)1U)
#define Code_Gen_Model_IN_Off          ((uint8_T)2U)
#define Code_Gen_Model_IN_Reverse      ((uint8_T)3U)

/* Exported block parameters */
real_T Auto_Signal_two = 60.0;         /* Variable: Auto_Signal_two
                                        * Referenced by: '<S7>/Constant1'
                                        */
real_T Teleop_Signal_two = 20.0;       /* Variable: Teleop_Signal_two
                                        * Referenced by: '<S10>/Constant1'
                                        */

/* Block signals (default storage) */
B_Code_Gen_Model_T Code_Gen_Model_B;

/* Block states (default storage) */
DW_Code_Gen_Model_T Code_Gen_Model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Code_Gen_Model_T Code_Gen_Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Code_Gen_Model_T Code_Gen_Model_Y;

/* Real-time model */
static RT_MODEL_Code_Gen_Model_T Code_Gen_Model_M_;
RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M = &Code_Gen_Model_M_;

/* Model step function */
void Code_Gen_Model_step(void)
{
  real_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/Motor_Revolutions'
   *  Inport: '<Root>/Motor_Speed'
   */
  Code_Gen_Model_B.Add_tp = Code_Gen_Model_U.Motor_Speed +
    Code_Gen_Model_U.Motor_Revolutions;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Code_Gen_Model_DW.SwitchCase_ActiveSubsystem;
  tmp = trunc(Code_Gen_Model_U.GameState);
  if ((rtIsNaN(tmp)) || (rtIsInf(tmp))) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch ((tmp < 0.0) ? (-((int32_T)((uint32_T)(-tmp)))) : ((int32_T)((uint32_T)
            tmp))) {
   case 0:
    rtAction = 0;
    break;

   case 1:
    rtAction = 1;
    break;

   case 2:
    rtAction = 2;
    break;

   default:
    rtAction = 3;
    break;
  }

  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outport: '<Root>/Motor_DutyCycle' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/Motor_DutyCycle'
     */
    Code_Gen_Model_Y.Motor_DutyCycle = 0.0;

    /* Outport: '<Root>/Signal_two' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/Signal_two'
     */
    Code_Gen_Model_Y.Signal_two = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  Inport: '<Root>/Limit_Switch_Motor_OnOff'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (Code_Gen_Model_U.Limit_Switch_Motor_OnOff != 0.0) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  Constant: '<S9>/Constant'
       *  Inport: '<Root>/Limit_Switch_Motor_FwdRev'
       *  RelationalOperator: '<S9>/Compare'
       */
      if (Code_Gen_Model_U.Limit_Switch_Motor_FwdRev != 0.0) {
        /* Outport: '<Root>/Motor_DutyCycle' incorporates:
         *  Constant: '<S7>/Constant'
         *  Inport: '<Root>/TOF_Distance'
         *  Product: '<S7>/Divide'
         *  UnaryMinus: '<S7>/Unary Minus'
         */
        Code_Gen_Model_Y.Motor_DutyCycle = -(Code_Gen_Model_U.TOF_Distance /
          300.0);
      } else {
        /* Outport: '<Root>/Motor_DutyCycle' incorporates:
         *  Constant: '<S7>/Constant'
         *  Inport: '<Root>/TOF_Distance'
         *  Product: '<S7>/Divide'
         */
        Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance / 300.0;
      }

      /* End of Switch: '<S7>/Switch1' */
    } else {
      /* Outport: '<Root>/Motor_DutyCycle' incorporates:
       *  Constant: '<S7>/Constant3'
       */
      Code_Gen_Model_Y.Motor_DutyCycle = 0.0;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Outport: '<Root>/Signal_two' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S2>/Signal_two'
     */
    Code_Gen_Model_Y.Signal_two = Auto_Signal_two;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S1>/Teleop' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S10>/Chart'
       */
      Code_Gen_Model_DW.is_active_c3_Code_Gen_Model = 0U;
      Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Mod_IN_NO_ACTIVE_CHILD;

      /* End of SystemReset for SubSystem: '<S1>/Teleop' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Chart: '<S10>/Chart' incorporates:
     *  Inport: '<Root>/Limit_Switch_Motor_FwdRev'
     *  Inport: '<Root>/Limit_Switch_Motor_OnOff'
     */
    if (Code_Gen_Model_DW.is_active_c3_Code_Gen_Model == 0U) {
      Code_Gen_Model_DW.is_active_c3_Code_Gen_Model = 1U;
      Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Off;

      /* Outport: '<Root>/Motor_DutyCycle' */
      Code_Gen_Model_Y.Motor_DutyCycle = 0.0;
    } else {
      switch (Code_Gen_Model_DW.is_c3_Code_Gen_Model) {
       case Code_Gen_Model_IN_Forward:
        if (!(Code_Gen_Model_U.Limit_Switch_Motor_OnOff != 0.0)) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Off;

          /* Outport: '<Root>/Motor_DutyCycle' */
          Code_Gen_Model_Y.Motor_DutyCycle = 0.0;
        } else if (Code_Gen_Model_U.Limit_Switch_Motor_FwdRev != 0.0) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Reverse;

          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            -300.0;
        } else {
          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            300.0;
        }
        break;

       case Code_Gen_Model_IN_Off:
        if ((Code_Gen_Model_U.Limit_Switch_Motor_OnOff != 0.0) &&
            (!(Code_Gen_Model_U.Limit_Switch_Motor_FwdRev != 0.0))) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Forward;

          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            300.0;
        } else if ((Code_Gen_Model_U.Limit_Switch_Motor_OnOff != 0.0) &&
                   (Code_Gen_Model_U.Limit_Switch_Motor_FwdRev != 0.0)) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Reverse;

          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            -300.0;
        } else {
          /* Outport: '<Root>/Motor_DutyCycle' */
          Code_Gen_Model_Y.Motor_DutyCycle = 0.0;
        }
        break;

       default:
        /* case IN_Reverse: */
        if (!(Code_Gen_Model_U.Limit_Switch_Motor_OnOff != 0.0)) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Off;

          /* Outport: '<Root>/Motor_DutyCycle' */
          Code_Gen_Model_Y.Motor_DutyCycle = 0.0;
        } else if (!(Code_Gen_Model_U.Limit_Switch_Motor_FwdRev != 0.0)) {
          Code_Gen_Model_DW.is_c3_Code_Gen_Model = Code_Gen_Model_IN_Forward;

          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            300.0;
        } else {
          /* Outport: '<Root>/Motor_DutyCycle' incorporates:
           *  Inport: '<Root>/TOF_Distance'
           */
          Code_Gen_Model_Y.Motor_DutyCycle = Code_Gen_Model_U.TOF_Distance /
            -300.0;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/Chart' */

    /* Outport: '<Root>/Signal_two' incorporates:
     *  Constant: '<S10>/Constant1'
     *  SignalConversion generated from: '<S5>/Signal_two'
     */
    Code_Gen_Model_Y.Signal_two = Teleop_Signal_two;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Outport: '<Root>/Motor_DutyCycle' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/Motor_DutyCycle'
     */
    Code_Gen_Model_Y.Motor_DutyCycle = 0.0;

    /* Outport: '<Root>/Signal_two' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/Signal_two'
     */
    Code_Gen_Model_Y.Signal_two = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;
}

/* Model terminate function */
void Code_Gen_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
