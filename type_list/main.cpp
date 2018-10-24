#include <iostream>
#include <typeinfo>
#include "typeList.h"


using CharIntList = TypeList<char, signed char, unsigned char, int, signed int, unsigned int>;
using List = Erase<CharIntList, double>::result;
using SignedCharList = Erase<CharIntList, unsigned char>::result;
using EmpltyList = TypeList<>;


template<class T>
struct FImpl;

template<class T>
void printTypeList() { FImpl<T>::f(); } // users, don't touch this!

using EmptyList = TypeList<>;



int main() {
    std::cout << "Char Int List!" << std::endl;
    printTypeList<CharIntList>();
    std::cout<<"Length="<<Length<CharIntList>::value<<std::endl;
    std::cout << "List!" << std::endl;
    printTypeList<List>();
    std::cout<<"Length="<<Length<List>::value<<std::endl;
    std::cout << "Signed Char List!" << std::endl;
    printTypeList<SignedCharList>();
    std::cout<<"Length="<<Length<SignedCharList>::value<<std::endl;
    std::cout<<"Length empty list="<<Length<EmptyList>::value<<std::endl;
    return 0;
}


template<>
struct FImpl<TypeList<NullType> > {
    static void f() // users, go ahead and specialize this
    {
//        std::cout<<"TypeList<NullType>"<<std::endl;
    }
};

template<class Head, class ... Tail>
struct FImpl<TypeList<Head, TypeList<Tail ...> > > {
    static void f() // users, go ahead and specialize this
    {
//        std::cout<<"TypeList<Head, TypeList<Tail ...>"<<std::endl;
        std::cout << typeid(Head).name() << std::endl;
        printTypeList<TypeList<Tail ...> >();
    }
};

//// для поддержки c++11
template<class Head, class ... Tail>
struct FImpl<TypeList<Head, Tail ...> > {
    static void f() // users, go ahead and specialize this
    {
//        std::cout<<"TypeList<Head, Tail ...>"<<std::endl;
        printTypeList<TypeList<Head, class TypeList<Head, Tail ...>::tail> >();
    }
};
