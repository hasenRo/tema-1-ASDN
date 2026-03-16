#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functii.h"

char* trans_zeciHexi(int base10){
    if(base10 == 0){
        printf("0\n");
        return "0";
    }

    int size = 0;
    int placeholder = base10;

    while(placeholder > 0){
        placeholder /= 16;
        size++;
    }

    char *base16 = malloc(size + 1);
    if(base16 == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }

    base16[size] = '\0';

    char digits[] = "0123456789ABCDEF";

    placeholder = base10;

    for(int i = size - 1; i >= 0; i--){
        int remainder = placeholder % 16;
        base16[i] = digits[remainder];
        placeholder /= 16;
    }

    printf("%s\n", base16);

    return base16;
};

int trans_hexiZeci(char* base16){
    int base10 = 0;
    char digits[] = "0123456789ABCDEF";

    int factor = strlen(base16) - 1; 
    for(int i = 0; i < strlen(base16); i++){
        for(int j = 0; j < sizeof(digits) / sizeof(char); j++){
            if(base16[i] == digits[j]){
                base10 += j * (int)pow(16, factor);
                factor--;
                break;
            }
        }
    }

    return base10;
};
