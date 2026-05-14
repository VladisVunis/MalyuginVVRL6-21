#include "task_filo.h"

bool test_brackets(const char* brackets){

    int size=0;
    for(int i = 0; brackets[i] != '\0'; i++){
        size++;
    }

    FILO filo(size);
    int value;

    for(int i = 0 ; i < size; i++){

        if(brackets[i] == '(' || brackets[i] == '<'
            || brackets[i] == '[' || brackets[i] == '{'){

            filo.putToEnd(brackets[i]);
        }

        else if(brackets[i] == ')' || brackets[i] == '>'
                 || brackets[i] == '}' || brackets[i] == ']'){

            if(filo.getFromEnd(&value) == ErrorFilo::empty){
                return false;
            }

            if(value == '(' && brackets[i] == ')'){
                continue;
            }
            else if(value == '{' && brackets[i] == '}'){
                continue;
            }
            else if(value == '[' && brackets[i] == ']'){
                continue;
            }
            else if(value == '<' && brackets[i] == '>'){
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(filo.getFromEnd(&value) == ErrorFilo::empty){
        return true;
    }
    else{
        return false;
    }
}
