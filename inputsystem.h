#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#include "EntityFu.h"
#include <QApplication>
class InputSystem : public System
{
public:
    InputSystem(){}

    static void tick(double fixedDelta);


};

#endif // INPUTSYSTEM_H
