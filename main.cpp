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
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber/2 << endl;

    cout<<"------------"<<endl;
    int ar[5] = {(int) 0xFFFFFFFF, 0x00};
    int index = 0;
    index = getMaxBit(ar,5);
    cout << index<< endl;



    return 0;
}
