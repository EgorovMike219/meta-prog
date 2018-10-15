#pragma once

#include <iostream>
#include "ISubject.h"
#include "IComponent.h"

class B: public ISubject, public IComponent
{
public:
    B(std::string name="component"):IComponent(name) {}
    void act() override {
        std::cout<<"B.act name="<<_name<<std::endl;
    }
    void call(std::string event)
    {
        std::cout<<"B.call event=" <<event<<std::endl;
        if (_mediator)
        {
            _mediator->notify(this, event);
        }
    }
    void doSomething() override {
        std::cout<<"B.doSomething"<<std::endl;
    }
};
