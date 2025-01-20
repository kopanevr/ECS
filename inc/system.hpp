#pragma once

#include "EntityManager.hpp"

class System
{
private:

public:
    System() = default;
    virtual ~System() = default;

    virtual void update(EntityManager& entityManager) = 0;
};
