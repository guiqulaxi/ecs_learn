#include "movesystem.h"
#include "movecomponent.h"
#include "positioncomponent.h"
#include "tankcomponent.h"
#include "ammunitioncomponent.h"
#include "fuelcomponent.h"

#include <iostream>
MoveSystem::MoveSystem()
{

}
void MoveSystem::tick(double fixedDelta){
    auto allEid = Entity::getAll<MoveComponent>();

    for(auto eid :allEid){
        MoveComponent &moveComponent=Entity::get<MoveComponent>(eid);
        PositionComponent &posComponent=Entity::get<PositionComponent>(eid);
        FuelComponent &fuelComponent =Entity::get<FuelComponent>(eid);
        //如果不移动或者没有对应PositionComponent组件
        if(moveComponent.empty()||posComponent.empty()){
            continue;
        }
        else{
            //记录前一个位置
            posComponent.prePosition=posComponent.position;
            //若燃料不够
            if(fuelComponent.range<moveComponent.velocity.norm()){
                posComponent.position+=moveComponent.velocity.normalized()*fuelComponent.range;
                fuelComponent.range=0;
            }
            else{
                posComponent.position=posComponent.position+moveComponent.velocity;
                fuelComponent.range-=moveComponent.velocity.norm();
            }



        }
        if(!Entity::get<TankComponent>(eid).empty())//坦克每次移动后就静止
        {
            moveComponent.velocity=matrix::Vector2i(empty_value,empty_value);
        }

        std::cout << "Entity " << eid << " position (" <<posComponent.position.data()[0] << "," << posComponent.position.data()[1] <<")"<< std::endl;


    }
}
