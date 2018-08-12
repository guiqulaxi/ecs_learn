#ifndef HITSYSTEM_H
#define HITSYSTEM_H

#include "EntityFu.h"
class HitSystem : public System
{
public:
    HitSystem();
    static void tick(double fixedDelta);
};

#endif // HITSYSTEM_H
