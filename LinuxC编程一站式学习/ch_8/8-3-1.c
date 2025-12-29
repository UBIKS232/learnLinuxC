#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int a[N];

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
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
    int i, histogram[10] = {0};

    // srand(time(NULL));
    gen_random(10);
    for (int i = 0; i < N; i++)
        histogram[a[i]]++; // !!

    printf("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t\n\n");
    for (int i = 0; i < N; i++) // 上限最好取histogram里的最大值
    {
        for (int j = 0; j < 10; j++)
        {
            if(histogram[j] == 0){
                // printf(" ");
            }
            else{
                printf("*");
                histogram[j]--;
            }
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}