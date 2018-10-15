#pragma once
// Интерфейс для класса B
class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void doSomething() = 0;
};