#include <iostream>
#include "sorts.h"

int main()
{
    int arr[] = {110, 6, -10, 4 ,-22, 77};
    selectionSort(arr, 6, true);
    for(int i = 0;i < 6; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";

    return 0;
}
