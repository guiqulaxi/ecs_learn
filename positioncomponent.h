#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
#include <QDebug>
class PositionComponent : public Entity::Component
{
public:
    PositionComponent(int x,int y):position(x,y),prePosition(empty_value,empty_value){}
    PositionComponent(const matrix::Vector2i &_position):position(_position),prePosition(empty_value,empty_value){}
    PositionComponent():position(empty_value,empty_value),prePosition(empty_value,empty_value){}
    virtual bool empty() const {
        return matrix::Vector2i(empty_value,empty_value)==position;
    }
    matrix::Vector2i position;//物体的位置 ，左上角
    matrix::Vector2i prePosition;//物体的前一个位置 ，左上角
    static Cid cid;
};

#endif // POSITIONCOMPONENT_H
