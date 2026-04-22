#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <fstream>

struct Box {
    static int counter;

    int nameBox;
    int _len; //длина
    int _width; //ширина
    int _height; //высота
    int _color; //цвет
    int volume; // объем
    bool volus;

    Box(int len, int width, int height){
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

    Box(int number){
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

    Box(){
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

};


void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box& box);
std::ostream& operator<<(std::ostream& dot, const Box& vivo);
#endif // BOX_H
