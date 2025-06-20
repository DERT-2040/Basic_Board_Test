#pragma once
#include <functional>
#include <vector>
#include <iostream>
class Component
{
public:
    Component();

    /** Contains references to all created components */
    static std::vector<Component*> AllCreatedComponents; 
    
    /** Component specific callback that runs before the simulink step function */
    virtual void PreStepCallback() = 0;

    /** Component specific callback that runs after the simulink step function */
    virtual void PostStepCallback() = 0;
};