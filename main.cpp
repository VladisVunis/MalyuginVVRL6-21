#include <iostream>
#include "bit_operations.h"
#include <fstream>
#include <time.h>
#include "sorts.h"
#include "file_operations.h"
//#include "fraction.h"

#define NAME 1// RK = 1/HW = 2/ SW = 3
#define COUNT 1 // номер работы
#define NUMBER 1 // номер задания
#if NAME == 1 && COUNT == 1
#include "rk_1.h"
#endif

#define BOX_VERSE 0
#if BOX_VERSE == 1
#include "box.h"
#elif BOX_VERSE == 2
#include "rk_1.h"
#elif BOX_VERSE == 0
#endif
struct Fraction {
    int _numerator; //< числитель
    int _denominator; //< знаменатель
    Fraction(){
        _numerator = 1;
        _denominator = 1;
    };
    Fraction(int numerator, int denominator){
        _numerator = numerator;
        _denominator = denominator;
    }
};

std::ostream& operator<<(std::ostream& out, const Fraction& FR){
    out << FR._numerator;
    out << "/";
    out << FR._denominator;
    return out;
}
void EVKLID(Fraction& frt){
    int a = frt._numerator;
    int b = frt._denominator;
    int ost = 0;
    if(b ==0){
        return;
    }
    if(a == 0){
        frt._denominator = 1;
        return;
    }
    a = abs(a);
    b = abs(b);
    if(abs(a) > abs(b)){
        while( abs(b) != 0){
            ost = abs(a)%abs(b);
            a = b;
            b = ost;
        }
        frt._numerator = frt._numerator/a;
        frt._denominator = frt._denominator/a;
    }
    else{
        while( abs(a) != 0){
            ost = abs(b)%abs(a);
            b = a;
            a = ost;
        }
        frt._numerator = frt._numerator/b;
        frt._denominator = frt._denominator/b;
    }
    if(frt._denominator < 0){
        frt._numerator = frt._numerator*-1;
        frt._denominator = frt._denominator* -1;
    }
}

Fraction sum(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2 + a2 * b1;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;
}

Fraction sub(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2 - a2 * b1;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;
}

Fraction div(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * b2;
    fr0._denominator = b1 * a2;
    EVKLID(fr0);
    return fr0;

}

Fraction mul(const Fraction& fr1, const Fraction& fr2){
    int a1 = fr1._numerator;
    int b1 = fr1._denominator;
    int a2 = fr2._numerator;
    int b2 = fr2._denominator;
    Fraction fr0;
    fr0._numerator = a1 * a2;
    fr0._denominator = b1 * b2;
    EVKLID(fr0);
    return fr0;

}



using namespace std;

int main()
{
    Fraction fr1(10, 20);
    Fraction fr2(-5, 7);
    std::cout << sum(fr1, fr2) << std::endl;
    std::cout << sub(fr1, fr2) << std::endl;
    std::cout << div(fr1,fr2) << std::endl;
    std::cout << mul(fr1, fr2) << std::endl;



#if BOX_VERSE == 2
    const struct Box temp(15);
    std::cout << temp;

    const struct Box temp1;
    std::cout << temp1;

    const struct Box temp2(5,10,11);
    std::cout << temp2;
#endif

    /*Fraction test(10, 15);
    int res = fracReduction(test);
    if (res == -1) {
        std::cerr << "errror..." << std::endl;
    }
    std::cout << test._numerator << "/" << test._denominator << std::endl;*/

#if BOX_VERSE == 1
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
