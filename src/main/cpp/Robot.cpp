// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//local
#include "include/Robot.h"
//  Components are included in Robot.hh
//  For each component there is a .cpp file in the 'cpp' folder.
//  For each component there is a .hh file in the 'include' folder

void Robot::RobotInit()
{
  Code_Gen_Model_U.GameState = -1;
  Code_Gen_Model_initialize(); //code gen model init
}

void Robot::RobotPeriodic() 
{  
  m_Tracer.ClearEpochs();
  m_Tracer.AddEpoch("After ClearEpochs");

  PreStep(); //Robot wide PreStep
  m_Tracer.AddEpoch("After PreStep");
  
  Code_Gen_Model_step(); //Step the model
  m_Tracer.AddEpoch("After Simulink");

  PostStep(); //Robot wide PostStep
  m_Tracer.AddEpoch("After PostStep");
  // m_Tracer.PrintEpochs();
  UpdateSmartDashboardValues();
}

void Robot::AutonomousInit() { Code_Gen_Model_U.GameState = 1; GameInitValues();}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {Code_Gen_Model_U.GameState = 2; GameInitValues();}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {Code_Gen_Model_U.GameState = 0; GameInitValues();}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {Code_Gen_Model_U.GameState = 3; GameInitValues();}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {Code_Gen_Model_U.GameState = 4; GameInitValues();}
void Robot::SimulationPeriodic() {}

void Robot::PreStep() 
{
  for (auto m_Component : Component::AllCreatedComponents)
    m_Component->PreStepCallback();
}

void Robot::PostStep() 
{
  for (auto m_Component : Component::AllCreatedComponents)
    m_Component->PostStepCallback();
}

void Robot::GameInitValues() 
{
  for (auto m_Component : Component::AllCreatedComponents)
    m_Component->GameStateChangeCallback();
}

void Robot::UpdateSmartDashboardValues(){
  for (auto m_Component : Component::AllCreatedComponents)
    m_Component->SmartDashboardCallback();
  frc::SmartDashboard::UpdateValues();
}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif
