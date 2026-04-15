#include "box.h"
#include <iostream>
#include <fstream>

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

std::ostream& operator<<(std::ostream& out, const Box& ST){
    out << "len = ";
    out << ST._len;
    out << ", width = ";
    out << ST._width;
    out << ", height = ";
    out << ST._height;
    out << ", volume = ";
    out << ST.volume;
    out << "\n";

    return out;
}

