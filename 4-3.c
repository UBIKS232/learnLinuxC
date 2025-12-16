#include <stdio.h>

void judgeXY(int x, int y)
{
    if (x > 0 && x < 10)
        ;
    else
        printf("x is out of range.\n");
    if ((x <= 0) || (x >= 10))
        ;
    else
        printf("x is out of range.\n");

    if (x > 0)
        printf("Test OK!\n");
    else if (x <= 0 && y > 0)
        printf("Test OK!\n");
    else
        printf("Test failed!\n");

    if (x <= 0 && y <= 0)
        printf("Test failed!\n");
    else
        printf("Test OK!\n");

    // if (x < 3 && y > 3)
    //     printf("Test OK!\n");
    // else if (x >= 3 && y >= 3) //!!??
    //     printf("Test OK!\n");
    // else if (z > 3 && x >= 3)
    //     printf("Test OK!\n");
    // else if (z <= 3 && y >= 3)
    //     printf("Test OK!\n");
    // else
    //     printf("Test failed!\n");
}

int main()
{
    judgeXY(2, 0);
    judgeXY(1, 1);
    judgeXY(23, 1);
    return 0;
}