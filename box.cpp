#include "box.h"
#include <iostream>
#include <fstream>

Box::Box(int len, int width, int height){
    nameBox = counter;
    _len = len;
    _width = width;
    _height = height;
    if((_len*_width*_height) < 0){
        volus = false;
    }
    else volus = true;
    volume = _len*_width*_height;
    counter++;
}

Box::Box(int number){
    nameBox = counter;
    _len = number;
    _width = number;
    _height = number;
    if((_len*_width*_height) < 0){
        volus = false;
    }
    else volus = true;
    volume = _len*_width*_height;
    counter++;
}
Box::Box(){
    nameBox = counter;
    _len = 10;
    _width = 10;
    _height = 10;
    if((_len*_width*_height) < 0){
        volus = false;
    }
    else volus = true;
    volume = _len*_width*_height;
    counter++;
}


int Box::counter = 1;

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

std::ostream& operator<<(std::ostream& dot, const Box& vivo){
    dot << "[" <<vivo.nameBox <<"] = {"<< vivo._len << ", " << vivo._width <<", "<<vivo._height << "} = ";
    if(vivo.volus == true) dot << vivo.volume << "\n";
    else dot << "[" <<vivo.nameBox <<"] = V < 0\n";
    return dot;
}

