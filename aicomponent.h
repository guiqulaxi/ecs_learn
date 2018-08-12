#ifndef AICOMPONENT_H
#define AICOMPONENT_H
#include "EntityFu.h"

class AIComponent : public Entity::Component
{
public:
    AIComponent();
    virtual bool empty() const{return false;}
    static Cid cid;
};


#endif // AICOMPONENT_H
