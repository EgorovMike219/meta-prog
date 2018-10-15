#pragma once
// Нужен чтобы  не было циклической зависимости IComponent и   IMediator


class IComponentBase
{
public:
    virtual ~IComponentBase() {}

    virtual void act() = 0;
};
