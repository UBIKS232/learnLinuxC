#include <stdio.h>

#define DEBUG()                                                              \
    printf("\tDEBUG: t: %d, i: %d, mid: %d, a[] = ", t, i, mid); \
    k = 0;                                                                   \
    for (k = 0; k < LEN; k++)                                                \
    {                                                                        \
        printf("%d ", a[k]);                                                 \
    }                                                                        \
    printf("\n");

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

int partition(int start, int end)
{
    // 从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
    // 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
    // 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，
    // 而a[mid]就是pivot元素;
    int pivot = a[start];
    int i, j, t, mid = start;
    int k = 0; // DEBUG();
    for (i = start + 1; i < end + 1; i++)
    {
        if (a[i] < pivot)
        {
            printf("\n\ta[i]<pivot: %d\n", i);
            t = a[i];
            DEBUG();
            for (j = i - 1; j > mid - 1; j--)
            {
                a[j + 1] = a[j];
            }
            DEBUG();
            a[mid] = t;
            DEBUG();
            mid++;
        }
        else
        {
            printf("\n\ta[i]>pivot: %d\n", i);
        }
    }

    printf("NORMAL: start: %d, mid: %d, end: %d, a[] = ", start, mid, end);
    for (k = 0; k < LEN; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    return mid;
}

void quicksort(int start, int end)
{
    int mid;
    if (end > start)
    {
        mid = partition(start, end);
        quicksort(start, mid - 1);
        quicksort(mid + 1, end);
    }
}

int main()
{
    quicksort(0, LEN - 1);
    return 0;
}