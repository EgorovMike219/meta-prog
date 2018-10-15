#pragma once
// интерфейс editor в паттерне Наблюдатель для класса B
#include <memory>
#include <string>
#include "IObserver.h"


class IEditor {
public:
    IEditor(std::string data, IObserver* observer)
    {
        _data = data;
        _observer =
                std::shared_ptr<IObserver>(observer);

    }
    virtual void edit(std::string) = 0;
protected:
    std::shared_ptr<IObserver> _observer;
    std::string _data;
};