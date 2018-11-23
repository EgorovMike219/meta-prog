#pragma once
#include "TypeList.h"


template
<
    class TList,
    template <class AtomicType, class Base> class Unit,
    class Root,
    int Number
>
class GenLinearHierarchy;

// случай когда длина тайплиста больше number
template
<
    class Head,
    class ... Tail,
    template <class, class> class Unit,
    class Root
>
class GenLinearHierarchy<TypeList<Head, Tail ...>, Unit, Root, 1>
        : public Unit<Head, Root > {};

template
<
        class Head,
        class ... Tail,
        template <class, class> class Unit,
        class Root,
        int Number
>
class GenLinearHierarchy<TypeList<Head, Tail ...>, Unit, Root, Number>
        : public Unit<Head, GenLinearHierarchy<TypeList<Tail ...>, Unit, Root, Number - 1> > {};

// случай когда длина тайплиста меньше или равно number
template
<
    class Type,
    template <class, class> class Unit,
    class Root,
    int Number
>
class GenLinearHierarchy<TypeList<Type>, Unit, Root, Number>
        : public Unit<Type, Root> {};
