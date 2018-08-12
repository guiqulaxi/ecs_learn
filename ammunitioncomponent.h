#ifndef SHELLWEAPONCOMPONENT_H
#define SHELLWEAPONCOMPONENT_H
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
#include <vector>
enum class AmmunitionState{
    loaded,//被装填
    moving,//被射出
    detonated,//被触发
    unkown//未知
};
class AmmunitionComponent : public Entity::Component
{
public:
    Eid shooterEid; //发射者的Eid
    int maxVelocity;//最大速度
    int power;//伤害
    int lethalRadius;//杀伤半径
    AmmunitionState state;//弹药状态
    AmmunitionComponent():shooterEid(0),maxVelocity(empty_value),power(empty_value),lethalRadius(empty_value){}
    AmmunitionComponent(Eid _shooterEid,int _maxVelocity,int _power,int _lethalRadius)
        :shooterEid(_shooterEid)
        ,maxVelocity(_maxVelocity)
        ,power(_power)
        ,lethalRadius(_lethalRadius)
        ,state(AmmunitionState::loaded){}
    AmmunitionComponent(Eid _shooterEid,int _maxVelocity,int _power,int _lethalRadius,AmmunitionState _state)
        :shooterEid(_shooterEid)
        ,maxVelocity(_maxVelocity)
        ,power(_power)
        ,lethalRadius(_lethalRadius)
        ,state(_state){}

    virtual bool empty() const{return empty_value==power||empty_value==maxVelocity;}
    static Cid cid;
};

#endif // SHELLWEAPONCOMPONENT_H
