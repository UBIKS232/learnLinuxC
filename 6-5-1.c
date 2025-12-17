#include <stdio.h>

int main(){

    // 99
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= i; j++){
            printf("%d\t", i*j);
        }
        printf("\n");
    }

    return 0;
}