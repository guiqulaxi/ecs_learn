#include "mainwindow.h"
#include <QApplication>

#include "EntityFu.h"
#include "movecomponent.h"
#include "positioncomponent.h"
#include "movesystem.h"
#include "healthcomponent.h"
#include "inputcomponent.h"
#include "inputsystem.h"
#include "weaponcomponent.h"
#include "globalapplication.h"
#include "inputcomponent.h"
#include "weaponcomponent.h"
#include "ammunitioncomponent.h"
#include "tankcomponent.h"
#include "collisioncomponent.h"
#include "collisionsystem.h"
#include "damagesystem.h"
#include "destroysystem.h"
#include "fuelcomponent.h"
#include "fuelsystem.h"
#include "weaponsystem.h"
#include "firesystem.h"
#include "hitcomponent.h"
#include "hitsystem.h"
#include <iostream>
#include <QtConcurrent>
#include <set>
#ifdef _WIN32
#include <windows.h>
#define _sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define _sleep(ms) usleep(ms * 1000)
#endif

//控制static变量初始化顺序
Cid Entity::Component::numCids=0;

Cid MoveComponent::cid=Entity::Component::numCids++;
Cid PositionComponent::cid=Entity::Component::numCids++;
Cid HealthComponent::cid=Entity::Component::numCids++;
Cid InputComponent::cid=Entity::Component::numCids++;
Cid WeaponComponent::cid=Entity::Component::numCids++;
Cid AmmunitionComponent::cid=Entity::Component::numCids++;

Cid TankComponent::cid=Entity::Component::numCids++;
//Cid AIComponent::cid=AIComponent::numCids++;
Cid CollisionComponent::cid=Entity::Component::numCids++;

Cid FuelComponent::cid=Entity::Component::numCids++;
Cid HitComponent::cid=Entity::Component::numCids++;


void init(){

    Eid eid1=Entity::create();
    Entity::addComponents(eid1,
                           new TankComponent(0)
                          ,new MoveComponent()
                          ,new PositionComponent(0,0)
                          ,new HealthComponent(100,100)
                          ,new FuelComponent(10000)
                          ,new InputComponent()
                          ,new WeaponComponent(eid1,std::set<Cid>{TankComponent::cid}));
    Eid eid2=Entity::create();
    Entity::addComponents(eid2,
                           new TankComponent(0)
                          ,new MoveComponent()
                          ,new PositionComponent(510,0)
                          ,new HealthComponent(100,100)
                          );
    Eid eid3=Entity::create();
    Entity::addComponents(eid3,
                           new TankComponent(0)
                          ,new MoveComponent()
                          ,new PositionComponent(520,0)
                          ,new HealthComponent(100,100)
                          );
}
void f(){
    while (Entity::count())
    {
        InputSystem::tick(0.1);
        WeaponSystem::tick(0.1);
        FireSystem::tick(0.1);
        MoveSystem::tick(0.1);
        FuelSystem::tick(0.1);
        HitSystem::tick(0.1);
        DamageSystem::tick(0.1);
        DestroySystem::tick(0.1);
        auto tankEids = Entity::getAll<TankComponent>();
        _sleep(100);
    }
}
int main(int argc, char *argv[])
{



    GlobalApplication a(argc, argv);

    MainWindow w;
    w.show();
    init();

    QFuture<void> fut = QtConcurrent::run(f);



    return a.exec();

    //fut.waitForFinished();
}
