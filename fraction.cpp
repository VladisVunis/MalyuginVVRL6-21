#include "fraction.h"
#include <iostream>

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
