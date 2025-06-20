// Local
#include "include/Input_Output.h"

void Input_Output::PreStepCallback()
{
    // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_OnOff = limitSwitchMotorOnOff.Get();	
    // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_FwdRev = limitSwitchMotorFwdRev.Get();	
}

void Input_Output::PostStepCallback()
{
	
}
