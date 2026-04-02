#include "fraction.h"

int fracReduction(Fraction& frac){
    int a = frac._numerator;
    int b = frac._denominator;
    int ost = 0;
    if(b == 0){
        return -1;
    }
    else{
        if(a > b){
            while( b != 0){
                ost = a%b;
                a = b;
                b = ost;
            }
            frac._numerator = frac._numerator/a;
            frac._denominator = frac._denominator/a;
            return 0;
        }
        else{
            while( a != 0){
                ost = b%a;
                b = a;
                a = ost;
            }
            frac._numerator = frac._numerator/b;
            frac._denominator = frac._denominator/b;
            return 0;
        }
    }
}
