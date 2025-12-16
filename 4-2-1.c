
#include <stdio.h>

int main()
{
    double i = 21.5;
    double j = i / 7.0;
    if (j * 7.0 == i)
        printf("Equal.\n");
    else
        printf("Unequal.\n");
}