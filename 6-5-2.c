#include <stdio.h>

int iabs(int x){
    if(x <= 0) return -x;
    else return x;
}

void diamond(int n, char ch){
    if(((n % 2) == 0) || (ch == 0)) {
        printf("invalid value.\n\n");
        return;
    }
    int i = 1, d1 = 0, d2 = 0;
    for(; i <= n; i++){
        d1 = iabs(i - ((n + 1) / 2));
        d2 = iabs(n - d1 * 2);
        for(int j = 0; j < d1; j++){
            // printf("t");
            printf("\t");
        }
        for(int j = 0; j < d2; j++){
            // printf("%c", ch);
            printf("%c\t", ch);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(){
    diamond(3, '+');
    diamond(7, '#');
    diamond(13, 'o');
    diamond(13, 0);
    diamond(2, '.');
    return 0;
}