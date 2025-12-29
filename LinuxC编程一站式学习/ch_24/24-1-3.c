#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    char *p;
    const uint32_t SIZE = 1024U * 1024U;

    while(1){
        p = malloc(SIZE);
        if(p == NULL) exit(1);
    }

    return 0;
}