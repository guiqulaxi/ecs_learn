#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H
#include "EntityFu.h"
#include "collisioncomponent.h"
#include "positioncomponent.h"

class CollisionSystem : public System
{
public:
    CollisionSystem();
    static void tick(double fixedDelta);
};

#endif // COLLISIONSYSTEM_H
