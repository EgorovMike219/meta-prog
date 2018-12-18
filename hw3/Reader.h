#pragma once

#include <fstream>
#include "TypeList.h"


template <class TypeList>
struct SizeOf{
    enum { size = 0};
};

template <class T, class ... U>
struct SizeOf<TypeList<T, U... > >{
    enum { size = sizeof(T) + SizeOf<TypeList<U ...> >::size};
};

template <class T>
struct SizeOf<TypeList<T> >{
    enum { size = sizeof(T)};
};

template <class TypeList>
struct Read{};

template <class T, class ... U>
struct Read<TypeList<T, U ...> >{
    static void read(std::ifstream* in, char* mem) {
        *in >> *((T*)(mem));
        std::cout << (void*)mem  << "---" << *((T*)(mem)) << std::endl;
        Read<TypeList<U ...> >::read(in, mem + sizeof(T));
    }
};

template <class T>
struct Read<TypeList<T> >{
    static void read(std::ifstream* in, char* mem) {
        *in >> *((T*)(mem));
        std::cout << (void*)mem  << "---" << *((T*)(mem)) << std::endl;
    }
};

template <class TypeList>
class Reader {
public:
    Reader(std::ifstream* in): in(in){};
    void* readNextLine();

private:
    std::ifstream* in;
};

template <class T, class ... U>
class Reader<TypeList<T, U... > >
{
public:
    Reader(std::ifstream* in): in(in){};
    void* readNextLine() {
        char* mem = new char[SizeOf<TypeList<T, U ...> >::size];
        Read<TypeList<T, U ...>>::read(in, mem);
        return mem;
    }

private:
    std::ifstream* in;
};

template <class T>
class Reader<TypeList<T> >
{
public:
    Reader(std::ifstream* in): in(in){};
    void* readNextLine() {
        char* mem = new char[SizeOf<TypeList<T> >::size];
        Read<TypeList<T>>::read(in, mem);
        return mem;
    }

private:
    std::ifstream* in;
};


