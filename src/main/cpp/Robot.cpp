//local
#include "include/Robot.h"

void Robot::RobotInit()      {Code_Gen_Model_U.GameState = -1; Code_Gen_Model_initialize();}
void Robot::DisabledInit()   {Code_Gen_Model_U.GameState = 0;}
void Robot::AutonomousInit() {Code_Gen_Model_U.GameState = 1;}
void Robot::TeleopInit()     {Code_Gen_Model_U.GameState = 2;}
void Robot::TestInit()       {Code_Gen_Model_U.GameState = 3;}
void Robot::SimulationInit() {Code_Gen_Model_U.GameState = 4;}

void Robot::RobotPeriodic() 
{  
  m_Tracer.ClearEpochs();
  
  PreStep();
  m_Tracer.AddEpoch("After PreStep");
  
  Code_Gen_Model_step(); //Step the model
  m_Tracer.AddEpoch("After Step");

  PostStep();
  m_Tracer.AddEpoch("After PostStep");
}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif
