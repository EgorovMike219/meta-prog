#pragma once

enum Pattern{
    Proxy,
    Mediator,
    Observer
};


class NullType{};
template <Pattern, typename T=NullType> class C;
