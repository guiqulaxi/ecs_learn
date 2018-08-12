#include "fuelsystem.h"
#include "fuelcomponent.h"
#include "movecomponent.h"
#include <iostream>
FuelSystem::FuelSystem()
{

}
void FuelSystem::tick(double fixedDelta){
    auto allEid = Entity::getAll<FuelComponent>();
    for(auto eid :allEid){
        FuelComponent &fuelComponent=Entity::get<FuelComponent>(eid);
        if(fuelComponent.range<=0){
            std::cout << "Entity " << eid << "uses up all its fuel"<< std::endl;
            Entity::removeComponent<MoveComponent>(eid);
        }
    }
}
