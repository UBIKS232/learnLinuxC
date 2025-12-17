#include <stdio.h>

// try -std=c89, -std=c99; C89下, for内定义int i会报错

int fib(int n)
{
    switch (n)
    {
    case 0:
    case 1:
        return 1;
    default:
        return fib(n - 1) + fib(n - 2);
        break;
    }
}

int main()
{
    for(int i = 0; i < 10; i++){
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}