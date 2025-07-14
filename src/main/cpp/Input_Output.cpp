// Local
#include "include/Input_Output.h"


void Input_Output::PreStepCallback()
{
    // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_OnOff = limitSwitchMotorOnOff.Get();
    Code_Gen_Model_U.Limit_Switch_Motor_FwdRev = limitSwitchMotorFwdRev.Get();

    // Time of Flight sensors
    Code_Gen_Model_U.TOF_Distance = distanceTimeOfFlightSensor.GetRange();

    // NEO Spark Max sensor feedback
    boardNeoSet.pushData();
		
}

void Input_Output::PostStepCallback()
{
	// NEO Spark Max motor commands
    boardNeoSet.pullCommands();
}
