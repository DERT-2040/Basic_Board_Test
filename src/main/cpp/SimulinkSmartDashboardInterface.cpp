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
 
    __Auto_Signal_one__Entry = NTtable_Tune->GetEntry("Auto_Signal_one");
    NTinst.AddListener(__Auto_Signal_one__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Auto_Signal_one = event.GetValueEventData()->value.GetDouble();});
    __Auto_Signal_one__Entry.SetDouble(50);
 
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
    __GameState__Entry = NTtable_Inport->GetEntry("GameState");
 
// Outports
    __Signal_one__Entry = NTtable_Outport->GetEntry("Signal_one");
    __Signal_two__Entry = NTtable_Outport->GetEntry("Signal_two");
 
// Test Points
}
 
void SimulinkSmartDashboardInterface::PreStepCallback() {}
 
void SimulinkSmartDashboardInterface::PostStepCallback() {}
 
void SimulinkSmartDashboardInterface::SmartDashboardCallback()
{
    // Inports
    __GameState__Entry.SetDouble(Code_Gen_Model_U.GameState);
    // Outports
    __Signal_one__Entry.SetDouble(Code_Gen_Model_Y.Signal_one);
    __Signal_two__Entry.SetDouble(Code_Gen_Model_Y.Signal_two);
    // Test Points
    // Tunable Parameters
    __Auto_Signal_one__Entry.SetDouble(Auto_Signal_one);
    __Auto_Signal_two__Entry.SetDouble(Auto_Signal_two);
    __Teleop_Signal_one__Entry.SetDouble(Teleop_Signal_one);
    __Teleop_Signal_two__Entry.SetDouble(Teleop_Signal_two);
}
void SimulinkSmartDashboardInterface::GameStateChangeCallback() {}
