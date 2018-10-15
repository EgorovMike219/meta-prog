#pragma once

#include <iostream>
#include "ICaller.h"
#include "IComponent.h"


class A: public ICaller, public IComponent
{
public:
    A(std::string name="component"):IComponent(name) {}
    void act() override {
        std::cout<<"A.act name="<<_name<<std::endl;
    }
    void call(std::string event)
    {
        std::cout<<"A.call event=" <<event<<std::endl;
        if (_mediator)
        {
            _mediator->notify(this, event);
        }
    }
    void call(ISubject* b) override {
        std::cout<<"A.call"<<std::endl;
        b->doSomething();
    }
};