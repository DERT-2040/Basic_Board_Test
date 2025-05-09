#pragma once
//std
#include <optional>
#include <cstdint>
#include <string>
//units
#include <units/time.h>
#include <units/current.h>
//ctre
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/core/CoreTalonFX.hpp>
#include <ctre/phoenix6/configs/Configs.hpp>
#include <ctre/phoenix6/StatusSignal.hpp>

struct KrakenTalonCreateInfo
{
    //motor
    int canID;
    const char* canbus;
    bool isReversed = false;
    double supplyCurrentLimit = 15;
    double openLoopRampPeriod = 0;
    bool enableFOC = true;

    //sensor
    double* setDutyCycleCallback = nullptr;
    double* getVelocityCallback = nullptr;
    double* getPositionCallback = nullptr;

    static constexpr KrakenTalonCreateInfo modifyInfo(
        KrakenTalonCreateInfo oldCreateInfo,
        int canID,           // CAN ID for the device
        double* setDutyCycleCallback = nullptr,
        double* getVelocityCallback = nullptr,
        double* getPositionCallback = nullptr)
    {
        auto newCreateInfo = oldCreateInfo;
        newCreateInfo.canID = canID;
        newCreateInfo.setDutyCycleCallback = setDutyCycleCallback;
        newCreateInfo.getVelocityCallback = getVelocityCallback;
        newCreateInfo.getPositionCallback = getPositionCallback;
        return newCreateInfo;
    }
};

class KrakenTalon
{
public:
    KrakenTalon(KrakenTalonCreateInfo createInfo);
    KrakenTalon(KrakenTalonCreateInfo createInfo, int canID);
    KrakenTalon(KrakenTalon&& other) noexcept;

    void getPositionCallback();
    void getVelocityCallback();
    void setDutyCycleCallback();
    ctre::phoenix6::hardware::TalonFX talonController;
    ctre::phoenix6::controls::DutyCycleOut dutyCycleControl;
    KrakenTalonCreateInfo finalCreateInfo{};
private:
    void initalizeTalon(KrakenTalonCreateInfo createInfo);
};