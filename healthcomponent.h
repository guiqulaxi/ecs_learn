#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H
#include "EntityFu.h"

class HealthComponent : public Entity::Component
{
public:

    HealthComponent(int _hp, int _maxHP):hp(_hp),maxHP(_maxHP)
    {

    }

    HealthComponent() : HealthComponent(0, 0) {}

    virtual bool empty() const {return maxHP == 0;}

    static Cid cid;
    int hp;
    int maxHP;
};

#endif // TANKCOMPONENT_H
