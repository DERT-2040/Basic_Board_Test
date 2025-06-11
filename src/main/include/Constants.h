#pragma once

// Local
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"  // Simulink input/output ports
#include "lib/include/NeoSpark.h"                   // Spart Max Motors Create Info

namespace Constants
{
    namespace Inputs_Outputs
    {
        // Limit Switches
        static constexpr int DIO_Port_LimitSwitch_OnOff = 0;
        static constexpr int DIO_Port_LimitSwitch_FwdRev = 1;

        // The Playing with Fusion configuration interface tool may be accessed by typing in the
        // IP address of the roboRIO into a web browser followed by :5812
        static constexpr uint8_t TOF_ID_Distance = 0;

        // Actuator motor controller configuration
        static NeoSparkCreateInfo CreateInfo_Motor{
            1,              // canID
            false,          // isReversed
            80,             // smartCurrentLimit
            80,             // secondaryCurrentLimit
            0.01,           // openLoopRampRate (seconds)
            &Code_Gen_Model_Y.Motor_DutyCycle,   // Simulink motor duty cycle port name
            &Code_Gen_Model_U.Motor_Velocity,    // Simulink motor motor velocity port name
            &Code_Gen_Model_U.Motor_Revs         // Simulink motor revolutions port name
        };      
    };
};