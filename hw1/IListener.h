#pragma once
// Интерфейс для класса A, необходим в Observer
class IListener
{
public:
    virtual void update() = 0;
};