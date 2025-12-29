#include <stdio.h>

char a[4][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
                   {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
                   {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
                   {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};

int main()
{
    char (*pa)[2] = &a[1][0]; // {'g', 'h'}
    char (*ppa)[3][2] = &a[1]; // {{'g', 'h'}, {...}, {...}}

    printf("ppa: %c pa: %c\n", *(*(*(ppa+1)+2)+1), *(*(pa+5)+1));
    printf("ppa: %c pa: %c\n", (*(ppa+1))[2][1], (*(pa+5))[1]);
    printf("ppa: %c pa: %c\n", *(ppa+1)[2][1], *(pa+5)[1]); // noway, [] 比 * 先计算

    return 0;
}