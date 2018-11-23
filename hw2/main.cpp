#include <iostream>
#include "GenCustomHierarchy.h"


template <class T, class Base>
class Handler: public Base
{
public:
    virtual void OnEvent(T& obj){
        std::cout<<sizeof(T)<<std::endl;
    }
};
class A{
    int val;
public:
    int f1();
};
class B{
    char val;
public:
    int f2();
};
class C{
    double val;
public:
    int f3();
};

typedef GenCustomHierarchy<TypeList<A, B, C>, Handler> MyHandler;

int main() {
    return 0;
}