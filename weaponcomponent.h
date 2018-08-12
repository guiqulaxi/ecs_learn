#ifndef WEAPONCOMPONENT_H
#define WEAPONCOMPONENT_H
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
#include <set>
#include <vector>
#include <QtCore>

class WeaponComponent : public Entity::Component
{
public:

    WeaponComponent():
        vehicleId(empty_value),
        direction(empty_value,empty_value){

    }
    WeaponComponent(Eid _vehicleId,const std::set<Cid> &_ammunitionType):
        vehicleId(_vehicleId),
        ammunitionType(_ammunitionType),
        direction(empty_value,empty_value){}
    WeaponComponent(Eid _vehicleId, matrix::Vector2i& _direction,const std::set<Cid> &_ammunitionType):
        vehicleId(_vehicleId),
        ammunitionType(_ammunitionType),
        direction(_direction){}
    virtual bool empty() const{ return matrix::Vector2i(empty_value,empty_value)==direction;}
    Eid vehicleId;//
    std::set<Cid> ammunitionType;//弹药种类，shell
    std::vector<Cid> toBeFiredAmmunition;//待发射的弹药
    matrix::Vector2i direction;//射击方向
    static Cid cid;
};

#endif // WEAPONCOMPONENT_H
