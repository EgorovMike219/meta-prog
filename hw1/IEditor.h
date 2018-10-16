#include <utility>

#pragma once
// интерфейс editor в паттерне Наблюдатель для класса B
#include <memory>
#include <string>
#include "IManager.h"


class IEditor {
public:
    IEditor(std::string data, IManager* observer)
    {
        _data = std::move(data);
        _observer =
                std::shared_ptr<IManager>(observer);

    }
    virtual void edit(std::string) = 0;
protected:
    std::shared_ptr<IManager> _observer;
    std::string _data;
};