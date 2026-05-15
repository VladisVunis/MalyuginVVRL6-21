#ifndef HW1_H
#define HW1_H

enum class meas {
    milli = 1,
    micro = 2,
    nano = 3,
    pico = 4
};

int getBest(int* ar, int size, bool (*comp)(int,int));
bool ascending(int a, int b);
bool descending(int a, int b);

double getTime(meas unit);
void writeStringToFile(const char* fileName, const char* data); //< запись в файл данных
char* convertDoubleToStr(double number); //< конвертирование double в строку
char* convertIntToStr(int number); //< конвертирование int в строку
void randomFillAr(int* ar, int size, int min = -100, int max = 100); //< функция заполнения массива произвольными числами

int getStep(int size);
void writeTOP(const char* fileName);

#endif // HW1_H
