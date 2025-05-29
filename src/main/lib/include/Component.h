#pragma once
#include <functional>
#include <vector>
#include <iostream>
class Component
{
public:
    Component();

    /**
     * Contains references to all created components
     */
    static std::vector<Component*> AllCreatedComponents; 
    
    /**
     * Component specific callback that runs before the simulink step function
     */
    virtual void PreStepCallback() = 0;

    /**
     * Component specific callback that runs after the simulink step function
     */
    virtual void PostStepCallback() = 0;

    /**
     * Component specific callback that pushes data to smart dashboard
     */
    virtual void SmartDashboardCallback() = 0;

    /**
     * Component specific callback that is called when the gamestate changes
     */
    virtual void GameStateChangeCallback() = 0;
};