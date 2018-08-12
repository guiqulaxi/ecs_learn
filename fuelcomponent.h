#ifndef FUELCOMPONENT_H
#define FUELCOMPONENT_H

#include "EntityFu.h"
#include "const_value.h"
class FuelComponent : public Entity::Component
{
public:
    FuelComponent():range(empty_value){}
    FuelComponent(int _range):range(_range){}
    virtual bool empty() const{
        return range==empty_value;
    }
    static Cid cid;
    int range;//燃料的航程
};

#endif // FUELCOMPONENT_H
