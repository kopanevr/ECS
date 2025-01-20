#include "Entity.hpp"
#include "EntityManager.hpp"

void loop();

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv)
{
    EntityManager* gpEntityManager = EntityManager::getInstance();

    EntityId entityId = gpEntityManager->createEntity();

    //

    // ОСНОВНОЙ ЦИКЛ
    loop();

    return 0;
}

void loop()
{
    while(1)
    {}
}
