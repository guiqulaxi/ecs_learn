#ifndef WEAPONSYSTEM_H
#define WEAPONSYSTEM_H

#include "EntityFu.h"

class WeaponSystem : public System
{
public:
    WeaponSystem(){}

    static void tick(double fixedDelta);


};
#endif // WEAPONSYSTEM_H
