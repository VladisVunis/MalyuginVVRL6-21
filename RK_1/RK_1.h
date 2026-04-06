#ifndef RK_1_H
#define RK_1_H
#include <iostream>

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
std::ostream& operator<<(std::ostream& out, const Fraction& FR);
void EVKLID(Fraction& frt);

#endif // RK_1_H
