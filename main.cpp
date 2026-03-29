#include <iostream>
#include "bit_operations.h"
#include <fstream>
#include <time.h>
#include "file_operations.h"

using namespace std;

/*void cycleShiftArray(unsigned int *array, int size, int N, bool left){
    for(int i = 0; i < size; i++){
        //x = *(array + i);
        if( left == true){
            *(array + i) = (*(array + i) << N) | (*(array + i) >> (32 - N));
        }
        else{
            *(array + i) = (*(array + i) >> N) | (*(array + i) << (32 - N));
        }
    }

            for(int i = size - 1; i > -1; i --){
                unsigned int saved = 0;
                saved = (array[i] >> (N - 32));
                *(array + i) = *(array + i) << N;
            }
        }
}*/

int main()
{
    /*srand(time(nullptr));
    fillFile("set", 10, 20, '\t', 7, 12);*/

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

    cout<<"------------"<<endl;*/

    unsigned int ar[] = {0x40, 0x00, 0x80, 0x01};
    bool f = true;

    cycleShiftArray(ar, 4, 1, f);
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    /*unsigned int w = 0xFFAABBCC;
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
