#pragma once
// интерфейс Медиатора для класса C
#include <string>
#include "IComponentBase.h"


class IMediator
{
public:
    virtual ~IMediator() {}
    virtual void notify(IComponentBase* sender, std::string event) = 0;
};
