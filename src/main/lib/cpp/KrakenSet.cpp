#include "lib/include/KrakenSet.h"

KrakenSet::KrakenSet(std::initializer_list<KrakenTalonCreateInfo> createInfos)
{
    for(auto createInfo : createInfos)
    {
        motorSet.push_back(std::make_unique<KrakenTalon>(createInfo));
        addCallbacks(*motorSet.back());
    }
}

void KrakenSet::stop()
{
    for(auto& motor : motorSet)
    {
        motor->talonController.StopMotor();
    }
}

void KrakenSet::set(double dutyCycle)
{
    for(auto& motor : motorSet)
    {
        motor->talonController.SetControl(motor->dutyCycleControl.WithOutput(*motor->finalCreateInfo.setDutyCycleCallback));
    }
}

void KrakenSet::setBrakeModeWhenIdle(bool isBrakeMode)
{
    for(auto& motor : motorSet)
    {
        motor->dutyCycleControl.WithOverrideBrakeDurNeutral(isBrakeMode);
    }
}

void KrakenSet::addCallbacks(KrakenTalon& motor)
{
    if(motor.finalCreateInfo.setDutyCycleCallback != nullptr)
        pullCommandCalbacks.push_back(std::bind(&KrakenTalon::setDutyCycleCallback, &motor));
    if(motor.finalCreateInfo.getPositionCallback != nullptr)
        pushDataCalbacks.push_back(std::bind(&KrakenTalon::getPositionCallback, &motor));
    if(motor.finalCreateInfo.getVelocityCallback != nullptr)
        pushDataCalbacks.push_back(std::bind(&KrakenTalon::getVelocityCallback, &motor));
}

void KrakenSet::pushData()
{
    for(auto func : pushDataCalbacks)
        func();
}

void KrakenSet::pullCommands()
{
    for(auto func : pullCommandCalbacks)
        func();
}