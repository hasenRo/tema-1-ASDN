#include <stdio.h>
#include <stdlib.h>

int main(){

    int base10 = 0;
    scanf("%d", &base10);

    if(base10 == 0){
        printf("0\n");
        return 0;
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
        return 1;
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

    free(base16);
    return 0;
}