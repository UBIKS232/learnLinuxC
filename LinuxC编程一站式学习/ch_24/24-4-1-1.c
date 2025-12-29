/* main.c */
#include <stdio.h>
#include "24-4-1-1.h"

int main(void)
{
     printf("%s %s\n", get_a_day(1), get_a_day(0));
     printf("%s %s\n", get_a_day(0), get_a_day(1)); // printf内的函数从右到左求值
     return 0;
}