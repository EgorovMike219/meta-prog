#include <iostream>
#include "functor.h"


void f(int, int) { std::cout<<"function(int,int)\n"; }
void func() { std::cout<<"function()\n"; }

struct A {
    void f(int, int) { std::cout<<"A method f(int,int)\n"; }
};

struct F {
    void operator()() const { std::cout<<"F operator()(int,int)\n"; }
};

A a;
F fun;

int main() {
// обычные функции
    f(1, 2);
    auto functor1 = make_functor(&f, 1, 2);
    functor1.Call();
// функции-члены
    a.f(1, 2);
    auto functor2 = make_functor(&A::f, 1, 2);
    functor2.Call(a);
// лямбды
    void (*plambda)(int, int) = [](int, int) { std::cout<<"lambda(int,int)\n"; };
    plambda(1, 2);
    auto functor3 = make_functor([](int, int) { std::cout<<"lambda(int,int)\n"; }, 1, 2);
    functor3.Call();
// объекты с оператором ()
    fun();
    auto functor4 = make_functor(fun);
    functor4.Call();
    return 0;
}