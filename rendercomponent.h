#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <QObject>
#include "EntityFu.h"
class RenderComponent : public Entity::Component
{
public:
    RenderComponent();
    virtual bool empty() const{return false;}
    static Cid cid;
};

#endif // RENDERCOMPONENT_H
