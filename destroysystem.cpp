#include "destroysystem.h"
#include "healthcomponent.h"
#include "movecomponent.h"
#include "collisioncomponent.h"
#include "positioncomponent.h"
#include "healthcomponent.h"
#include "ammunitioncomponent.h"
#include "tankcomponent.h"
#include "weaponcomponent.h"
#include "inputcomponent.h"
#include "hitcomponent.h"
DestroySystem::DestroySystem()
{

}
void DestroySystem::tick(double fixedDelta){
     auto eids=Entity::getAll<HealthComponent>();
     for(auto eid : eids){
         if(Entity::get<HealthComponent>(eid).hp<=0){

            //移除hp<=0的实体
            Entity::removeComponent<MoveComponent>(eid);
            Entity::removeComponent<PositionComponent>(eid);
            Entity::removeComponent<CollisionComponent>(eid);
            Entity::removeComponent<HealthComponent>(eid);
            Entity::removeComponent<TankComponent>(eid);
            Entity::removeComponent<AmmunitionComponent>(eid);
            Entity::removeComponent<TankComponent>(eid);
            Entity::removeComponent<WeaponComponent>(eid);
            Entity::removeComponent<InputComponent>(eid);
            Entity::removeComponent<HitComponent>(eid);
            qDebug()<<"移除"<<eid;
         }
     }
}
