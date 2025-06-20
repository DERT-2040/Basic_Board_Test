#include "lib/include/Component.h"

std::vector<Component*> Component::AllCreatedComponents; 

Component::Component()
{
    AllCreatedComponents.push_back(this);
}   