#include <stdio.h>

int min(int a, int b){
    return (a <= b)? a : b;
}

int max(int a, int b){
    return (a <= b)? b : a;
}

int fibonacci(int n)
{
    switch (n)
    {
    case 0:
    case 1:
        return 1;
    default:
        return fibonacci(n - 1) + fibonacci(n - 2);
        break;
    }
}

int main(){

    int n = 13, a = 234, b = 27;

    // gcd
    int x = a, y = b;
    while(min(x, y) != 0){
        int t_x = x, t_y = y;
        x = min(t_x, t_y);
        y = max(t_x, t_y) % min(t_x, t_y);
    }
    printf("gcd(%d, %d) = %d\n", a, b, max(x, y));

    // fib
    int i = 0, fib = 0, fib_1 = 1, fib_2 = 1;
    while(i <= n){
        if(i == 0 || i == 1){
            fib = 1;
        }
        else{
            fib = fib_1 + fib_2;
        }
        fib_2 = fib_1;
        fib_1 = fib;
        i++;
    }
    printf("fibonacci, loop: %d, recursive: %d\n", fib, fibonacci(n));

    return 0;
}