#pragma once
// интерфейс Наблюдателя для класса C
#include <string>
#include "IObserver.h"


class IManager
{
public:
    enum EventType
    {
        Update
    };
    virtual void notify(EventType, std::string event) = 0;
    virtual void subscribe(EventType, IObserver*) = 0;
    virtual void unsubscribe(EventType, IObserver*) = 0;
};