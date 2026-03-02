#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "functii.h"

void *convBinar(int base10){

    int size = 0, placeholder = base10;
    while(placeholder > 0){
        placeholder /= 2;
        size++;
    }

    size+=1; // pentru null terminator al string-ului

    char *base2 = (char *)calloc(size, sizeof(char));

    if(base2 == NULL){
        printf("Error! Memory allocation failed!\n");

        return NULL;
    }

    placeholder = base10;
    int bits = size - 1;
    for(int i = 0; i < bits; i++){
        base2[i] = (placeholder % 2) + '0';
        placeholder /= 2;
    }

    int j = bits - 1;
    for(int i = 0; i < j; i++){
        base2[i] = base2[i] ^ base2[j];
        base2[j] = base2[i] ^ base2[j];
        base2[i] = base2[i] ^ base2[j];
        j--;
    }

    return base2;

}

int convDeci(char *base2, int bits){

    int decimal = 0, j = 0;
    for(int i = bits - 2; base2[i] >= 0; i--){
        if(base2[i] == '1')
            decimal += pow(2, j);

        j++;
    }

    return decimal;

}