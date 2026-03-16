#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functii.h"

int main(){
    int conv = 0;
    printf("Introdu 1 daca vrei sa transformi un numar zecimal in baza 3 sau 0 daca vrei sa transformi un numar in baza 3 intr-un zecimal.\n");
    scanf("%d", &conv);

    if(conv == 1){
        int dec = 0;
        scanf("%d", &dec);

        int placeholder = dec, size = 0;
        while(placeholder > 0){
            placeholder /= 3;
            size++;
        }

        char baza3[size];
        baza3 = Zecimal_InBaza3(dec);

    }

    return 0;
}