#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include "IComponentBase.h"
#include "C.h"


// InterfaceMediator (C наследует этот интерфейс)
// IComponentBase (A и B наследуют этот интерфейс)
template <typename InterfaceMediator>
class C<Mediator, InterfaceMediator>: public InterfaceMediator {
public:
    C(IComponentBase*  a,IComponentBase*  firstComponent, IComponentBase* secondComponent)
    {
        _a = std::shared_ptr<IComponentBase>(a);
        _firstComponent = std::shared_ptr<IComponentBase>(firstComponent);
        _secondComponent = std::shared_ptr<IComponentBase>(secondComponent);
    }
    void notify(IComponentBase* sender, std::string event)
    {
        if (sender == this->_a.get()) {
            std::cout << "Mediator.notify from a + msg(" << event << ")" << std::endl;
            if (event == "firstComponent") {
                _firstComponent->act();
                return;
            }
            if (event == "secondComponent") {
                _secondComponent->act();
                return;
            }
            std::cout << "Mediator.notify from a unknown command" << std::endl;
            return;
        }
        if (sender == this->_firstComponent.get()) {
            std::cout << "Mediator.notify from firstComponent + msg(" << event << ")" << std::endl;
            return;
        }
        if (sender == this->_secondComponent.get()) {
            std::cout << "Mediator.notify from secondComponent + msg(" << event << ")" << std::endl;
            return;
        }
        std::cout << "Mediator.notify from unknown" << std::endl;
    }
private:
    std::shared_ptr<IComponentBase> _a;  // это класс A который вызывает другие компоненты
    std::shared_ptr<IComponentBase> _firstComponent;
    std::shared_ptr<IComponentBase> _secondComponent;
};

