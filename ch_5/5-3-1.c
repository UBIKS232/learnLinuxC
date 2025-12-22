/**
 * gcd: gcd(a, b) = gcd(a, b mod a); n mod 0 = n
 */

#include <stdio.h>

int min(int a, int b){
    return (a <= b)? a : b;
}

int max(int a, int b){
    return (a <= b)? b : a;
}

int gcd(int a, int b){
    int m = min(a, b);
    int M = max(a, b);

    if(m == 0){
        return M;
    }
    else{
        return gcd(m, M % m);
    }
}

int main(){
    printf("%d\n", gcd(234, 27));
    printf("%d\n", gcd(3, 6));
    printf("%d\n", gcd(5, 8));
    printf("%d\n", gcd(60, 24));
    printf("%d\n", gcd(1, 1));

    return 0;
}