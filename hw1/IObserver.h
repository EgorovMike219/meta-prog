#pragma once
// Интерфейс для класса A
#include <string>

class IObserver
{
public:
    virtual void update(std::string) = 0;
};