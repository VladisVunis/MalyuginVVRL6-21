#include <iostream>
#include <fstream>
#include <time.h>

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

void showArray(unsigned int *arr, int size){
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << arr[i] << std::endl;
    }
}

void cycleShiftArray(unsigned int *array, int size, int N, bool left){
    for(int i = 0; i < size; i++){
        //x = *(array + i);
        if( left == true){
            *(array + i) = (*(array + i) << N) | (*(array + i) >> (32 - N));
        }
        else{
            *(array + i) = (*(array + i) >> N) | (*(array + i) << (32 - N));
        }
    }
}

void setBit(int* number, int numBit){
    unsigned int c = 0x00000001;
    c = c << numBit;
    *number = *number | c;
}

void clearBit(int* number, int numBit){
    unsigned int c = 0x00000001;
    c = c << numBit;
    c = ~c;
    *number = *number & c;
}

void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements){
    std::ofstream DIM;
    DIM.open(fileName, std::ios_base::out);
    if (!DIM.is_open()){
        std::cout << "error" << std::endl;
    }
    else{
        if(countElements % cols == 0){
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
        }
        else{
            int count = 0;
            for(int Ncount = 0; Ncount < (countElements/cols)*cols; Ncount += cols){
                count += cols;
                for(int NScount = 0; NScount < cols; NScount++){
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
            for(int c = count ; c < countElements; c++){
                int x = min + rand()%(max-min +1);
                DIM << x << delimeter;
            }
        }
        DIM.close();
    }
}
