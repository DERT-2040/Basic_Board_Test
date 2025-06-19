#include "lib/include/NeoSet.h"

NeoSet::NeoSet(std::initializer_list<NeoSparkCreateInfo> createInfos)
{
    for(auto createInfo : createInfos)
    {
        motorSet.push_back(std::make_unique<NeoSpark>(createInfo));
        addCallbacks(*motorSet.back());
    }
}

void NeoSet::stop()
{
    for(auto& motor : motorSet)
        motor->stopMotor();
}

void NeoSet::set(double dutyCycle)
{
    for(auto& motor : motorSet)
        motor->setDutyCycle(dutyCycle);
}

void NeoSet::setBrakeModeWhenIdle(bool isBrakeMode)
{
    for(auto& motor : motorSet)
        motor->setBrakeModeWhenIdle(isBrakeMode);
}

void NeoSet::addCallbacks(NeoSpark& motor)
{
    if(motor.finalCreateInfo.setDutyCycleCallback != nullptr)
        pullCommandCalbacks.push_back(std::bind(&NeoSpark::setDutyCycleCallback, &motor));
    if(motor.finalCreateInfo.getPositionCallback != nullptr)
        pushDataCalbacks.push_back(std::bind(&NeoSpark::getPositionCallback, &motor));
    if(motor.finalCreateInfo.getVelocityCallback != nullptr)
        pushDataCalbacks.push_back(std::bind(&NeoSpark::getVelocityCallback, &motor));
}

void NeoSet::pushData()
{
    for(auto func : pushDataCalbacks)
        func();
}

void NeoSet::pullCommands()
{
    for(auto func : pullCommandCalbacks)
        func();
}