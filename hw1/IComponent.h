#include <utility>

#pragma once
// интерфейс компоненты в паттерне Медиатор для классов A, B
#include <memory>
#include <string>
#include "IMediator.h"


class IComponent : public IComponentBase
        {
public:
    explicit IComponent(std::string name)
    {
        _name = std::move(name);
    }
    void setMediator(IMediator* mediator)
    {
        _mediator =
                std::shared_ptr<IMediator>(mediator);
    }
    void act() override = 0;
protected:
    std::shared_ptr<IMediator> _mediator;
    std::string _name;
};


