#include <iostream>
#include "Proxy.h"
#include "Mediator.h"
#include "A.h"
#include "B.h"

int main() {
    //Proxy
    std::cout<<"===================Proxy==================="<<std::endl;
    A* a = new A();
    B* b = new B();
    auto * cProxy = new C<Proxy, ISubject>(b);
    a->call(cProxy);
    //Mediator
    std::cout<<"===================Mediator================"<<std::endl;
    A* client = new A("client");
    B* component1 = new B("component1");
    B* component2 = new B("component2");
    auto* cMediator = new C<Mediator, IMediator>(
            client,
            component1,
            component2);
    client->setMediator(cMediator);
    client->call("firstComponent");
    return 0;
}