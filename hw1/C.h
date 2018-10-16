#pragma once

enum Pattern{
    Proxy,
    Mediator,
    Observer
};


template <Pattern> class C;
