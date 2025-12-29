#include <stdio.h>

int main(){

    int x = 17, n = 4; // n != 0

    printf("%d\n", -((-x) / n));
    printf("%d\n", (x + n -1) / n);

    x = 16, n = 4; // n != 0
    printf("%d\n", -((-x) / n));
    printf("%d\n", (x + n - 1) / n);

    return 0;
}