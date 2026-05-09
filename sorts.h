#ifndef SORTS_H
#define SORTS_H

int getMin(const int* arr, int size);
int getMax(const int* arr, int size);
void selectionSort(int* arr,unsigned int size, bool ascending);
int isSorted(const int* array, unsigned int size);

void bubbleSort(int* ar, int size, bool (*comp)(int, int));

void selectionSort(int* ar, int size, bool (*comp)(int,int));

void insertionSort(int* ar, int size, bool (*comp)(int,int));

void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int)); // сборка неделимых кусков памяти и их одновременная сортировка
void mergeSortRecursive(int* ar, int left, int right, bool (*comp)(int, int));// разделение памяти до неделимых кусков
void mergeSort(int* ar, int size, bool (*comp)(int, int)); // функция сортировки слиянием, состоящая из деления до неделимых кусков, и затем ее сборка с учетом величины каждого куска
#endif // SORTS_H
