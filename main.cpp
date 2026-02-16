#include <iostream>

using namespace std;

int main()
{
    short a;
    cout << "napishite dlinnu massiva: ";
    cin>> a ;
    int arr[a];
    char c;
    cout << "kak hotite zapolnit? Sami(S)/Auto(A): ";
    cin >> c;
    switch (c){
    case 'S': for(int i = 0; i<a; i++){
            cout << "vvedite chlen [" << i + 1 << "]:";
            cin >> arr[i];
        } break;
    case 'A': for(int i =0; i<a; i++){
            arr[i] = -100 + rand() % 100;
        }break;
    }
    cout << "CHECK:"<< endl;
    for(int i = 0; i<a; i++){
        cout<< "chlen[" << i+1 << "]: "<<arr[i]<<endl;
    }
    for(int i = 1; i<a-1;i++){
        int Imin = 0;
        for(int j = i+1; j<a;j++){
            if(arr[j]< arr[Imin]){
                Imin = j;
            }
        }
        if(Imin != i){
            swap(arr[i], arr[Imin]);
        }
    }
    cout << endl << "OTSORTIROV. by Choice:"<< endl;
    for(int i = 0; i<a; i++){
        cout<< "chlen[" << i+1 << "]: "<<arr[i]<<endl;
    }

    return 0;
}
