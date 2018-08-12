#ifndef FIRESYSTEM_H
#define FIRESYSTEM_H
#include "EntityFu.h"

class FireSystem : public System
{
public:
    FireSystem();
    static void tick(double fixedDelta);
};

#endif // FIRESYSTEM_H
