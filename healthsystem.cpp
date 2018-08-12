#include "healthsystem.h"
#include "healthcomponent.h"
#include <iostream>

void HealthSystem::tick(double fixedDelta)
    {
        // create a copy of the vector<Eid> for all health components so we
        // don't cause an assertion failure: "vector iterator not incrementable"
        // for more speed you can instead loop over a reference as long as you schedule
        // Entity::destroyNow for after the loop
        auto all = Entity::getAll<HealthComponent>();

        // for this example, just decrement all health components each tick
        for (auto eid : all)
        {

            HealthComponent &healthComponent=Entity::get<HealthComponent>(eid);

            // this is overly pragmatic, but you get the drift of how to check if a component is valid
            if (healthComponent.empty())
                continue;

            // decrement
            healthComponent.hp--;
            if (healthComponent.hp < 0)
                healthComponent.hp = 0;
            std::cout << "Entity " << eid << " has " << healthComponent.hp << "/" << healthComponent.maxHP << " hit points." << std::endl;

            // destroy entity if zero health
            if (healthComponent.hp <= 0)
                Entity::destroyNow(eid);
        }
    }
