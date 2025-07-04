#pragma once

// Local
#include "lib/include/Component.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"
#include "lib/include/NeoSet.h"
#include "Constants.h"
//FRC
#include <frc/DigitalInput.h>
//playing with fusion
#include <TimeOfFlight.h>
class Input_Output : public Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
  // Limit Switches
  frc::DigitalInput LimitSwitchMotorOnOff {0};
  frc::DigitalInput LimitSwitchMotorFWDREV {1};
  pwf::TimeOfFlight distanceTimeOfFlightSensor{0};
  
  NeoSet boardNeoSet
  {
    {
      Names::motor
    }
  };
};
