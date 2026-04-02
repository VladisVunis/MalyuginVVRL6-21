#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int _numerator; //< числитель
    int _denominator; //< знаменатель
    Fraction();
    Fraction(int numerator, int denominator){
        _numerator = numerator;
        _denominator = denominator;
    }
};

int fracReduction(Fraction& frac);

#endif // FRACTION_H
