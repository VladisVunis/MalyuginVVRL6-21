#include <fstream>
#include <time.h>
#include <iostream>

void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements){
    std::ofstream DIM;
    DIM.open(fileName, std::ios_base::out);
    if (!DIM.is_open()){
        std::cout << "error" << std::endl;
    }
    else{
        if(countElements % cols == 0){
            for(int Ncount = 0; Ncount != countElements ;Ncount += cols ){
                for(int NScount = 0; NScount != cols; NScount++){
                    if(cols == NScount + 1){
                        int x = min + rand()%(max-min +1);
                        DIM << x << std::endl;
                    }
                    else{
                        int x = min + rand()%(max-min +1);
                        DIM << x << delimeter;
                    }
                }

            }
        }
        else{
            int count = 0;
            for(int Ncount = 0; Ncount < (countElements/cols)*cols; Ncount += cols){
                count += cols;
                for(int NScount = 0; NScount < cols; NScount++){
                    if(cols == NScount + 1){
                        int x = min + rand()%(max-min +1);
                        DIM << x << std::endl;
                    }
                    else{
                        int x = min + rand()%(max-min +1);
                        DIM << x << delimeter;
                    }
                }

            }
            for(int c = count ; c < countElements; c++){
                int x = min + rand()%(max-min +1);
                DIM << x << delimeter;
            }
        }
        DIM.close();
    }
}
