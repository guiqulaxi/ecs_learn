#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H
#include "EntityFu.h"
#include <vector>
#include "matrix/math.hpp"
#include "const_value.h"
class CollisionComponent : public Entity::Component
{
public:
    CollisionComponent():size(empty_value,empty_value){}
    virtual bool empty() const{return matrix::Vector2i(empty_value,empty_value)==size; }
    CollisionComponent(int width,int height):size(width,height){}
    matrix::Vector2i size;//宽高
    //与它碰撞的entity
    std::vector<Eid> hitEids;
    static Cid cid;
};

#endif // COLLISIONCOMPONENT_H
