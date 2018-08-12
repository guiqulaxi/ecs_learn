#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include "EntityFu.h"
#include <QtCore>
class InputComponent : public Entity::Component
{
public:
    InputComponent():key(Qt::Key_unknown){}

    int key;
    virtual bool empty() const{return Qt::Key_unknown==key;}
    static Cid cid;
};

#endif // INPUTCOMPONENT_H
