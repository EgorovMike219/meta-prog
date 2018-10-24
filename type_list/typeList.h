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

// удаление только первого вхождения
template <class Type, class T> struct Erase
{
    using result = NullType;  // этот код никогда не выполнится, нужен для видимости result
};
// если typeList пустой, то результат NullType
template <class T>
struct Erase<TypeList<NullType>, T>
{
    using result = NullType;
};
// иначе
// если T=Head, то результат хвост
template <class T, class ... Tail>
struct Erase<TypeList<T, TypeList<Tail ...> >, T>
{
    using result = TypeList<Tail ...>;
};
// иначе
// рекурсивно удаляем элемент из хвоста
template <class Head, class ... Tail, class T>
struct Erase<TypeList<Head, TypeList<Tail ...> >, T>
{
    using result = TypeList<Head, class Erase<class TypeList<Head, Tail ...>::tail, T>::result >;
};
// для поддержки с++ templates
template <class Head, class ... Tail, class T>
struct Erase<TypeList<Head, Tail ...>, T>
{
    using result = class Erase<TypeList<Head, class TypeList<Head, Tail ...>::tail >, T>::result;
};

#include <iostream>

template <class TypeList>
struct Length {
    enum {
        value = Length<class TypeList::tail>::value + 1
    };
    static int f() {
        std::cout<<"TypeList| TypeList::tail="<< typeid(class TypeList::tail).name()<<std::endl;
        return 1 + Length<class TypeList::tail>::f();
    }
};

template <>
struct Length<TypeList<NullType> > {
    enum {
        value = 0
    };
    static int f() {
        std::cout<<"TypeList<NullType>"<<std::endl;
        return 0;
    }
};

template <>
struct Length<NullType> {
    enum {
        value = 0
    };
    static int f() {
        std::cout<<"NullType"<<std::endl;
        return 0;
    }
};
