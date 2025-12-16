#include <stdio.h>

void getX(int x){
    int a, b;
    a = x / 10;
    b = x % 10;
    printf("十位: %d, 个位: %d\n", a, b);
}

int main(){
    getX(7);
    getX(11);
    getX(125);
    getX(55);
    getX(-23);
    getX(-329);
    getX(-3);
    return 0;
}