// gcc -Wall main.c -o main

#include <stdio.h>

unsigned int rotate_right(unsigned int x, int cnt){
    unsigned int i = 0;
    for(int j = cnt; j > 0; j--){
        i = x & 1;
        x = x >> 1;
        x = (i << 31) + x;
    }
    return x;
}


int main(){

    printf("%x\n", rotate_right(0xdeadbeef, 16)); // 例子给错了吗

    return 0;
}