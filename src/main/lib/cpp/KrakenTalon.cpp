#include "lib/include/KrakenTalon.h"

// Create talon controller with CAN ID
KrakenTalon::KrakenTalon(KrakenTalonCreateInfo createInfo)
: talonController{createInfo.canID, createInfo.canbus},
dutyCycleControl{0}
{
    initalizeTalon(createInfo);
}

// Configure the talon controller settings
void KrakenTalon::initalizeTalon(KrakenTalonCreateInfo createInfo)
{
    // Get Configurator to Apply configuration settings
    auto& talonConfigurator = talonController.GetConfigurator();

    // Set Direction
    ctre::phoenix6::configs::MotorOutputConfigs motorDirectionConfig;
    motorDirectionConfig.Inverted = createInfo.isReversed ? 
        ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive : 
        ctre::phoenix6::signals::InvertedValue::Clockwise_Positive;
    talonConfigurator.Apply(motorDirectionConfig);

    // Set Open Loop Ramp Period
    ctre::phoenix6::configs::OpenLoopRampsConfigs rampPeriodConfig;
    units::time::second_t openLoopRampPeriod_time {createInfo.openLoopRampPeriod};
    rampPeriodConfig.DutyCycleOpenLoopRampPeriod = openLoopRampPeriod_time;
    talonConfigurator.Apply(rampPeriodConfig);

    // Set Current Limiting Configuration
    ctre::phoenix6::configs::CurrentLimitsConfigs currentLimitsConfig;
    units::current::ampere_t supplyCurrentLimit_amps {createInfo.supplyCurrentLimit};
    currentLimitsConfig.SupplyCurrentLimit = supplyCurrentLimit_amps;
    currentLimitsConfig.SupplyCurrentLimitEnable = true;
    talonConfigurator.Apply(currentLimitsConfig);

    // Initialize Duty Cycle Output Communication
    dutyCycleControl.WithEnableFOC(createInfo.enableFOC);

    // Store for later use
    finalCreateInfo = createInfo;
}

// Get Motor Encoder Position
void KrakenTalon::getPositionCallback()
{  
    *finalCreateInfo.getPositionCallback = talonController.GetPosition().GetValueAsDouble();
}

// Get Motor Encoder Velocity
void KrakenTalon::getVelocityCallback()
{  
    *finalCreateInfo.getVelocityCallback = talonController.GetVelocity().GetValueAsDouble()*60;  // Multiply by 60 for Rev/Sec to Rev/Min
}

// Set Motor Duty Cycle
void KrakenTalon::setDutyCycleCallback()
{
    talonController.SetControl(dutyCycleControl.WithOutput(*finalCreateInfo.setDutyCycleCallback));
}