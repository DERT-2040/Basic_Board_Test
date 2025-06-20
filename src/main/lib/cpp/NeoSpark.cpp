#include "lib/include/NeoSpark.h"

NeoSpark::NeoSpark(NeoSparkCreateInfo createInfo)
: sparkMax{createInfo.canID, createInfo.motorType}
{
    initalizeSpark(createInfo);
}

void NeoSpark::initalizeSpark(NeoSparkCreateInfo createInfo)
{
    rev::spark::SparkMaxConfig config{};
    config
        .Inverted(createInfo.isReversed)
        .SmartCurrentLimit(createInfo.smartCurrentLimit)
        .SecondaryCurrentLimit(createInfo.secondaryCurrentLimit)
        .OpenLoopRampRate(createInfo.openLoopRampRate);
    sparkMax.Configure(config,
                       rev::spark::SparkBase::ResetMode::kResetSafeParameters,
                       rev::spark::SparkBase::PersistMode::kNoPersistParameters);
    if(createInfo.getVelocityCallback != nullptr || createInfo.getPositionCallback != nullptr)
        sparkRelEncoder = sparkMax.GetEncoder();
    finalCreateInfo = createInfo;
}

void NeoSpark::getPositionCallback()
{
    *finalCreateInfo.getPositionCallback = sparkRelEncoder->GetPosition();
}

void NeoSpark::getVelocityCallback()
{
    *finalCreateInfo.getVelocityCallback = sparkRelEncoder->GetVelocity();
}

void NeoSpark::setDutyCycleCallback()
{
    sparkMax.Set(*finalCreateInfo.setDutyCycleCallback);
}

void NeoSpark::setBrakeModeWhenIdle(bool isBrakeMode)
{
    rev::spark::SparkMaxConfig config{};
    config.SetIdleMode((isBrakeMode) ?  rev::spark::SparkBaseConfig::IdleMode::kBrake :  rev::spark::SparkBaseConfig::IdleMode::kCoast );
    sparkMax.Configure(config,
                       rev::spark::SparkBase::ResetMode::kNoResetSafeParameters,
                       rev::spark::SparkBase::PersistMode::kNoPersistParameters);
}

void NeoSpark::setDutyCycle(double DC)
{
    sparkMax.Set(DC);
}

void NeoSpark::stopMotor()
{
    sparkMax.StopMotor();
}