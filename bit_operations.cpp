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
