#pragma once

#include <iostream>
#include <memory>
#include "C.h"


// InterfaceSubject - class B
template <typename InterfaceSubject>
class C<Proxy, InterfaceSubject>: public InterfaceSubject {
public:
    C(InterfaceSubject* b)
    {
        _receiver =
                std::shared_ptr<InterfaceSubject>(b);
    }
    void doSomething() override {
        std::cout<<"C.doSomething"<<std::endl;
        _receiver->doSomething();
    }
private:
    std::shared_ptr<InterfaceSubject> _receiver;
};
