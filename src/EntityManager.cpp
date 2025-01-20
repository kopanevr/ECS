#include "EntityManager.hpp"

#include <algorithm>
#include <utility>

EntityManager* EntityManager::getInstance()
{
    static EntityManager sInstance;

    return &sInstance;
}

EntityId EntityManager::createEntity()
{
    EntityId entity = m_nextEntityId++;

    m_entities.push_back(entity);

    return entity;
}

void EntityManager::destroyEntity(EntityId id)
{
    if (m_components.find(id) != m_components.end())
    {
        m_components.erase(id);
    }

    std::vector<EntityId>::iterator it = std::find(m_entities.begin(), m_entities.end(), id);

    if (it != m_entities.end())
    {
        m_entities.erase(it);
    }
}

template<typename T>
void EntityManager::addComponent(EntityId id, std::unique_ptr<T> component)
{
    m_components[id].push_back(std::move(component));
}

template<typename T>
T* EntityManager::getComponent(EntityId id)
{
    if (m_components.find(id) == m_components.end())
    {
        return nullptr;
    }

    for (std::unique_ptr<Component>& component : m_components[id])
    {
        if (T* castedComponent = dynamic_cast<T*>(component.get()))
        {
            return castedComponent;
        }
    }

    return nullptr;
}

template<typename T>
bool EntityManager::hasComponent(EntityId id)
{
    if (m_components.find(id) == m_components.end())
    {
        return false;
    }

    for (std::unique_ptr<Component>& component : m_components[id])
    {
        if (dynamic_cast<T*>(component.get()) != nullptr)
        {
            return true;
        }
    }

    return false;
}
