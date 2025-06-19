// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//local
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
#include "lib/include/Component.h"
#include "include/SimulinkSmartDashboardInterface.h"

// For each component also add content in this file at the bottom of the private area

//frc
#include <frc/TimedRobot.h>
#include <frc/DriverStation.h>
//std
#include <iostream>

class Robot : public frc::TimedRobot {
public:
  /** Runs once when robot turns on */
  void RobotInit() override;

  /** The following code runs once when its mode is enabledd */
  void AutonomousInit() override;
  void TeleopInit() override;
  void DisabledInit() override;
  void TestInit() override;
  void SimulationInit() override;

  /** Runs every 20ms regardless of what mode the robot is in */
  void RobotPeriodic() override;
  void AutonomousPeriodic() override {};
  void TeleopPeriodic() override {};
  void DisabledPeriodic() override {};
  void TestPeriodic() override {};
  void SimulationPeriodic() override {};

private:
  /** Puts all inputs from sensors and HIDs into Simulink */
  void PreStep() {for(auto component : Component::AllCreatedComponents) component->PreStepCallback();}
  
  /** Takes outputs from simulink and pushes their commands to hardware */
  void PostStep() {for(auto component : Component::AllCreatedComponents) component->PostStepCallback();}

  /*
   * Below are the instances of the subsystems used by the robot
   * Everything here should be direct hardware control, only
   * functions that manipulate global variables declared by Simulink
   * are exceptions to this rule.
   */

   /** Monitor code execution time */
  frc::Tracer m_Tracer{};

  /** Component for all Tunable Parameters created by simulink */
  SimulinkSmartDashboardInterface m_SimulinkSmartDashboardInterface;  
  
};
