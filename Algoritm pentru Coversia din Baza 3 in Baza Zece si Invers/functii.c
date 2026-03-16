#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functii.h"

int baza3_InZecimal(char* base3){
    int size = strlen(base3);

    int base10 = 0, factor = 4, digit = 0;
    for(int i = 0; i < size; i++){
        digit = (base3[i]) - 48;
        base10 += digit * pow(3, factor);

        factor--;
    }

    return base10;
}

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* Zecimal_InBaza3(int base10){
    int size = 0, placeholder = base10;
    while(placeholder > 0){
        placeholder /= 3;
        size++;
    }
    
    char *base3 = malloc(size + 1);
    base3[size] = '\0';

    char digits[] = {'0', '1', '2'};

    placeholder = base10;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < sizeof(digits) / sizeof(char); j++){
            if(placeholder % 3 == j){
                base3[i] = digits[j];
                break;
            }
        }
        placeholder /= 3;
    }

    int j = size - 1;
    for(int i = 0; i < j; i++){
        swap(&base3[i], &base3[j]);
        j--;
    }

    return base3;
}
