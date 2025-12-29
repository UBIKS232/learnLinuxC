#include <stdio.h>

int is_leap_year(int year){
    return ((year % 100) && !(year % 4)) || !(year % 400);
}

int main(){
    printf("%d\n", is_leap_year(2010));
    printf("%d\n", is_leap_year(2004));
    printf("%d\n", is_leap_year(2004));
    printf("%d\n", is_leap_year(2013));
    printf("%d\n", is_leap_year(2400));
    printf("%d\n", is_leap_year(2020));
    printf("%d\n", is_leap_year(2012));
    printf("%d\n", is_leap_year(2000));
    printf("%d\n", is_leap_year(1989));

    return 0;
}