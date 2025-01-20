#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

#include "entity.hpp"
#include "component.hpp"

class EntityManager final
{
private:
    std::vector<EntityId> m_entities;
    std::unordered_map<EntityId, std::vector<std::unique_ptr<Component>>> m_components;

    EntityId m_nextEntityId = 0U;

    EntityManager() = default;

    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;
public:
    ~EntityManager() = default;

    static EntityManager* getInstance();

    EntityId createEntity();
    void destroyEntity(EntityId id);

    template<typename T>
    void addComponent(EntityId id, std::unique_ptr<T> component);
    template<typename T>
    T* getComponent(EntityId id);
    template<typename T>
    bool hasComponent(EntityId id);

    const std::vector<EntityId>& getEntity() const
    {
        return m_entities;
    }
};
