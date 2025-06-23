// Local
#include "include/Input_Output.h"

void Input_Output::PreStepCallback()
{
	// Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_On_Off = LimitSwitchMotorOnOff.Get();
    Code_Gen_Model_U.Limit_Switch_Motor_FWD_REV = LimitSwitchMotorFWDREV.Get();
}

void Input_Output::PostStepCallback()
{
	
}
