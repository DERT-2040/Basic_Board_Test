#pragma once

// Local
#include "lib/include/Component.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"
# include "Constants.h"
#include "lib/include/NeoSet.h"
//FRC 
#include <frc/DigitalInput.h>
//Playing with Fusion
#include <TimeOfFlightof.h>



class Input_Output : public Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:

// Limit Switches
  frc::DigitalInput limitSwitchMotorOnOff {0};
  frc::DigitalInput limitSwitchMotorForRev {1};

// Playing with Fusion - Time of Flight sensor
  pwf::TimeOfFlight distanceTimeOfFlightSensor{0};

 // NEO Spark Max motor controllers
  NeoSet ReefscapeGameNeoSet{
    {Names::motor}
  }
};
