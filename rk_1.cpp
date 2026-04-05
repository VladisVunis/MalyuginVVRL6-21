#include "rk_1.h"
#include <iostream>


std::ostream& operator<<(std::ostream& out, const Box& ST){
    out << "len = ";
    out << ST._len;
    out << ", width = ";
    out << ST._width;
    out << ", height = ";
    out << ST._height;
    out << ", volume = ";
    out << ST._volume;
    out << "\n";

    return out;
}
