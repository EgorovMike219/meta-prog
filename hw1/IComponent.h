#pragma once
// интерфейс компоненты в паттерне Медиатор для классов A, B
#include <memory>
#include <string>
#include "IMediator.h"


class IComponent : public IComponentBase
        {
public:
    IComponent(std::string name)
    {
        _name = name;
    }
    void setMediator(IMediator* mediator)
    {
        _mediator =
                std::shared_ptr<IMediator>(mediator);
    }
    virtual void act() = 0;
protected:
    std::shared_ptr<IMediator> _mediator;
    std::string _name;
};


