#pragma once

// Local
#include "lib/include/Component.h"
#include "lib/include/NeoSet.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"
#include "Constants.h"


// FRC
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
  frc::DigitalInput limitswitchMotorOnOff {0};
  frc::DigitalInput limitswitchMotorFwdRev {1};

  // Playing with Fusion - Time of Flight sensor
  pwf::TimeOfFlight distanceTimeOfFlightSensor{0};

   NeoSet BoardNeoSet
  {
    {
      Names::motor
    }
  };
};
