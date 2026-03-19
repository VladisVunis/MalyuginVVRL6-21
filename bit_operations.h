#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

void swapHalfWord(unsigned int* words);
void cycleShift(unsigned int* number, int N, int left);
int getMaxBit(const int* array, int N);
unsigned char getCount1Bit(int number);
void showArray(int *arr, int size);
void cycleShiftArray(unsigned int *array, int size, int N, bool left);
void setBit(int* number, int numBit);
void clearBit(int* number, int numBit);
void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements);
#endif // BIT_OPERATIONS_H
