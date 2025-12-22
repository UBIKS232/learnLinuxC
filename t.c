#include <stdio.h>

int main() {
    char num[5], anti_num[5];
    scanf("%s", num);
    for(int i = 4; i > 0; i--){
        anti_num[4 - i] = num[i - 1];
    }
    anti_num[4] = '\0';
    printf("%s\n", anti_num);
    return 0;
}