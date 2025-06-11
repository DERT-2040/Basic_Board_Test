#pragma once
//std
#include <optional>
#include <cstdint>
//rev
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>
#include <rev/SparkRelativeEncoder.h>

struct NeoSparkCreateInfo
{
    //motor
    int canID;
    bool isReversed = false;
    uint8_t smartCurrentLimit = 15;
    double secondaryCurrentLimit = 15;
    double openLoopRampRate = 0.00000001;
    //sensor
    double* setDutyCycleCallback = nullptr;
    double* getVelocityCallback = nullptr;
    double* getPositionCallback = nullptr;
    rev::spark::SparkMax::MotorType motorType = rev::spark::SparkMax::MotorType::kBrushless;

    static constexpr NeoSparkCreateInfo modifyInfo(
        NeoSparkCreateInfo oldCreateInfo,
        int canID,
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

class NeoSpark
{
public:
    NeoSpark(NeoSparkCreateInfo createInfo);
    NeoSpark(NeoSpark&& other) noexcept;

    void getPositionCallback();
    void getVelocityCallback();
    void setDutyCycleCallback();
    void setBrakeModeWhenIdle(bool isBrakeMode);
    void setDutyCycle(double DC);
    void stopMotor();
    
    rev::spark::SparkMax sparkMax;
    std::optional<rev::spark::SparkRelativeEncoder> sparkRelEncoder;
    NeoSparkCreateInfo finalCreateInfo{};
private:
    void initalizeSpark(NeoSparkCreateInfo createInfo);
    
};