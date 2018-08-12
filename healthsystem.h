#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H
#include "EntityFu.h"

class HealthSystem : public System
{
public:
    HealthSystem(){}
    static void tick(double fixedDelta);
};

#endif // HEALTHSYSTEM_H
