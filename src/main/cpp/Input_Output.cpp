// Local
#include "include/Input_Output.h"

void Input_Output::PreStepCallback()
{
	 // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_OnOff = limitswitchMotorOnOff.Get();
    Code_Gen_Model_U.Limit_Switch_Motor_FwdRev = limitswitchMotorFwdRev.Get();
}

void Input_Output::PostStepCallback()
{
	
}
