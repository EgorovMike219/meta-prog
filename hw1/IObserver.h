#pragma once
// интерфейс Наблюдателя для класса C
#include <string>
#include "ISubscriber.h"


class IObserver
{
public:
    enum EventType
    {
        Update
    };
    virtual void notify(EventType, std::string event) = 0;
    virtual void subscribe(EventType, ISubscriber*) = 0;
    virtual void unsubscribe(EventType, ISubscriber*) = 0;
};