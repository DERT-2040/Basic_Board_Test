// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#include "include/SimulinkSmartDashboardInterface.h"
 
SimulinkSmartDashboardInterface::SimulinkSmartDashboardInterface()
{
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");
    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");
 
    __Auto_Signal_two__Entry = NTtable_Tune->GetEntry("Auto_Signal_two");
    NTinst.AddListener(__Auto_Signal_two__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Signal_two = event.GetValueEventData()->value.GetDouble();});
    __Auto_Signal_two__Entry.SetDouble(60);
 
    __Teleop_Signal_one__Entry = NTtable_Tune->GetEntry("Teleop_Signal_one");
    NTinst.AddListener(__Teleop_Signal_one__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Teleop_Signal_one = event.GetValueEventData()->value.GetDouble();});
    __Teleop_Signal_one__Entry.SetDouble(10);
 
    __Teleop_Signal_two__Entry = NTtable_Tune->GetEntry("Teleop_Signal_two");
    NTinst.AddListener(__Teleop_Signal_two__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Teleop_Signal_two = event.GetValueEventData()->value.GetDouble();});
    __Teleop_Signal_two__Entry.SetDouble(20);
 
// Inports
    __Coral_TOF_Distance__Entry = NTtable_Inport->GetEntry("Coral_TOF_Distance");
    __GameState__Entry = NTtable_Inport->GetEntry("GameState");
    __Limit_Switch_Motor_FwdRev__Entry = NTtable_Inport->GetEntry("Limit_Switch_Motor_FwdRev");
    __Limit_Switch_Motor_OnOff__Entry = NTtable_Inport->GetEntry("Limit_Switch_Motor_OnOff");
 
// Outports
    __Signal_two__Entry = NTtable_Outport->GetEntry("Signal_two");
    __motor_DutyCycle__Entry = NTtable_Outport->GetEntry("motor_DutyCycle");
 
// Test Points
}
 
void SimulinkSmartDashboardInterface::PreStepCallback() {}
 
void SimulinkSmartDashboardInterface::PostStepCallback()
{
    // Inports
    __Coral_TOF_Distance__Entry.SetDouble(Code_Gen_Model_U.Coral_TOF_Distance);
    __GameState__Entry.SetDouble(Code_Gen_Model_U.GameState);
    __Limit_Switch_Motor_FwdRev__Entry.SetDouble(Code_Gen_Model_U.Limit_Switch_Motor_FwdRev);
    __Limit_Switch_Motor_OnOff__Entry.SetDouble(Code_Gen_Model_U.Limit_Switch_Motor_OnOff);
    // Outports
    __Signal_two__Entry.SetDouble(Code_Gen_Model_Y.Signal_two);
    __motor_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.motor_DutyCycle);
    // Test Points
    // Tunable Parameters
    __Auto_Signal_two__Entry.SetDouble(Auto_Signal_two);
    __Teleop_Signal_one__Entry.SetDouble(Teleop_Signal_one);
    __Teleop_Signal_two__Entry.SetDouble(Teleop_Signal_two);
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
