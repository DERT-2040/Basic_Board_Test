// Local
#include "include/Input_Output.h"

void Input_Output::PreStepCallback()
{
	 // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_OnOff = limitSwitchMotorOnOff.Get();
    Code_Gen_Model_U.Limit_Switch_Motor_ForRev = limitSwitchMotorForRev.Get();
     // Time of Flight sensors
    Code_Gen_Model_U.Coral_TOF_Distance = distanceTimeOfFlightSensor.GetRange();
}

void Input_Output::PostStepCallback()
{
	  // NEO Spark Max motor commands
    BoardNeoSet.pullCommands();
}
