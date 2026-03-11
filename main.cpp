#include <iostream>
#include "bit_operations.h"

using namespace std;

int main()
{
    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w << endl;

    cout<<"------------"<<endl;

    unsigned int Pnumber = 0x80000801;
    int n = 1;
    int left = 0;
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber << endl;

    return 0;
}
