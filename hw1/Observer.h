#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include "IManager.h"
#include "IObserver.h"
#include "C.h"


// IManager (C наследует этот интерфейс)
// IObserver (A наследуют этот интерфейс)
template <>
class C<Observer>: public IManager {
public:
    void notify(EventType eventType, std::string event) override
    {
        std::cout << "Manager.notify" << std::endl;
        for (auto it=_subscribers.equal_range(eventType).first;
            it != _subscribers.equal_range(eventType).second;
            ++it)
        {
            it->second->update(event);
        }
    }
    void subscribe(EventType eventType, IObserver* subscriber) override{
        _subscribers.insert(std::pair<IManager::EventType, IObserver*>(eventType, subscriber));
        std::cout<<"Add new subscriber eventType="<<eventType<<std::endl;
    }
    void unsubscribe(EventType eventType, IObserver* subscriber) override{
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
    std::multimap<IManager::EventType, IObserver*> _subscribers;
};


