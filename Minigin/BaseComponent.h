#pragma once
#include <cassert>

namespace dae
{
    class GameObject;

    class BaseComponent
    {
    public:
        virtual ~BaseComponent() = default;

        BaseComponent(const BaseComponent& other) = delete;
        BaseComponent(BaseComponent&& other) = delete;
        BaseComponent& operator=(const BaseComponent& other) = delete;
        BaseComponent& operator=(BaseComponent&& other) = delete;

        virtual void Update(float delta_time) = 0;
        virtual void Render() const = 0;

    protected:
        explicit BaseComponent(GameObject* pOwner) : m_pOwner(pOwner) {};
        GameObject* GetOwner() const { return m_pOwner; };
    private:
        GameObject* m_pOwner{ nullptr };
    };
}
