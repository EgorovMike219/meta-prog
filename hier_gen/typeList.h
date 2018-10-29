#pragma once


class NullType {};

template <class T=NullType, class ... U>
struct TypeList
{
    using head = T;
    using tail = TypeList<U ...>;
};

template <class T>
struct TypeList<T>
{
    using head = T;
    using tail = NullType;
};
