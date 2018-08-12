#ifndef DESTROYSYSTEM_H
#define DESTROYSYSTEM_H
#include "EntityFu.h"

class DestroySystem : public System
{
public:
    DestroySystem();
    //把所有hp<=0的实体剔除
    static void tick(double fixedDelta);
};

#endif // DESTROYSYSTEM_H
