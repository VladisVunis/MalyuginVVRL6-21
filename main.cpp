#include <iostream>

using namespace std;

void swapHalfWord(unsigned int* words){
    int cwords = (*words << 8) | (*words >> 8);
}

int main()
{
    unsigned int w = 0xFFAABBCC;
    swapHalfWord(&w);
    cout << hex << w;
    return 0;
}
