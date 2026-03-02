#include <stdio.h>
#include <stdlib.h>

int main(){

    int base10 = 2000;

    int size = 0, placeholder = base10;
    while(placeholder > 0){
        placeholder /= 2;
        size++;
    }

    size+=1; // pentru null terminator al string-ului

    char *base2 = (char *)calloc(size, sizeof(char));

    if(base2 == NULL){
        printf("Error! Memory allocation failed!\n");
        return 1;
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

    printf('%s', base2);

    return 0;
}