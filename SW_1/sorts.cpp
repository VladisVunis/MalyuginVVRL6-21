#include <iostream>
#include <utility>

int getMax(int *arr,int size ){
    int indM = 0;
    for(int i = 1;i < size; i++){
        if(arr[indM] < arr[i]){
            indM = i;
        }
    }
    return indM;
}

int getMin(int *arr,int size ){
    int indm = 0;
    for(int i = 1;i < size; i++){
        if(arr[indm] > arr[i]){
            indm = i;
        }
    }
    return indm;
}

void selectionSort(int* arr, int size, bool ascending){
    if(ascending){
        for(int i = 0; i < size ; i++){
            int c = getMax(arr, size-i);
            std::swap(arr[size-1-i], arr[c]);
        }
    }
    else{
        for(int i = 0; i < size ; i++){
            int c = getMin(arr, size-i);
            std::swap(arr[c], arr[size-1-i]);
        }
    }
}
