#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    int bits = 8;
    bits += 1;
    char base2[bits];

    strcpy(base2, "11001000");
    
    int decimal = 0, j = 0;
    for(int i = bits - 2; i >= 0; i--){
        if(base2[i] == '1')
            decimal += pow(2, j);

        j++;
    }

    printf("%d", decimal);

    return 0;
}