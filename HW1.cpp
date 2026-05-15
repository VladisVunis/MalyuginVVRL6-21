#include "HW1.h"
#include <chrono>
#include <string.h>
#include <cstring>
#include <fstream>


int getBest(int* ar, int size, bool (*comp)(int,int)){
    int IndBest = 0;
    for(int i = 1; i < size; i ++){
        if(comp(ar[IndBest], ar[i])){
            IndBest = i;
        }
    }
    return IndBest;
}

bool ascending(int a, int b){
    return a > b;
}

bool descending(int a, int b){
    return a < b;
}

double getTime(meas unit) {
    auto now = std::chrono::high_resolution_clock::now(); // начинает отсчет относительно часов в компьютере
    auto duration = now.time_since_epoch(); // трансформирует время компьютера во время относительно "начальной точки"

    switch (unit) {
    case meas::milli:
        return std::chrono::duration<double, std::milli>(duration).count();

    case meas::micro:
        return std::chrono::duration<double, std::micro>(duration).count();

    case meas::nano:
        return std::chrono::duration<double, std::nano>(duration).count();

    case meas::pico:
        return std::chrono::duration<double, std::pico>(duration).count();
    }

    return 0;
}

void randomFillAr(int* ar, int size, int min, int max){
    for(int i = 0; i < size; i++){
        ar[i] =  min + rand()%(max-min +1);
    }
}

void writeTOP(const char* fileName){
    std::ofstream FILE;
    FILE.open(fileName, std::ios_base::out);
    if (!FILE.is_open()){
    }
    else{
        FILE << "| size | bubble | selection | insertion | merge | quick | shell | count | \n";
        FILE << "|------|--------|-----------|-----------|-------|-------|-------|-------| \n";
    }
    FILE.close();
}

void writeStringToFile(const char* fileName,const char* data){
    static int count = 1;
    std::ofstream FILE;
    FILE.open(fileName, std::ios_base::app);
    if (!FILE.is_open()){
    }
    else{

        if(count ==1){
            FILE << "| " << data << " |";
        }
        else{
            FILE << " " << data << " |";
        }

        if (count == 8){
            FILE << "\n";
            count = 1;
        }
        else{
            count++;
        }
    }
    FILE.close();
}

char* convertDoubleToStr(double number){
    std::string str = std::to_string(number);

    int polozToch = str.find('.');

    if (polozToch != -1 && polozToch + 3 < str.length()) {
        str = str.substr(0, polozToch + 3);
    }

    char* string = new char[str.length() + 1];
    strcpy(string, str.c_str());

    return string;
}

char* convertIntToStr(int number){
    std::string str = std::to_string(number);

    char* string = new char[str.length() + 1];
    strcpy(string, str.c_str());

    return string;
}

int getStep(int size) {
    if (size < 1000) {
        return 100;
    }
    if (size < 10000) {
        return 500;
    }
    if (size < 20000) {
        return 1000;
    }
    if (size < 100000) {
        return 5000;
    }
    if (size < 500000) {
        return 10000;
    }
    if (size < 2000000) {
        return 100000;
    }
    return 500000;
}
