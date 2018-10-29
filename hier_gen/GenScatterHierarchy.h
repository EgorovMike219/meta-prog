#pragma once

#include "typeList.h"

template <class TList, template <class> class Unit>
class GenScatterHierarchy;

template <class Head, class ... Tail, template <class> class Unit>
class GenScatterHierarchy<TypeList<Head, Tail ...>, Unit>:
        public GenScatterHierarchy<class TypeList<Head, Tail ...>::head , Unit>,
        public GenScatterHierarchy<class TypeList<Head, Tail ...>::tail, Unit> {
public:
    using TList = TypeList<Head, Tail ...>;
    using LeftBase = GenScatterHierarchy<class TypeList<Head, Tail ...>::head, Unit>;
    using RightBase = GenScatterHierarchy<class TypeList<Head, Tail ...>::tail, Unit>;
    // неявное преобразование к базовому типу
    template <typename T> struct Rebind
    {
        using Result = Unit<T>;
    };
};

template <class Type, template <class> class Unit>
class GenScatterHierarchy:
        public Unit<Type> {
public:
    using LeftBase = Unit<Type>;
    // неявное преобразование к базовому типу
    template <typename T> struct Rebind
    {
        using Result = Unit<T>;
    };
};

template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit> {
    // неявное преобразование к базовому типу
    template <typename T> struct Rebind
    {
        using Result = Unit<T>;
    };
};

// не работает если в списке есть дубликаты
template <class T, class H>
typename H::template Rebind<T>::Result& Field(H& obj)
{
    return obj;
}
