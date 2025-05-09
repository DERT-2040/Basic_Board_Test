#include "lib/include/Component.h"

std::vector<Component*> Component::AllCreatedComponents; 

Component::Component()
{
    AllCreatedComponents.push_back(this);
}

void Component::PreStepCallback()
{
    std::cout << "Pre Step Callback Undefined Virtural";
}

void Component::PostStepCallback()
{
    std::cout << "Post Step Callback Undefined Virtural";
}

void Component::SmartDashboardCallback()
{
    std::cout << "Smart Dashboard Callback Undefined Virtural";
}

void Component::GameStateChangeCallback()
{
    std::cout << "Game State Change Callback Undefined Virtural";
}