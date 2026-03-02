#include <stdio.h>
#include <math.h>

int main(){

    printf("Introdu numarul de cifre: ");
    int size = 0;
    scanf("%d", &size);

    printf("Introdu cifra hexizecimala: ");
    char base16[size + 1];

    base16[size] = '\0';

    getchar();
    fgets(base16, size + 1, stdin);

    printf("%d\n", size);

    int base10 = 0;
    char digits[] = "0123456789ABCDEF";

    int factor = size - 1; 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < sizeof(digits) / sizeof(char); j++){
            if(base16[i] == digits[j]){
                base10 += j * (int)pow(16, factor);
                factor--;
                break;
            }
        }
    }

    printf("Numarul in baza 10: %d", base10);

    return 0;
}