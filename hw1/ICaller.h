#pragma once

#include "ISubject.h"
// Интерфейс вызыватель
// Интерфейс для класса A, чтобы в паттерне proxy вызвать класс B
class ICaller
{
public:
    virtual void call(ISubject*) = 0;
};