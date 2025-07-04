/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.402
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul  3 19:38:32 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Exported block parameters */
real_T Auto_Signal_two = 60.0;         /* Variable: Auto_Signal_two
                                        * Referenced by: '<S7>/Constant1'
                                        */
real_T Teleop_Signal_one = 10.0;       /* Variable: Teleop_Signal_one
                                        * Referenced by: '<S10>/Constant'
                                        */
real_T Teleop_Signal_two = 20.0;       /* Variable: Teleop_Signal_two
                                        * Referenced by: '<S10>/Constant1'
                                        */

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

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  tmp = trunc(Code_Gen_Model_U.GameState);
  if ((rtIsNaN(tmp)) || (rtIsInf(tmp))) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch ((tmp < 0.0) ? (-((int32_T)((uint32_T)(-tmp)))) : ((int32_T)((uint32_T)
            tmp))) {
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
     *  Inport: '<Root>/Limit_Switch_Motor_On_Off'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (Code_Gen_Model_U.Limit_Switch_Motor_On_Off != 0.0) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  Constant: '<S9>/Constant'
       *  Inport: '<Root>/Limit_Switch_Motor_FWD_REV'
       *  RelationalOperator: '<S9>/Compare'
       */
      if (Code_Gen_Model_U.Limit_Switch_Motor_FWD_REV != 0.0) {
        /* Outport: '<Root>/Motor_DutyCycle' incorporates:
         *  Constant: '<S7>/Constant'
         *  Inport: '<Root>/TOF_Distance'
         *  Product: '<S7>/Divide'
         *  UnaryMinus: '<S7>/Unary Minus1'
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
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Outport: '<Root>/Motor_DutyCycle' incorporates:
     *  Constant: '<S10>/Constant'
     *  SignalConversion generated from: '<S5>/Motor_DutyCycle'
     */
    Code_Gen_Model_Y.Motor_DutyCycle = Teleop_Signal_one;

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
