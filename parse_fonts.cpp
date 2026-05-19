#include "parse_fonts.h"
#include "verdana_8_font.h"
#include <iostream>

void parse_font(char symbol, char fill, char background){

    int begin = 0;
    int end = 0;
    int step = 32;
    int count = 1;

    switch(symbol){
    case ' ': {
        begin = 0 * step;
        end = 1 * step - 1;
        break;
    }
    case '!': {
        begin = 1 * step;
        end = 2 * step - 1;
        break;
    }
    case '"': {
        begin = 2 * step;
        end = 3 * step - 1;
        break;
    }
    case '#': {
        begin = 3 * step;
        end = 4 * step - 1;
        break;
    }
    case '$': {
        begin = 4 * step;
        end = 5 * step - 1;
        break;
    }
    case '%': {
        begin = 5 * step;
        end = 6 * step - 1;
        break;
    }
    case '&': {
        begin = 6 * step;
        end = 7 * step - 1;
        break;
    }
    case '\'': {
        begin = 7 * step;
        end = 8 * step - 1;
        break;
    }
    case '(': {
        begin = 8 * step;
        end = 9 * step - 1;
        break;
    }
    case ')': {
        begin = 9 * step;
        end = 10 * step - 1;
        break;
    }
    case '*': {
        begin = 10 * step;
        end = 11 * step - 1;
        break;
    }
    case '+': {
        begin = 11 * step;
        end = 12 * step - 1;
        break;
    }
    case ',': {
        begin = 12 * step;
        end = 13 * step - 1;
        break;
    }
    case '-': {
        begin = 13 * step;
        end = 14 * step - 1;
        break;
    }
    case '.': {
        begin = 14 * step;
        end = 15 * step - 1;
        break;
    }
    case '/': {
        begin = 15 * step;
        end = 16 * step - 1;
        break;
    }

    case '0': {
        begin = 16 * step;
        end = 17 * step - 1;
        break;
    }
    case '1': {
        begin = 17 * step;
        end = 18 * step - 1;
        break;
    }
    case '2': {
        begin = 18 * step;
        end = 19 * step - 1;
        break;
    }
    case '3': {
        begin = 19 * step;
        end = 20 * step - 1;
        break;
    }
    case '4': {
        begin = 20 * step;
        end = 21 * step - 1;
        break;
    }
    case '5': {
        begin = 21 * step;
        end = 22 * step - 1;
        break;
    }
    case '6': {
        begin = 22 * step;
        end = 23 * step - 1;
        break;
    }
    case '7': {
        begin = 23 * step;
        end = 24 * step - 1;
        break;
    }
    case '8': {
        begin = 24 * step;
        end = 25 * step - 1;
        break;
    }
    case '9': {
        begin = 25 * step;
        end = 26 * step - 1;
        break;
    }

    case ':': {
        begin = 26 * step;
        end = 27 * step - 1;
        break;
    }
    case ';': {
        begin = 27 * step;
        end = 28 * step - 1;
        break;
    }
    case '<': {
        begin = 28 * step;
        end = 29 * step - 1;
        break;
    }
    case '=': {
        begin = 29 * step;
        end = 30 * step - 1;
        break;
    }
    case '>': {
        begin = 30 * step;
        end = 31 * step - 1;
        break;
    }
    case '?': {
        begin = 31 * step;
        end = 32 * step - 1;
        break;
    }
    case '@': {
        begin = 32 * step;
        end = 33 * step - 1;
        break;
    }

    case 'A': {
        begin = 33 * step;
        end = 34 * step - 1;
        break;
    }
    case 'B': {
        begin = 34 * step;
        end = 35 * step - 1;
        break;
    }
    case 'C': {
        begin = 35 * step;
        end = 36 * step - 1;
        break;
    }
    case 'D': {
        begin = 36 * step;
        end = 37 * step - 1;
        break;
    }
    case 'E': {
        begin = 37 * step;
        end = 38 * step - 1;
        break;
    }
    case 'F': {
        begin = 38 * step;
        end = 39 * step - 1;
        break;
    }
    case 'G': {
        begin = 39 * step;
        end = 40 * step - 1;
        break;
    }
    case 'H': {
        begin = 40 * step;
        end = 41 * step - 1;
        break;
    }
    case 'I': {
        begin = 41 * step;
        end = 42 * step - 1;
        break;
    }
    case 'J': {
        begin = 42 * step;
        end = 43 * step - 1;
        break;
    }
    case 'K': {
        begin = 43 * step;
        end = 44 * step - 1;
        break;
    }
    case 'L': {
        begin = 44 * step;
        end = 45 * step - 1;
        break;
    }
    case 'M': {
        begin = 45 * step;
        end = 46 * step - 1;
        break;
    }
    case 'N': {
        begin = 46 * step;
        end = 47 * step - 1;
        break;
    }
    case 'O': {
        begin = 47 * step;
        end = 48 * step - 1;
        break;
    }
    case 'P': {
        begin = 48 * step;
        end = 49 * step - 1;
        break;
    }
    case 'Q': {
        begin = 49 * step;
        end = 50 * step - 1;
        break;
    }
    case 'R': {
        begin = 50 * step;
        end = 51 * step - 1;
        break;
    }
    case 'S': {
        begin = 51 * step;
        end = 52 * step - 1;
        break;
    }
    case 'T': {
        begin = 52 * step;
        end = 53 * step - 1;
        break;
    }
    case 'U': {
        begin = 53 * step;
        end = 54 * step - 1;
        break;
    }
    case 'V': {
        begin = 54 * step;
        end = 55 * step - 1;
        break;
    }
    case 'W': {
        begin = 55 * step;
        end = 56 * step - 1;
        break;
    }
    case 'X': {
        begin = 56 * step;
        end = 57 * step - 1;
        break;
    }
    case 'Y': {
        begin = 57 * step;
        end = 58 * step - 1;
        break;
    }
    case 'Z': {
        begin = 58 * step;
        end = 59 * step - 1;
        break;
    }

    case '[': {
        begin = 59 * step;
        end = 60 * step - 1;
        break;
    }
    case '\\': {
        begin = 60 * step;
        end = 61 * step - 1;
        break;
    }
    case ']': {
        begin = 61 * step;
        end = 62 * step - 1;
        break;
    }
    case '^': {
        begin = 62 * step;
        end = 63 * step - 1;
        break;
    }
    case '_': {
        begin = 63 * step;
        end = 64 * step - 1;
        break;
    }
    case '`': {
        begin = 64 * step;
        end = 65 * step - 1;
        break;
    }

    case 'a': {
        begin = 65 * step;
        end = 66 * step - 1;
        break;
    }
    case 'b': {
        begin = 66 * step;
        end = 67 * step - 1;
        break;
    }
    case 'c': {
        begin = 67 * step;
        end = 68 * step - 1;
        break;
    }
    case 'd': {
        begin = 68 * step;
        end = 69 * step - 1;
        break;
    }
    case 'e': {
        begin = 69 * step;
        end = 70 * step - 1;
        break;
    }
    case 'f': {
        begin = 70 * step;
        end = 71 * step - 1;
        break;
    }
    case 'g': {
        begin = 71 * step;
        end = 72 * step - 1;
        break;
    }
    case 'h': {
        begin = 72 * step;
        end = 73 * step - 1;
        break;
    }
    case 'i': {
        begin = 73 * step;
        end = 74 * step - 1;
        break;
    }
    case 'j': {
        begin = 74 * step;
        end = 75 * step - 1;
        break;
    }
    case 'k': {
        begin = 75 * step;
        end = 76 * step - 1;
        break;
    }
    case 'l': {
        begin = 76 * step;
        end = 77 * step - 1;
        break;
    }
    case 'm': {
        begin = 77 * step;
        end = 78 * step - 1;
        break;
    }
    case 'n': {
        begin = 78 * step;
        end = 79 * step - 1;
        break;
    }
    case 'o': {
        begin = 79 * step;
        end = 80 * step - 1;
        break;
    }
    case 'p': {
        begin = 80 * step;
        end = 81 * step - 1;
        break;
    }
    case 'q': {
        begin = 81 * step;
        end = 82 * step - 1;
        break;
    }
    case 'r': {
        begin = 82 * step;
        end = 83 * step - 1;
        break;
    }
    case 's': {
        begin = 83 * step;
        end = 84 * step - 1;
        break;
    }
    case 't': {
        begin = 84 * step;
        end = 85 * step - 1;
        break;
    }
    case 'u': {
        begin = 85 * step;
        end = 86 * step - 1;
        break;
    }
    case 'v': {
        begin = 86 * step;
        end = 87 * step - 1;
        break;
    }
    case 'w': {
        begin = 87 * step;
        end = 88 * step - 1;
        break;
    }
    case 'x': {
        begin = 88 * step;
        end = 89 * step - 1;
        break;
    }
    case 'y': {
        begin = 89 * step;
        end = 90 * step - 1;
        break;
    }
    case 'z': {
        begin = 90 * step;
        end = 91 * step - 1;
        break;
    }

    case '{': {
        begin = 91 * step;
        end = 92 * step - 1;
        break;
    }
    case '|': {
        begin = 92 * step;
        end = 93 * step - 1;
        break;
    }
    case '}': {
        begin = 93 * step;
        end = 94 * step - 1;
        break;
    }
    case '~': {
        begin = 94 * step;
        end = 95 * step - 1;
        break;
    }
    case '\x7F': {
        begin = 95 * step;
        end = 96 * step - 1;
        break;
    }
}


    for(begin; begin <= end; begin++){
        for(int i = 0; i < 8; i++){
            int mask_res;
            mask_res = (font_verdana_8[begin] >> i) & 0b1;
            if(mask_res == 1){
                std::cout << fill;
            }
            else{
                std::cout << background;
            }
        }
        if(count < 2){
            count++;
        }
        else{
            count = 1;
            std::cout << "\n";
        }
    }

}
