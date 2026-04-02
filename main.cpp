#include <iostream>
#include "bit_operations.h"
#include <fstream>
#include <time.h>
#include "sorts.h"
#include "file_operations.h"
#include "box.h"
#include "fraction.h"

using namespace std;


int main()
{

    Fraction test(10, 15);
    int res = fracReduction(test);
    if (res == -1) {
        std::cerr << "errror..." << std::endl;
    }
    std::cout << test._numerator << "/" << test._denominator << std::endl;


    /*Box box;
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

    /*srand(time(nullptr));
    fillFile("set", 10, 20, '\t', 7, 12);*/

    /*int number = 0x80000001;

    setBit(&number, 8);
    cout << hex << number << endl;

    cout<<"------------"<<endl;

    clearBit(&number, 0);
    cout << hex << number << endl;

    unsigned int ar[4] = {0x80000001u, 0x00, 0x80, 0x10};
    int size = 4;
    bool f = true;
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    cout<<"------------"<<endl;

    unsigned int ar[] = {0x40, 0x00, 0x80, 0x01};
    bool f = true;

    cycleShiftArray(ar, 4, 1, f);
    for(int i = 0; i < 4; i++){
        std::cout << "x"<< i+1<< " = " << std::hex << ar[i] << std::endl;
    }

    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w << endl;

    cout<<"------------"<<endl;

    unsigned int Pnumber = 0x80000801;
    cycleShift(&Pnumber, 3, 0);
    cout << hex << Pnumber/2 << endl;

    cout<<"------------"<<endl;

    int ar[5] = { 0x0FFFFFFF, (int) 0xFFFFFFFF, 0x00, 0x0FFFFFFF};
    int index = 0;
    index = getMaxBit(ar,4);
    cout << index<< endl;

    cout<<"------------"<<endl;

    int num = -10;
    unsigned char amount = getCount1Bit(num);
    cout << (int)amount << endl;

    -----------

    //int arr[] = {0, 0, 0, 0 ,0, 0};
    int arr[] = {110, 6, -10, 4 ,-22, 77};
    //selectionSort(arr, 6, true);
    for(int i = 0;i < 6; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    int v = isSorted(arr, 6);
    std::cout<<v<<"\n";



*/




    return 0;
}
