#include "lib/include/NeoSpark.h"

NeoSpark::NeoSpark(NeoSparkCreateInfo createInfo)
: sparkMax{createInfo.canID, createInfo.motorType}
{
    initalizeSpark(createInfo);
}

NeoSpark::NeoSpark(int canID, bool includeSensor)
: sparkMax{canID, rev::spark::SparkMax::MotorType::kBrushless}
{
    finalCreateInfo.includeSensor = includeSensor;
    initalizeSpark(finalCreateInfo);
}

NeoSpark::NeoSpark(NeoSparkCreateInfo createInfo, int canID, bool isReversed)
: sparkMax{canID, createInfo.motorType}
{
    createInfo.isReversed = isReversed;
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
    if(createInfo.includeSensor)
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