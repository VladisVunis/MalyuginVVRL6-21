#include <iostream>

#define NAME 3// RK = 1/HW = 2/ SW = 3
#define COUNT 3 // номер работы
#define NUMBER 1 // номер задания

#if NAME == 1 && COUNT == 1
#include "rk_1.h"
#elif  NAME == 3 && COUNT == 4
#include "fraction.h"
#include "box.h"
#elif NAME == 3 && COUNT == 3
#include "bit_operations.h"
#include "file_operations.h"
#elif NAME == 3 && COUNT == 2
#include "bit_operations.h"
#elif NAME == 3 && COUNT == 1
#include "sorts.h"
#endif


using namespace std;

int main()
{
#if NAME == 1 && COUNT == 1 && NUMBER == 1
    Fraction fr1(10, 20);
    Fraction fr2(-5, 7);
    std::cout << sum(fr1, fr2) << std::endl;
    std::cout << sub(fr1, fr2) << std::endl;
    std::cout << div(fr1,fr2) << std::endl;
    std::cout << mul(fr1, fr2) << std::endl;
#endif

#if NAME == 1 && COUNT == 1 && NUMBER == 2
    const struct Box temp(15);
    std::cout << temp;

    const struct Box temp1;
    std::cout << temp1;

    const struct Box temp2(5,10,11);
    std::cout << temp2;
#endif

#if NAME == 3 && COUNT == 4 && NUMBER == 2
    Fraction test(10, 15);
    int res = fracReduction(test);
    if (res == -1) {
        std::cerr << "errror..." << std::endl;
    }
    std::cout << test._numerator << "/" << test._denominator << std::endl;
#endif

#if NAME == 3 && COUNT == 4 && NUMBER == 1
    Box box;
    Box* temp = new Box();

    temp->_len = 1;
    temp->_width = 2;
    temp->_height = 3;
    temp->_color = 0x00FF00FF;
    writeToFile("STR",*temp );
    delete temp;
    temp = nullptr;
    Box* temp1 = new Box();
    readFromFile("STR", *temp1);
    cout << temp1->_len <<endl;
    cout << temp1->_width <<endl;
    cout << temp1->_height <<endl;
    cout << std::hex << temp1->_color <<endl;
    delete temp1;
    temp1 = nullptr;
#endif
#if NAME == 3 && COUNT == 3 && NUMBER == 3
    srand(time(nullptr));
    fillFile("set", 10, 20, '\t', 7, 12);
#endif

#if NAME == 3 && COUNT == 3 && NUMBER == 2
    int number = 0x80000001;

    setBit(&number, 8);
    cout << hex << number << endl;



    clearBit(&number, 0);
    cout << hex << number << endl;
#endif

#if NAME == 3 && COUNT == 3 && NUMBER == 1
    unsigned int ar[4] = {0x80000001u, 0x00, 0x80, 0x10};
    int size = 4;
    bool f = true;

    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    std::cout << std::endl;

    cycleShiftArray(ar, 4, 1, f);
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }
#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 1
    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w << endl;
#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 2
    unsigned int Pnumber = 0x80000801;
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber/2 << endl;
#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 3
    int ar[5] = { 0x0FFFFFFF, (int) 0xFFFFFFFF, 0x00, 0x0FFFFFFF};
    int index = 0;
    index = getMaxBit(ar,4);
    cout << index<< endl;
#endif

#if NAME == 3 && COUNT == 2 && NUMBER == 4
    int num = -10;
    unsigned char amount = getCount1Bit(num);
    cout << (int)amount << endl;
#endif

#if NAME == 3 && COUNT == 1 && NUMBER == 1 || NUMBER == 2
    int arr[] = {110, 6, -10, 4 ,-22, 77};
    selectionSort(arr, 6, true);
    for(int i = 0;i < 6; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n";
    int v = isSorted(arr, 6);
    std::cout<<v<<"\n";
#endif

    return 0;

}
