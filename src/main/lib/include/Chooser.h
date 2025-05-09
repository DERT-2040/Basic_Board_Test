#pragma once

//std
#include <vector>
#include <utility>
#include <string>
#include <functional>

// frc
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Chooser
{
public:
    Chooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap);
    Chooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap, double* simulinkPointer);

    double GetSelectedKey();
    double GetSelectedKey(std::string currentSelection);

private:
    void InitChooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap);

    frc::SendableChooser<std::string> m_chooser;
    std::vector<std::pair<std::string, int>> chooserMap;

    double* chooserSelectedKeyPointer;
};