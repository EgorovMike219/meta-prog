#pragma once

#include <iostream>
#include <memory>
#include "ISubject.h"
#include "C.h"


// ISubject - class B
template <>
class C<Proxy>: public ISubject {
public:
    C(ISubject* b)
    {
        _receiver =
                std::shared_ptr<ISubject>(b);
    }
    void doSomething() override {
        std::cout<<"C.doSomething"<<std::endl;
        _receiver->doSomething();
    }
private:
    std::shared_ptr<ISubject> _receiver;
};
