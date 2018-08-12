#include "firesystem.h"
#include "weaponcomponent.h"
#include "movecomponent.h"
#include "positioncomponent.h"
#include "collisioncomponent.h"
#include "healthcomponent.h"
#include "fuelcomponent.h"
#include "ammunitioncomponent.h"
#include "hitcomponent.h"
FireSystem::FireSystem()
{

}

void FireSystem::tick(double fixedDelta)
{
    auto all_eid = Entity::getAll<WeaponComponent>();
    for (auto eid : all_eid)
    {
         WeaponComponent &weaponComponent =  Entity::get<WeaponComponent>(eid);
         for (auto cid : weaponComponent.toBeFiredAmmunition){

             PositionComponent &positionComponent=Entity::get<PositionComponent>(weaponComponent.vehicleId);
             Eid ammunitionId=Entity::create();
             Entity::addComponents(ammunitionId
                                   ,new MoveComponent(weaponComponent.direction*100)
                                   ,new PositionComponent(positionComponent.position)
                                   ,new HealthComponent(10,10)
                                   ,new FuelComponent(1000)
                                   ,new HitComponent(matrix::Vector2i(510,0))
                                   ,new AmmunitionComponent(eid,100,100,100,AmmunitionState::moving)
                                   );
           qDebug()<<"Entity"<<eid<<"发射炮弹"<<ammunitionId;
         }

         weaponComponent.toBeFiredAmmunition.clear();
    }
}
