#include <iostream>
#include "RK_1.h"
using namespace std;

int main()
{
    Fraction fr1(10, 20);
    Fraction fr2(5, 7);
    std::cout << sum(fr1, fr2) << std::endl;
    std::cout << sub(fr1, fr2) << std::endl;
    std::cout << div(fr1,fr2) << std::endl;
    std::cout << mul(fr1, fr2) << std::endl;
    return 0;
}
