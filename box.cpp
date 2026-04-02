#include <fstream>
#include <iostream>
#include "box.h"

void writeToFile(const char* fileName, const struct Box& box){
    std::ofstream Write;
    Write.open(fileName, std::ios_base::out);
    if(!Write.is_open()) return;
    else{
        Write << box._len << std::endl;
        Write << box._width << std::endl;
        Write << box._height << std::endl;
        Write << box._color << std::endl;
    }
    Write.close();
}

void readFromFile(const char* fileName, struct Box& box){
    std::ifstream Read(fileName);
    if(!Read.is_open()) return;
    else{

        Read >> box._len;

        Read >> box._width;

        Read >> box._height;

        Read >> box._color;

    }
    Read.close();
}
