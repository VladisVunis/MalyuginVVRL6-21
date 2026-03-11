#include <iostream>
#include "bit_operations.h"

using namespace std;

int getMaxBit(const int* array, int N){
    int count = 0;
    int MAXcount = 0;
    int MAXindex = 0;
    for(int i= 0; i< N;i++){
        int x = array[i];
        if(x > 0){
            while(x>0){
                if (x & 1) count++;
                x >>= 1;
            }
            if(count > MAXcount){
                MAXcount = count;
                MAXindex = i;
                count = 0;
            }
            else count = 0;
        }
        else continue;
    }
    if(MAXcount != 0) return MAXindex;
    else return -1;
}

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
