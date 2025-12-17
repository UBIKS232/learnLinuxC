#include <stdio.h>

int main(){
    int i = 1, cnt = 0;
    while (i <= 100)
    {
        // if(((i % 10) == 9) || ((i / 10) == 9)) cnt++;
        // if(((i % 10) == 9) && ((i / 10) == 9)) cnt++;
        if((i % 10) == 9) cnt++;
        if((i / 10) == 9) cnt++;
        i++;
    }
    printf("%d\n", cnt);
    return 0;
}