#include <iostream>
#include <fstream>
#include "TypeList.h"
#include "Reader.h"


int main() {
    std::string line;

    std::ifstream in("../input.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        std::cout<<"...\n";
        Reader<TypeList<int, char, double>> reader(&in);
        char* mem = (char*)reader.readNextLine();
        int a = *((int*)(mem));
        std::cout << (void*)mem << "---" << a << std::endl;
        mem += sizeof(int);
        char b = *((char*)(mem));
        std::cout << (void*)mem << "---" << b << std::endl;
        mem += sizeof(char);
        double c = *((double*)(mem));
        std::cout << (void*)mem << "---" << c << std::endl;
    }
    in.close();     // закрываем файл

    std::cout << "End of program" << std::endl;
    return 0;
}