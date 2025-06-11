#pragma once

// Libraries
#include <frc/DigitalInput.h>       // RoboRio digital inputs
#include <TimeOfFlight.h>           // Playing With Fusion

// Local
#include "Constants.h"              // Where hardware level constants are defined
#include "lib/include/Component.h"  // Component class (required)
#include "lib/include/NeoSet.h"     // Spark Max motor controller
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"  // Simulink input/output ports

namespace InputsOutputsNameSpace = Constants::Inputs_Outputs;

class Inputs_Outputs : public Component
{
public:
    // Declare the class
    Inputs_Outputs();

    /**
     * Runs before the step function is called in the main loop
     */
    void PreStepCallback() override;

    /**
     * Runs after the step function is called in the main loop
     */
    void PostStepCallback() override;
    
    /*
     * X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
     * X X X X                 Class Specific Methods                  X X X X
     * X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
     */

private:
    // Limit switch inputs
    frc::DigitalInput LimitSwitch_OnOff  {InputsOutputsNameSpace::DIO_Port_LimitSwitch_OnOff};
    frc::DigitalInput LimitSwitch_FwdRev {InputsOutputsNameSpace::DIO_Port_LimitSwitch_FwdRev};

    // Playing with Fusion - Time of Flight sensor
    pwf::TimeOfFlight Distance_Sensor {InputsOutputsNameSpace::TOF_ID_Distance};

    // NEO Spark Max motor controllers
    NeoSet Inputs_Outputs_NeoSet
    {
        {
        InputsOutputsNameSpace::CreateInfo_Motor
        }
    };

};

  