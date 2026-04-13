#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <fstream>

struct Box {
    int _len; //длина
    int _width; //ширина
    int _height; //высота
    int _color; //цвет
    int _volume; // объем

    Box(int len, int width, int height){
        _len = len;
        _width = width;
        _height = height;
        _volume = _len*_width*_height;
    }

    Box(int number){
        _len = number;
        _width = number;
        _height = number;
        _volume = _len*_width*_height;
    }

    Box(){
        _len = 10;
        _width = 10;
        _height = 10;
        _volume = _len*_width*_height;
    }
};

void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box& box);
std::ostream& operator<<(std::ostream& out, const Box& ST);
#endif // BOX_H
