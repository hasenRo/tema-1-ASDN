#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "functii.h"

int main(){

    int conv = 0;
    printf("Introdu 0 pentru a face trecerea unui numar zecimal la hexazecimal sau 1 pentru a face trecerea unui numar hexazecimal la unul zecimal: ");

    scanf("%d", &conv);

    if(conv == 0){
        printf("Introdu numarul zecimal: ");
        int base10 = 0;
        scanf("%d", &base10);

        char *base16 = trans_zeciHexi(base10);

        printf("Numarul %d zecimal este %s in hexazecimal.\n", base10, base16);
        free(base16);
    }
    else{
        printf("Introdu numarul de cifre ale numarului hexazecimal: ");
        int size = 0;
        scanf("%d", &size);

        char *base16 = malloc(size + 1);

        printf("Introdu numarul hexazecimal: ");
        getchar();
        fgets(base16, size + 1, stdin);

        int base10 = trans_hexiZeci(base16);

        printf("Numarul %s hexazecimal este %d in zecimal.\n", base16, base10);
    }

    return 0;
}
