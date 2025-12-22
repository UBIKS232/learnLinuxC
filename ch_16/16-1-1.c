// gcc -Wall main.c -o main
#include <stdio.h>

unsigned int a = (unsigned int)32455;

int countbit(unsigned int x){
    // unsigned int: 4B = 32bit

    int cnt = 0;
    while(x){
        x &= x - 1; // !!
        cnt++;
    }

    return cnt;
}


int main(){

    // printf("%ld\n", sizeof(a));
    printf("%d\n", countbit(a));

    return 0;
}