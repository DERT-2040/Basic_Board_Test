#include "include/Inputs_Outputs.h"

Inputs_Outputs::Inputs_Outputs()
{
    // Initializations that are not run each step
}

void Inputs_Outputs::PreStepCallback()
{
    // Limit Switches
    Code_Gen_Model_U.LimitSwitch_OnOff = LimitSwitch_OnOff.Get();
    Code_Gen_Model_U.LimitSwitch_FwdRev = LimitSwitch_FwdRev.Get();    

    // Time of Flight sensors
    Code_Gen_Model_U.Distance_Sensor = Distance_Sensor.GetRange();

    // NEO Spark Max sensor feedback
    Inputs_Outputs_NeoSet.pushData();
}

void Inputs_Outputs::PostStepCallback()
{
    // NEO Spark Max motor commands
    Inputs_Outputs_NeoSet.pullCommands();
}