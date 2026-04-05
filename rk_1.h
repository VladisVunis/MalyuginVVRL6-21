#ifndef RK_1_H
#define RK_1_H
#include <iostream>

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

struct Fraction {
    int _numerator; //< числитель
    int _denominator; //< знаменатель
    Fraction(){
        _numerator = 1;
        _denominator = 1;
    };
    Fraction(int numerator, int denominator){
        _numerator = numerator;
        _denominator = denominator;
    }
};
Fraction sum(const Fraction& fr1, const Fraction& fr2); //< сложение
Fraction sub(const Fraction& fr1, const Fraction& fr2); //< вычитание
Fraction div(const Fraction& fr1, const Fraction& fr2); //< деление
Fraction mul(const Fraction& fr1, const Fraction& fr2); //< умножение
std::ostream& operator<<(std::ostream& out, const Box& ST);
std::ostream& operator<<(std::ostream& out, const Fraction& FR);
void EVKLID(Fraction& frt);
#endif // RK_1_H
