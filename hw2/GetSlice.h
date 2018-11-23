#pragma once

#include "TypeList.h"

template
<
    class TList,
    int Number
>
struct GetSlice{
    using Result = NullType;
};

// если длина TypeList меньше или равно Number
template <>
struct GetSlice<TypeList<>, 0>
{
    using Result = TypeList<>;
};

// если длина TypeList больше Number
template <class Head, class ... Tail>
struct GetSlice<TypeList<Head, Tail ...>, 0>
{
    using Result = TypeList<Head, Tail ...>;
};

// общий случай
template
<
    class Head,
    class ... Tail,
    int Number
>
struct GetSlice<TypeList<Head, Tail ...>, Number>
{
    using Result = class GetSlice<TypeList<Tail ...>, Number - 1>::Result;
};
