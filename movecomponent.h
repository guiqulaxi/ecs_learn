#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
#include <QtCore>

class MoveComponent : public  Entity::Component
{
public:

    MoveComponent():velocity(empty_value,empty_value){

    }

    MoveComponent(const matrix::Vector2i& velocity):velocity(velocity){

    }

    virtual bool empty() const{
        return velocity==matrix::Vector2i(empty_value,empty_value);
    }
    static Cid cid;
    matrix::Vector2i velocity;//速度,蕴含方向

};


#endif // MOVECOMPONENT_H
