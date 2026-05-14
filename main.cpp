#include <iostream>

#define NAME 3// RK = 1/HW = 2/ SW = 3
#define COUNT 6 // номер работы
#define NUMBER 2 // номер задания

/*enum NAME{
    SW = 3,
    RK = 1,
    HW = 3,
};*/

#include "test.h"

#if NAME == 1 && COUNT == 1
#include "box.h"
#include "fraction.h"
#elif NAME == 3 && COUNT == 6
#include "ring_buffer.h"
#include "filo.h"
#include "task_filo.h"
#include "test_ring_buffer.h"
#elif NAME == 3 && COUNT == 5
#include "bit_operations.h"
#include "box.h"
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
#if NAME == 3 && COUNT == 6 && NUMBER == 2

RUN_TEST(test_ring_buffer_empty);
RUN_TEST(test_ring_buffer_push_back_full);
RUN_TEST(test_ring_buffer_get_front_full);

#endif

#if NAME == 3 && COUNT == 6 && NUMBER == 4

bool res;
res = test_brackets("()(){<<>>[]}");
std::cout << res << std::endl;

#endif
#if NAME == 3 && COUNT == 6 && NUMBER == 3

    FILO filo(8);

    for (int i = 0; i < 8; i++) {
        if (filo.putToEnd(i + 1) != ErrorFilo::ok) {
            ASSERT(0);
        }
    }

    filo.showElements();

    ASSERT(filo.putToEnd(10) == ErrorFilo::full);

    filo.flush();

    for (int i = 0; i < 3; filo.getFromEnd(nullptr), i++);

    filo.showElements();

    while(filo.getFromEnd(nullptr) != ErrorFilo::empty);

    filo.showElements();

#endif

#if NAME == 3 && COUNT == 5 && NUMBER == 1

        Box* temp[10];
        temp[0] = new Box(10, 12, 13);
        std::cout << *temp[0]; // [1] = {10, 12, 13} = 1560
        temp[1] = new Box(1, 2, 3);
        std::cout << *temp[1]; // [2] = {1, 2, 3} = 6
        delete temp[1];
        temp[2] = new Box(1, 2, 3);
        std::cout << *temp[2]; // [2] = {1, 2, 3} = 6
        delete temp[0];
        temp[3] = new Box(1, 2, 3);
        std::cout << *temp[3]; // [3] = {1, 2, 3} = 6
        temp[0] = new Box(2, 3, 4);
        std::cout << *temp[0]; // [4] = {2, 3, 4} = 24
        Box temp_1(1,2,2);
        std::cout << temp_1; // [5] = {1, 2, 2} = 4
        delete temp[0];
        delete temp[3];
        delete temp[2];

#endif

#if NAME == 3 && COUNT == 5 && NUMBER == 2

    int a = 0x101;
    bool res0 = isPalindromNumber(a);
    cout << res0 << endl;

#endif

#if NAME == 1 && COUNT == 1 && NUMBER == 2

    Fraction fr1(10, 20);
    Fraction fr2(-5, 7);
    std::cout << sum(fr1, fr2) << std::endl;
    std::cout << sub(fr1, fr2) << std::endl;
    std::cout << div(fr1,fr2) << std::endl;
    std::cout << mul(fr1, fr2) << std::endl;

#endif

#if NAME == 1 && COUNT == 1 && NUMBER == 1

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

#if NAME == 3 && COUNT == 1 && (NUMBER == 1 || NUMBER == 2)

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
