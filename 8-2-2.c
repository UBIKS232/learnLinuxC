#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define UPPER_BOUND 11

int a[N];

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound + 10;
}

int howmany(int value)
{
    int count = 0, i;
    for (i = 0; i < N; i++)
        if (a[i] == value)
            ++count;
    return count;
}

int main(void)
{
    int i;

    srand(time(NULL));
    gen_random(UPPER_BOUND);
    for (i = 0; i < 30; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("value\thow many\n");
    for (i = 10; i < UPPER_BOUND + 10; i++)
        printf("%d\t%d\n", i, howmany(i));

    return 0;
}