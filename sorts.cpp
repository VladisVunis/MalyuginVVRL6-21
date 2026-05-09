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

void selectionSort(int* arr,unsigned int size, bool ascending){
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

int isSorted(const int* arr,unsigned int size){
    int a = 0;
    int i = 1;
    if(arr[i-1] >= arr[i]){
        a = -1;
        for(int i = 1; i < size; i++ ){
            if(arr[i-1] >= arr[i]){
                a = -1;
            }
            else{
                a = 0;
                break;
            }
        }

    }
    else if(arr[i-1] <= arr[i]){
        a = 1;
        for(int i = 1; i < size; i++ ){
            if(arr[i-1] <= arr[i]){
                a = 1;
            }
            else{
                a = 0;
                break;
            }
        }
    }
    return a;
}


// ------------HW1------------


bool ascending(int a, int b){
    return a > b;
}
bool descending(int a, int b){
    return a < b;
}

void bubbleSort(int* ar, int size, bool (*comp)(int, int)){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-1-i; j++){
            if(comp(ar[j], ar[j+1])){
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

int getBest(int* ar, int size, bool (*comp)(int,int)){
    int IndBest = 0;
        for(int i = 1; i < size; i ++){
        if(comp(ar[IndBest], ar[i])){
                IndBest = i;
        }
    }
        return IndBest;
}

void selectionSort(int* ar, int size, bool (*comp)(int,int)){
    for (unsigned int i = 0; i < size; i++) {
        int c = getBest(ar, size - i, comp);
        std::swap(ar[i], ar[c]);
    }
}

void insertionSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 1; i < size; i++) {
        int key = ar[i];
        int j = i - 1;

        while (j >= 0 && comp(ar[j], key)) {
            ar[j + 1] = ar[j];
            j--;
        }

        ar[j + 1] = key;
    }
}

void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int)) { // сбор неделимых участков
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* L = new int[size1];
    int* R = new int[size2];

    for (int i = 0; i < size1; i++) {
        L[i] = ar[left + i];
    }

    for (int j = 0; j < size2; j++) {
        R[j] = ar[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < size1 && j < size2) {
        if (comp(L[i], R[j])) {
            ar[k] = R[j];
            j++;
        } else {
            ar[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < size1) {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        ar[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortRecursive(int* ar, int left, int right, bool (*comp)(int, int)) { // разделение массива на неделимые участки
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortRecursive(ar, left, mid, comp);
    mergeSortRecursive(ar, mid + 1, right, comp);

    merge(ar, left, mid, right, comp);
}

void mergeSort(int* ar, int size, bool (*comp)(int, int)) { // вызов всей функции сортировки слиянием
    if (size <= 1) {
        return;
    }

    mergeSortRecursive(ar, 0, size - 1, comp);
}
