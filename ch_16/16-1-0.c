#include <stdio.h>

int main(){

    int i = 0xcffffff3;
    printf("%x\n", 0xcffffff3>>2);
    printf("%x\n", i>>2); // gcc将其当作有符号数处理

    return 0;
}
