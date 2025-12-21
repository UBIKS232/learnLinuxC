// gcc -Wall main.c -o main
// #include <stdio.h>
// int main(){
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

// (11011)2×(10010)2=((11011)2<<1)+((11011)2<<4)
unsigned int multiply(unsigned int x, unsigned int y){
    unsigned int z = 0;
    int cnt = 0;
    while(y){
        if((y & 1) == 1) z += (x << cnt);
        cnt++;
        y = (y >> 1);
    }
    return z;
}

int main(){

    printf("%ld\n", sizeof(int));
    printf("%u\n", multiply(0x1C, 0x12));
    printf("%x\n", multiply(0x1C, 0x12));
    
    return 0;
}