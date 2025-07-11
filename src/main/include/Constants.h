#pragma once
//std
#include <string>
//local
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"
#include "lib/include/NeoSpark.h"
namespace Names
{
    // Coral Arm motor controller configuration
        static constexpr NeoSparkCreateInfo MotorCreateInfo{
            -1,   // canID
            true, // isReversed
            12,   // smartCurrentLimit
            12,   // secondaryCurrentLimit
            0.01, // openLoopRampRate (seconds)
        };
        static NeoSparkCreateInfo motor = NeoSparkCreateInfo::modifyInfo(MotorCreateInfo,
                                                                             1, // CAN ID
                                                                             &Code_Gen_Model_Y.motor_DutyCycle);
};