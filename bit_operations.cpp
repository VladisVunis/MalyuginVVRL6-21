#include <iostream>

void swapHalfWord(unsigned int* words){
    *words = (*words << 16) | (*words >> 16);
}

void cycleShift(unsigned int* number, int N, int left){
    if(left == 1){
        *number = (*number << N) | (*number >> (32 - N));
    }
    else{
        *number = (*number >> N) | (*number << (32 - N));
    }
}

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

unsigned char getCount1Bit( int number){
    int count = 0;
    unsigned int x = number;
    while (x > 0) {
        if (x & 1) count++;
        x >>= 1;
    }

    return count;
}
