#include <stdio.h>

int absolute_value(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else if (x > 0)
    {
        return x;
    }
}

int main()
{
    printf("%d\n", absolute_value(-3));
    printf("%d\n", absolute_value(6));
    printf("%d\n", absolute_value(0)); // return value 2 is err
    printf("%d\n", absolute_value(0));
    printf("%d\n", absolute_value(0));

    return 0;
}