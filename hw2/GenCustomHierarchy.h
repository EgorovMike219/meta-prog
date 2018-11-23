#pragma once

#include "TypeList.h"
#include "GenLinearHierarchy.h"
#include "GetSlice.h"

template
<
        class TList,
        template <class AtomicType, class Base> class Unit,
        class Root = NullType,
        int PreviousNumber = 0,
        int CurrentNumber = 1
>
class GenCustomHierarchy;

// случай когда GetSlice возвращает TypeList<> (если длина TypeList меньше или равно Number)
template
<
    template <class, class> class Unit,
    class Root,
    int PreviousNumber,
    int CurrentNumber
>
class GenCustomHierarchy<TypeList<>, Unit, Root, PreviousNumber, CurrentNumber> {
};

// случай когда в TypeList только один элемент; на самом деле не обязательно специализировать этот случай
template
<
    class Type,
    template <class, class> class Unit,
    class Root,
    int PreviousNumber,
    int CurrentNumber
>
class GenCustomHierarchy<TypeList<Type>, Unit, Root, PreviousNumber, CurrentNumber>:
        public Unit<Type, Root> {
public:
    using LeftBase = Unit<Type, Root>;
};

template
<
    class Head,
    class ... Tail,
    template <class, class> class Unit,
    class Root,
    int PreviousNumber,
    int CurrentNumber
>
class GenCustomHierarchy<TypeList<Head, Tail ...>, Unit, Root, PreviousNumber, CurrentNumber>:
        public GenLinearHierarchy
            <
                TypeList<Head, Tail ...>,
                Unit,
                Root,
                CurrentNumber
            >,
        public GenCustomHierarchy
            <
                class GetSlice<TypeList<Head, Tail ...>, CurrentNumber>::Result,
                Unit,
                Root,
                CurrentNumber,
                PreviousNumber + CurrentNumber
            > {
public:
    using TList = TypeList<Head, Tail ...>;
    using LeftBase = GenLinearHierarchy
            <
                    TypeList<Head, Tail ...>,
                    Unit,
                    Root,
                    CurrentNumber
            >;
    using RightBase = GenCustomHierarchy
            <
                class GetSlice<TypeList<Head, Tail ...>, CurrentNumber>::Result,
                Unit,
                Root,
                CurrentNumber,
                PreviousNumber + CurrentNumber
            >;
};
