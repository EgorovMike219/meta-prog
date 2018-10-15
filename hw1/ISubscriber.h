#pragma once
// Интерфейс для класса A
#include <string>

class ISubscriber
{
public:
    virtual void update(std::string) = 0;
};