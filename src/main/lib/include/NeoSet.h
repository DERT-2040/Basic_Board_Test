#pragma once

//std
#include <algorithm>
#include <vector>
#include <functional>
#include <memory>
//local
#include "lib/include/NeoSpark.h"
//rev
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>
#include <rev/SparkRelativeEncoder.h>

class NeoSet
{
public:
    NeoSet(std::initializer_list<NeoSparkCreateInfo> createInfos);
    void stop();
    void set(double dutyCycle);
    void setBrakeModeWhenIdle(bool isBrakeMode);
    void pushData();
    void pullCommands();
private:
    void addCallbacks(NeoSpark& motor);
    std::vector<std::unique_ptr<NeoSpark>> motorSet;
    std::vector<std::function<void()>> pushDataCalbacks;
    std::vector<std::function<void()>> pullCommandCalbacks;
};