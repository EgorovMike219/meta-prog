#include <utility>

#include <utility>

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
    explicit B(std::string name="component",
            std::string data="data",
            IManager* observer= nullptr)
            :
            IComponent(std::move(name)),
            IEditor(std::move(data), observer)
            {}
    void act() override {
        std::cout<<"B.act name="<<_name<<std::endl;
    }
    void call(const std::string &event)
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
        _observer->notify(IManager::EventType::Update, data);
    }
};
