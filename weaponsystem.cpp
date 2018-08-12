#include "weaponsystem.h"
#include "movecomponent.h"
#include "weaponcomponent.h"

 void WeaponSystem::tick(double fixedDelta){
    auto all_eid = Entity::getAll<WeaponComponent>();
    for (auto eid : all_eid)
    {
        MoveComponent &moveComponent=Entity::get<MoveComponent>(eid);
        WeaponComponent &weaponComponent=Entity::get<WeaponComponent>(eid);
        if(moveComponent.empty()) continue;
        matrix::Vector2f direction(moveComponent.velocity.data()[0],moveComponent.velocity.data()[1]);
        direction=direction.normalized();
        weaponComponent.direction.data()[0]=(int)direction.data()[0];
        weaponComponent.direction.data()[1]=(int)direction.data()[1];
    }
}
