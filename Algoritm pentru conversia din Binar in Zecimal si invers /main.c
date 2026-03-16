#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "functii.h"

int main(){

    int conv = 0;
    printf("Introdu 1 daca vrei sa faci trecerea de la zecimal in binar sau 0 daca vrei sa faci trecerea de la binar in zecimal: ");
    scanf("%d", &conv);


    if(conv == 1){
        printf("Introdu numarul zecimal: ");
        int base10 = 0;
        scanf("%d", &base10);

        char *base2 = "\0";
        base2 = convBinar(base10);

        if(base2==NULL){
            printf("Eroare de alocare de memorie!\n");
            return 1;
        }

        printf("Numarul %d in binar: %s\n", base10, base2);

        free(base2);

    }

    else if(conv == 0){
        printf("Introdu numarul de bits al numarului binar: ");
        int bits = 0;
        scanf("%d", &bits);
        getchar();

        bits += 1;

        char base2[bits]; //spatiu in plus pentru null terminator
        printf("Introdu numarul binar: ");
        fgets(base2, sizeof(base2), stdin);

        int base10 = 0;
        base10 = convDeci(base2, bits);

        printf("Numarul %s in zecimal: %d", base2, base10);

    }
    

    return 0;
}
