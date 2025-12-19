#include <stdio.h>

#define ALL 7
#define PART 4

int a[ALL] = {0};
// int used[ALL] = {0};
int p[PART] = {0};
int cnt = 0;

void f(int i, int next)
{
    if (i == PART)
    {
        for (int j = 0; j < PART; j++)
        {
            printf("%d ", p[j]);
        }
        cnt++;
        printf("\n");
    }
    else
    {
        // for (int k = i; k < ALL; k++)
        // {
        //     for (int j = 0; j < ALL; j++)
        //     {
        //         if (used[j] == 1)
        //         {
        //             // continue; // 无事发生 ʕ•ᴥ•ʔ
        //         }
        //         else
        //         {
        //             p[i] = a[j];
        //             used[j] = 1;
        //             break;
        //         }
        //     }
        //     f(i + 1);
        // }
        for (int k = next; k < ALL; k++)
        {
            p[i] = a[k];
            f(i + 1, k + 1);
        }
    }
}

int main()
{
    for (int k = 1; k < ALL + 1; k++)
    {
        a[k - 1] = k;
    }

    f(0, 0);

    printf("count: %d.\n", cnt);

    return 0;
}