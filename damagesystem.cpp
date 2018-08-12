#include "damagesystem.h"
#include "ammunitioncomponent.h"
#include "hitcomponent.h"
#include "healthcomponent.h"
#include <QDebug>
DamageSystem::DamageSystem()
{

}

void DamageSystem::tick(double fixedDelta)
{
    //获得所有的HitComponent的Eid
    auto eids=Entity::getAll<HitComponent>();
    for(auto  eid : eids){
        HitComponent& hitComponent=Entity::get<HitComponent>(eid);
        AmmunitionComponent& ammunitionComponent=Entity::get<AmmunitionComponent>(eid);
        for(auto tankid :hitComponent.hitEids){
            HealthComponent& healthComponent=Entity::get<HealthComponent>(tankid);
            healthComponent.hp-=ammunitionComponent.power;
            qDebug()<<tankid<<"剩余血量:"<<healthComponent.hp;
        }
        //炮弹被引爆把hp设置为0
        if(AmmunitionState::detonated== ammunitionComponent.state){
            HealthComponent& healthComponent=Entity::get<HealthComponent>(eid);
            healthComponent.hp=0;

        }
    }

}
