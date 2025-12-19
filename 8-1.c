#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 4, 3, 5}, b[5];
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", b[i]);;
    }
    
    return 0;
}