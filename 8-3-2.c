#include <stdio.h>

#define N 5
#define START 0
#define M 3

int a[N] = {0};
int cnt = 0;

void f(int i)
{
    if (i == M)
    {
        for (int k = 0; k < M; k++)
        {
            printf("%d ", a[k]);
        }
        cnt++;
        printf("\n");
    }
    else
    {
        for (int j = i; j < N; j++)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;

            f(i + 1);

            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
}

int main()
{
    for (int k = 1; k < N + 1; k++)
    {
        a[k - 1] = k;
    }

    f(START);

    printf("count: %d.\n", cnt);

    return 0;
}