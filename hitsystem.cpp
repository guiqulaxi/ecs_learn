#include "hitsystem.h"
#include "hitcomponent.h"
#include "positioncomponent.h"
#include "ammunitioncomponent.h"
#include "tankcomponent.h"
#include "matrix/math.hpp"
bool isHited(Eid ammunitionId,Eid tankId){

    PositionComponent &tankPos=Entity::get<PositionComponent>(tankId);
    PositionComponent &ammunitionPos=Entity::get<PositionComponent>(ammunitionId);
    AmmunitionComponent &ammunitionComponent=Entity::get<AmmunitionComponent>(ammunitionId);
    int a=ammunitionPos.position.data()[0]-tankPos.position.data()[0];
    int b=ammunitionPos.position.data()[1]-tankPos.position.data()[1];
    if(a*a+b*b<=ammunitionComponent.lethalRadius*ammunitionComponent.lethalRadius){ //在杀伤半径内
            return true;
    }else{
           return false;
    }
}
HitSystem::HitSystem()
{

}
void HitSystem::tick(double fixedDelta){
    auto allEids = Entity::getAll<HitComponent>();
    for(auto eid :allEids){
       HitComponent &hitComponent=Entity::get<HitComponent>(eid);
       PositionComponent &positionComponent=Entity::get<PositionComponent>(eid);
       AmmunitionComponent &ammunitionComponent=Entity::get<AmmunitionComponent>(eid);
       if(positionComponent.position==hitComponent.destination){
           qDebug()<<"炮弹"<eid<<"到达目标地点，准备引爆";
           ammunitionComponent.state=AmmunitionState::detonated;
           //计算命中的目标
           auto tankEids = Entity::getAll<TankComponent>();
           for(auto tankId :tankEids){
               if(isHited(eid,tankId)){
                    hitComponent.hitEids.push_back(tankId);
                    qDebug()<<eid<<"命中"<<tankId;
               }
           }
       }


    }
}
