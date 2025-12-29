#include <stdio.h>

#define LEN 8
#define K 7
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

int partition(int start, int end)
{
    // 从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
    // 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
    // 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，
    // 而a[mid]就是pivot元素;
    int pivot = a[start];
    int i, j, t, mid = start;
    for (i = start + 1; i < end + 1; i++)
    {
        if (a[i] < pivot)
        {
            // printf("\n\ta[i]<pivot: %d\n", i);
            t = a[i];
            for (j = i - 1; j > mid - 1; j--)
            {
                a[j + 1] = a[j];
            }
            a[mid] = t;
            mid++;
        }
        else
        {
            // printf("\n\ta[i]>pivot: %d\n", i);
        }
    }

    printf("mid: %d, pivot: %d, a[mid] = %d\n", mid, pivot, a[mid]);

    return mid;
}

/* 从start到end之间找出第k小的元素 */
int order_statistic(int start, int end, int k)
{
    // 用partition函数把序列分成两半，中间的pivot元素是序列中的第i个;
    int i = partition(start, end);
    if (k == i)
        // 返回找到的元素;
        return a[i];
    else if (k > i)
        // 从后半部分找出第k-i小的元素并返回;
        // k和i是在partition和order内都是绝对索引
        return order_statistic(i + 1, end, k);
    else
        // 从前半部分找出第k小的元素并返回;
        return order_statistic(start, i - 1, k);
}

int main()
{
    for (int j = 0; j< LEN; j++)
    {
        // 第几小是从0开始数的, 写 (K - 1)
        printf("第%d小: %d\n", j + 1, order_statistic(0, LEN - 1, j));
    }
    return 0;
}