#ifndef DAMAGESYSTEM_H
#define DAMAGESYSTEM_H
#include "EntityFu.h"

class DamageSystem : public System
{
public:
    DamageSystem();
    //遍历具有碰撞组件且是炮弹的实体
    //遍历每个炮弹的实体的hitEids
    //将他们的hp减去炮弹的伤害
    //令炮弹的hp为0;
    static void tick(double fixedDelta);
};

#endif // DAMAGESYSTEM_H
