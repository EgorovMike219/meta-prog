#include <iostream>
#include <typeinfo>
#include "typeList.h"


using CharList = TypeList<char, signed char, unsigned char>;
using List = NTypeList::Erase<TypeList<char, signed char, unsigned char>, double>::result;
using SignedCharList = NTypeList::Erase<CharList, unsigned char>::result;


template <class T>
struct FImpl
{
    static void f() // users, go ahead and specialize this
    {
        std::cout<<typeid(T).name()<<std::endl;
    }
};

template<class T>
void printTypeList() { FImpl<T>::f(); } // users, don't touch this!

template <>
struct FImpl<TypeList<NullType> >
{
    static void f() // users, go ahead and specialize this
    {}
};

template <class Head, class ... Tail>
struct FImpl<TypeList<Head, TypeList<Tail ...> > >
{
    static void f() // users, go ahead and specialize this
    {
        std::cout<<typeid(Head).name()<<std::endl;
        printTypeList<TypeList<Tail ...> >();
    }
};

//// для поддержки c++11
template <class Head, class ... Tail>
struct FImpl<TypeList<Head, Tail ...> >
{
    static void f() // users, go ahead and specialize this
    {
        printTypeList<TypeList<Head, class TypeList<Head, Tail ...>::tail > >();
    }
};


int main() {
    std::cout << "Char List!" << std::endl;
    printTypeList<CharList>();
    std::cout << "List!" << std::endl;
    printTypeList<List>();
    std::cout << "<char, signed char, unsigned char>!" << std::endl;
    printTypeList<TypeList<char, signed char, unsigned char>>();
    std::cout << "Signed Char List!" << std::endl;
    printTypeList<SignedCharList>();
    return 0;
}