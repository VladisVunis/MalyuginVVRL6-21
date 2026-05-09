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

    Box(int len, int width, int height);
    Box(int number);
    Box();

};

void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box& box);
std::ostream& operator<<(std::ostream& dot, const Box& vivo);
#endif // BOX_H
