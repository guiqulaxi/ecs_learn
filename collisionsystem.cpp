#include "collisionsystem.h"
#include "collisioncomponent.h"
#include<math.h>
#include<vector>
CollisionSystem::CollisionSystem()
{

}
bool isRectIntersect(int x01, int x02, int y01, int y02,
    int x11, int x12, int y11, int y12)
{
    int zx = abs(x01 + x02 -x11 - x12);
    int x  = abs(x01 - x02) + abs(x11 - x12);
    int zy = abs(y01 + y02 - y11 - y12);
    int y  = abs(y01 - y02) + abs(y11 - y12);
    if(zx <= x && zy <= y)
        return true;
    else
        return false;
}
void CollisionSystem::tick(double fixedDelta){
   auto entities=Entity::getAll<CollisionComponent>();
    for(int i=0;i<entities.size();i++){

        for(int j=i+1;j<entities.size();j++){

//            CollisionComponent &aSize=Entity::get<CollisionComponent>(entities[i]);
//            PositionComponent &aPos=Entity::get<PositionComponent>(entities[i]);
//            CollisionComponent &bSize=Entity::get<CollisionComponent>(entities[j]);
//            PositionComponent &bPos=Entity::get<PositionComponent>(entities[j]);
//            //判断是否相交
//            int a_x1=get_x(aPos.position);
//            int a_y1=get_y(aPos.position);
//            int a_x2=get_x(aPos.position)+get_width(aSize.size);
//            int a_y2=get_y(aPos.position)+get_height(aSize.size);
//            int b_x1=get_x(bPos.position);
//            int b_y1=get_y(bPos.position);
//            int b_x2=get_x(bPos.position)+get_width(bSize.size);
//            int b_y2=get_y(bPos.position)+get_height(bSize.size);

//            if(isRectIntersect(a_x1,a_x2,a_y1,a_y2,b_x1,b_x2,b_y1,b_y2)){
//                //相交则把Entity相互加入对方的hitEntities
//               aSize.hitEids.push_back(entities[j]);
//               bSize.hitEids.push_back(entities[i]);
//            }
        }

    }

}
