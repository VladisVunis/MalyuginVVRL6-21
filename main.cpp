#include <iostream>
#include "bit_operations.h"
#include <fstream>
#include <time.h>

using namespace std;

void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements){
    srand(time(nullptr));
    ofstream DIM;
    DIM.open("set", ios_base::out);
    if (!DIM.is_open()){
        std::cout << "error" << std::endl;
    }
    else{
        for(int Ncount = 0; Ncount != countElements ;Ncount += cols ){
            for(int NScount = 0; NScount != cols; NScount++){
                if(cols == NScount + 1){
                    int x = min + rand()%(max-min +1);
                    DIM << x << std::endl;
                }
                else{
                    int x = min + rand()%(max-min +1);
                    DIM << x << delimeter;
                }
            }

        }
        DIM.close();
    }
}

int main()
{
    fillFile("set", 10, 20, '\t', 4, 12);
    /*int number = 0x80000001;

    setBit(&number, 8);
    cout << hex << number << endl;

    cout<<"------------"<<endl;

    clearBit(&number, 0);
    cout << hex << number << endl;

    unsigned int ar[4] = {0x80000001u, 0x00, 0x80, 0x10};
    int size = 4;
    bool f = true;
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    cout<<"------------"<<endl;

    cycleShiftArray(ar, 4, 1, f);
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w << endl;

    cout<<"------------"<<endl;

    unsigned int Pnumber = 0x80000801;
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber/2 << endl;

    cout<<"------------"<<endl;

    int ar[5] = { 0x0FFFFFFF, (int) 0xFFFFFFFF, 0x00, 0x0FFFFFFF};
    int index = 0;
    index = getMaxBit(ar,4);
    cout << index<< endl;

    cout<<"------------"<<endl;

    int num = -10;
    unsigned char amount = getCount1Bit(num);
    cout << (int)amount << endl;*/




    return 0;
}
