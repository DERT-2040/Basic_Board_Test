// Local
#include "include/Input_Output.h"


void Input_Output::PreStepCallback()
{
	 // Limit Switches
    Code_Gen_Model_U.Limit_Switch_Motor_OnOff = limitSwitchMotoronoff.Get();
    Code_Gen_Model_U.Limit_Switch_Motor_FwdRev = limitSwitchMotorFwdRev.Get();


  // Time of Flight sensors
    Code_Gen_Model_U.TOF_Distance = distanceTimeOfFlightSensor.GetRange();

}

void Input_Output::PostStepCallback()
{
	// NEO Spark Max motor commands
    boardNeoSet.pullCommands();
}
