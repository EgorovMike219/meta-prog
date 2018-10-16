#include <utility>

#pragma once

#include <iostream>
#include "ICaller.h"
#include "IComponent.h"
#include "ISubscriber.h"


class A: public ICaller, public IComponent, public ISubscriber
{
public:
    explicit A(std::string name="component"):IComponent(std::move(name)) {}
    void act() override {
        std::cout<<"A.act name="<<_name<<std::endl;
    }
    void call(const std::string &event)
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
    void update(std::string event) override {
        std::cout<<"A.update event="<<event<<std::endl;
    }
};