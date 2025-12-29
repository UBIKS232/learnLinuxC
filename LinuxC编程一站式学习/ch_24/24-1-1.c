#include <stdio.h>

char* user_strcpy(char* dest, const char* src);

int main(){
    char buf[20] = {0};
    char source[] = "Merry Christmas!";

    printf("%s\n", user_strcpy(buf, source));

    return 0;
}

char* user_strcpy(char* dest, const char* src){
    char *tmp = dest;

    while((*(dest++) = *(src++)) != '\0');// = 表达式的值

    return tmp;
}