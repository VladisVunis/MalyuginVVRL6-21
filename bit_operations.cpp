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

void showArray(unsigned int *arr, int size){
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << arr[i] << std::endl;
    }
}

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
}*/

void cycleShiftArray(unsigned int *array, int size, int N, bool left){
    if(N < 32){
        unsigned int temp[size];
        if(left == true){
            for(int i = size - 1; i >= 0; i --){
                temp[i] = (*(array+ i) >> (32 - N));
                *(array + i) = *(array + i) << N;
            }
            for(int i = size - 1; i >= 0; i --){
                if(i == 0){
                    *(array + (size - 1)) = *(array + (size - 1)) | temp[i];
                }
                else{
                    *(array + (i - 1)) = *(array + (i -1)) | temp[i];
                }
            }
        }
        else{
            for(int i = 0; i < size; i ++){
                temp[i] = (*(array + i) << (32 - N));
                *(array + i) = *(array + i) >> N;
            }
            for(int i = 0; i < size ; i ++){
                if(i + 1 == size){
                    *(array) = *(array ) | temp[i];
                }
                else{
                    *(array + (i+1)) = *(array + (i+1)) | temp[i];
                }
            }
        }
    }
    else{
        int a = N / 32;
        int count = 0;

        while(count < a){
            if(left == true){
                unsigned int first = *array;

                for(int i = 0; i < size - 1; i++){
                    *(array + i) = *(array + i + 1);
                }

                *(array + (size - 1)) = first;
            }
            else{
                unsigned int last = *(array + (size - 1));

                for(int i = size - 1; i > 0; i--){
                    *(array + i) = *(array + i - 1);
                }

                *array = last;
            }

            count += 1;
        }
        a = N % 32;
        unsigned int temp[size];
        if(left == true){
            for(int i = size - 1; i >= 0; i --){
                temp[i] = (array[i] >> (32 - a));
                *(array + i) = *(array + i) << a;
            }
            for(int i = size - 1; i >= 0; i --){
                if(i == 0){
                    *(array + (size - 1)) = *(array + (size - 1)) | temp[i];
                }
                else{
                    *(array + (i - 1)) = *(array + (i -1)) | temp[i];
                }
            }
        }
        else{
            for(int i = 0; i < size; i ++){
                temp[i] = (*(array + i) << (32 - a));
                *(array + i) = *(array + i) >> a;
            }
            for(int i = 0; i < size ; i ++){
                if(i + 1 == size){
                    *(array) = *(array) | temp[i];
                }
                else{
                    *(array + (i +1)) = *(array + (i+ 1)) | temp[i];
                }
            }
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
