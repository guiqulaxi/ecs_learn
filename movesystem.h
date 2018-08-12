#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H
#include "EntityFu.h"
#include <QObject>
class MoveSystem : public System
{

public:
    MoveSystem();
    static void tick(double fixedDelta);


};

#endif // MOVESYSTEM_H
