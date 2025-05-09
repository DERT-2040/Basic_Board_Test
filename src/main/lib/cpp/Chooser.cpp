#include "lib/include/Chooser.h"

Chooser::Chooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap)
{
    InitChooser(ChooserName, chooserMap);
}

Chooser::Chooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap, double* simulinkPointer)
{
    InitChooser(ChooserName, chooserMap);
    chooserSelectedKeyPointer = simulinkPointer;

    m_chooser.OnChange(
        [&](std::string currentSelection){
            *chooserSelectedKeyPointer = GetSelectedKey(currentSelection);
        }
    );
}

void Chooser::InitChooser(std::string ChooserName, std::vector<std::pair<std::string, int>> chooserMap)
{
    this->chooserMap = chooserMap;

    if(chooserMap.size() == 0)
        throw std::runtime_error("Chooser Length must be greater than zero");

    m_chooser.SetDefaultOption(chooserMap.at(0).first, chooserMap.at(0).first);

    for(size_t pos = 1; pos < chooserMap.size(); pos++)
    {
        m_chooser.AddOption(chooserMap.at(pos).first, chooserMap.at(pos).first);
    }

    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * warning: the defulat value if the current selected is not found is -1
 */
double Chooser::GetSelectedKey(std::string currentSelection)
{
    for(size_t pos = 0; pos < chooserMap.size(); pos++)
    {
        std::pair<std::string, int> pairAtPos = chooserMap.at(pos);

        if(pairAtPos.first == currentSelection)
        {
            return pairAtPos.second;
        }
    }
    return -1;
}

double Chooser::GetSelectedKey()
{
    std::string currentSelection = m_chooser.GetSelected();
    return GetSelectedKey(currentSelection);
}