#include <iostream>
#include <typeinfo>
#include "typeList.h"


using NewTypeList = TypeList<char, signed char, unsigned char, int, signed int, unsigned int>;
using NewList = Erase<NewTypeList, double>::result;
using NewSignedList = Erase<Erase<NewTypeList, unsigned char>::result, unsigned int>::result;
using EmptyList = TypeList<>;

using OldTypeList = TypeList<char, TypeList<signed char, TypeList<unsigned char, TypeList<int, TypeList<signed int, TypeList<unsigned int> > > > > >;
using OldList = Erase<OldTypeList, double>::result;
using OldSignedList = Erase<Erase<OldTypeList, unsigned char>::result, unsigned int>::result;


template<class T>
struct FImpl;

template<class T>
void printTypeList() { FImpl<T>::f(); } // users, don't touch this!


int main() {
    std::cout<<"=======Test new Typelist c++11======="<<std::endl;
    std::cout << "New Type List!" << std::endl;
    printTypeList<NewTypeList>();
    std::cout<<"Length="<<Length<NewTypeList>::value<<std::endl;
    std::cout<<std::endl<<"New List!" << std::endl;
    printTypeList<NewList>();
    std::cout<<"Length="<<Length<NewList>::value<<std::endl;
    std::cout<<std::endl<< "New Signed List!" << std::endl;
    printTypeList<NewSignedList>();
    std::cout<<"Length="<<Length<NewSignedList>::value<<std::endl;
    std::cout<<std::endl<< "Empty List!" << std::endl;
    std::cout<<"Length empty list="<<Length<EmptyList>::value<<std::endl;
    std::cout<<std::endl<<"=======Test old Typelist before c++11======="<<std::endl;
    std::cout << "Old Type List!" << std::endl;
    printTypeList<OldTypeList>();
    std::cout<<"Length="<<Length<OldTypeList>::value<<std::endl;
    std::cout<<std::endl<< "Old List!" << std::endl;
    printTypeList<OldList>();
    std::cout<<"Length="<<Length<OldList>::value<<std::endl;
    std::cout<<std::endl<< "Old Signed List!" << std::endl;
    printTypeList<OldSignedList>();
    std::cout<<"Length="<<Length<OldSignedList>::value<<std::endl;
    return 0;
}


template<>
struct FImpl<TypeList<NullType> > {
    static void f() // users, go ahead and specialize this
    {
    }
};

template<class Head, class ... Tail>
struct FImpl<TypeList<Head, TypeList<Tail ...> > > {
    static void f() // users, go ahead and specialize this
    {
        std::cout << typeid(Head).name() << std::endl;
        printTypeList<TypeList<Tail ...> >();
    }
};

//// для поддержки c++11
template<class Head, class ... Tail>
struct FImpl<TypeList<Head, Tail ...> > {
    static void f() // users, go ahead and specialize this
    {
        printTypeList<TypeList<Head, class TypeList<Head, Tail ...>::tail> >();
    }
};
