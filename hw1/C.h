#pragma once

enum Pattern{
    Proxy,
    Mediator,
    Observer
};


class NullType{};
template <Pattern, typename T, typename Y=NullType> class C;
