#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include "IObserver.h"
#include "ISubscriber.h"
#include "C.h"


// IObserver (C наследует этот интерфейс)
// ISubscriber (A наследуют этот интерфейс)
template <>
class C<Observer>: public IObserver {
public:
    void notify(EventType eventType, std::string event) override
    {
        std::cout << "Observer.notify" << std::endl;
        for (auto it=_subscribers.equal_range(eventType).first;
            it != _subscribers.equal_range(eventType).second;
            ++it)
        {
            it->second->update(event);
        }
    }
    void subscribe(EventType eventType, ISubscriber* subscriber) override{
        _subscribers.insert(std::pair<IObserver::EventType, ISubscriber*>(eventType, subscriber));
        std::cout<<"Add new subscriber eventType="<<eventType<<std::endl;
    }
    void unsubscribe(EventType eventType, ISubscriber* subscriber) override{
        for (auto it=_subscribers.equal_range(eventType).first;
             it != _subscribers.equal_range(eventType).second;
             ++it)
        {
            if(it->second == subscriber)
            {
                _subscribers.erase(it);
                break;
            }
        }
        std::cout<<"Delete subscriber eventType="<<eventType<<std::endl;
    }
private:
    std::multimap<IObserver::EventType, ISubscriber*> _subscribers;
};


