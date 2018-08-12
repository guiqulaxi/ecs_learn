#ifndef TANKCOMPONENT_H
#define TANKCOMPONENT_H
#include "EntityFu.h"
#include "const_value.h"
class TankComponent : public Entity::Component
{
public:
    TankComponent():side(empty_value){}
    TankComponent(int _side):side(_side){}
    virtual bool empty() const {return empty_value==side;}
    int side;
    static Cid cid;
};

#endif // TANKCOMPONENT_H
