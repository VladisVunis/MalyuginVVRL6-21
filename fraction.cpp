#include "fraction.h"
#include <iostream>

Fraction::Fraction(){
    _numerator = 1;
    _denominator = 1;
};

Fraction::Fraction(int numerator, int denominator){
    _numerator = numerator;
    _denominator = denominator;
}

int fracReduction(Fraction& frac){
    int a = frac._numerator;
    int b = frac._denominator;
    int ost = 0;
    a = abs(a);
    b = abs(b);
    if(b == 0){
        return -1;
    }
    else{
        if(abs(a) > abs(b)){
            while( abs(b) != 0){
                ost = a%b;
                a = b;
                b = ost;
            }
            frac._numerator = frac._numerator/a;
            frac._denominator = frac._denominator/a;
            if(frac._denominator < 0){
                frac._numerator = frac._numerator*-1;
                frac._denominator = frac._denominator* -1;
            }
            return 0;
        }
        else{
            while( abs(a) != 0){
                ost = b%a;
                b = a;
                a = ost;
            }
            frac._numerator = frac._numerator/b;
            frac._denominator = frac._denominator/b;
            if(frac._denominator < 0){
                frac._numerator = frac._numerator*-1;
                frac._denominator = frac._denominator* -1;
            }
            return 0;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Fraction& FR){
    out << FR._numerator;
    out << "/";
    out << FR._denominator;
    return out;
}

void EVKLID(Fraction& frt){
    int a = frt._numerator;
    int b = frt._denominator;
    int ost = 0;
    if(b ==0){
        return;
    }
    if(a == 0){
        frt._denominator = 1;
        return;
    }
    a = abs(a);
    b = abs(b);
    if(abs(a) > abs(b)){
        while( abs(b) != 0){
            ost = abs(a)%abs(b);
            a = b;
            b = ost;
        }
        frt._numerator = frt._numerator/a;
        frt._denominator = frt._denominator/a;
    }
    else{
        while( abs(a) != 0){
            ost = abs(b)%abs(a);
            b = a;
            a = ost;
        }
        frt._numerator = frt._numerator/b;
        frt._denominator = frt._denominator/b;
    }
    if(frt._denominator < 0){
        frt._numerator = frt._numerator*-1;
        frt._denominator = frt._denominator* -1;
    }
}

Fraction sum(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2 + a2 * b1;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;
}

Fraction sub(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2 - a2 * b1;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;
}

Fraction div(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2;
    fr0._denominator = b1 * a2;
    EVKLID(fr0);
    return fr0;

}

Fraction mul(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * a2;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;

}
