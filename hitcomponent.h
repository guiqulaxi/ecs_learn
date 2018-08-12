#ifndef HITCOMPONENT_H
#define HITCOMPONENT_H
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
//炮弹打击
class HitComponent : public Entity::Component
{
public:
    matrix::Vector2i destination;
    HitComponent():destination(empty_value,empty_value){}
    std::vector<Eid> hitEids;//命中的实体
    HitComponent(const matrix::Vector2i &_destination):destination(_destination){}
    virtual bool empty() const{
        return destination==matrix::Vector2i(empty_value,empty_value);
    }
    static Cid cid;
};

#endif // HITCOMPONENT_H
