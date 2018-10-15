#pragma once

#include <iostream>
#include "ISubject.h"
#include "IComponent.h"
#include "IEditor.h"


class B: public ISubject,
        public IComponent,
        public IEditor
{
public:
    B(std::string name="component",
            std::string data="data",
            IObserver* observer= nullptr)
            :
            IComponent(name),
            IEditor(data, observer)
            {}
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
    void edit(std::string data) override{
        _data = data;
        std::cout<<"B.edit data="<<data<<std::endl;
        _observer->notify(IObserver::EventType::Update, data);
    }
};
