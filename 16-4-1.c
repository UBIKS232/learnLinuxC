#include <stdio.h>

int main()
{
    int i = 0;
    unsigned int sum = 0;
    for (; i < 16; i++)
        sum = sum + 1U << i; // + 优先于 <<
    printf("%x\n", sum);

    return 0;
}