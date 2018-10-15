#include <iostream>
#include "Proxy.h"
#include "Mediator.h"
#include "Observer.h"
#include "A.h"
#include "B.h"

int main() {
    //Proxy
    std::cout<<"===================Proxy==================="<<std::endl;
    A* a = new A();
    B* b = new B();
    auto cProxy = new C<Proxy>(b);
    a->call(cProxy);
    //Mediator
    std::cout<<"===================Mediator================"<<std::endl;
    A* client = new A("client");
    B* component1 = new B("component1");
    B* component2 = new B("component2");
    auto cMediator = new C<Mediator>(
            client,
            component1,
            component2);
    client->setMediator(cMediator);
    client->call("firstComponent");
    //Observer
    std::cout<<"===================Observer================"<<std::endl;
    A* eventListener1 = new A("eventListener1");
    A* eventListener2 = new A("eventListener2");
    auto eventManager = new C<Observer>();
    eventManager->subscribe(IObserver::EventType::Update, eventListener1);
    eventManager->subscribe(IObserver::EventType::Update, eventListener2);
    B* editor = new B("editor", "text", eventManager);
    editor->edit("new text");
    return 0;
}