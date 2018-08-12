#include "inputsystem.h"
#include "globalapplication.h"
#include "inputcomponent.h"
#include "movecomponent.h"
#include "weaponcomponent.h"
#include "ammunitioncomponent.h"
#include "positioncomponent.h"
#include "EntityFu.h"
#include "matrix/math.hpp"
#include "const_value.h"
#include <QDebug>

void InputSystem::tick(double fixedDelta){
    GlobalApplication* app=dynamic_cast<GlobalApplication*>(QApplication::instance());
    int pressedMoveKey=Qt::Key_unknown;
    if(nullptr!=app)
    {
        pressedMoveKey=app->getOneKey();
    }

    if(Qt::Key_unknown==pressedMoveKey){
        return;
    }
    auto all_eid = Entity::getAll<InputComponent>();
    for (auto eid : all_eid)
    {
        MoveComponent &moveComponent=Entity::get<MoveComponent>(eid);
        PositionComponent &positionComponent=Entity::get<PositionComponent>(eid);
        WeaponComponent &weaponComponent=Entity::get<WeaponComponent>(eid);
        switch (pressedMoveKey) {
        case Qt::Key_Space:{
            if(!weaponComponent.empty()){//发射炮弹
                //子弹上膛
                weaponComponent.toBeFiredAmmunition.push_back(AmmunitionComponent::cid);
            }

            break;
        }
        case Qt::Key_Up:{
            moveComponent.velocity=matrix::Vector2i(0,-10);

            break;
        }
        case Qt::Key_Down:{
            moveComponent.velocity=matrix::Vector2i(0,10);

            break;
        }
        case Qt::Key_Left:{
            moveComponent.velocity=matrix::Vector2i(-10,0);

            break;
        }
        case  Qt::Key_Right:{
            moveComponent.velocity=matrix::Vector2i(10,0);
            break;
        }
        default:
            moveComponent.velocity=matrix::Vector2i(empty_value,empty_value);
            break;
        }

    }


}
