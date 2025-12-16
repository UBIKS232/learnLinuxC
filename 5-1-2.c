#include <stdio.h>
#include <math.h> // -lm

double myround(double x){
    // if(x < 0){
    //     return (x < (ceil(x) - 0.5)) ? floor(x) : ceil(x);
    // }
    // else{
    //     return (x < (ceil(x) - 0.5)) ? floor(x) : ceil(x);
    // }

        return (x < (ceil(x) - 0.5)) ? floor(x) : ceil(x);
}

int main(){

    printf("%f\n", myround(3.6));
    printf("%f\n", myround(4.3));
    printf("%f\n", myround(-2.1));
    printf("%f\n", myround(-9.8));
    printf("%f\n", myround(0));

    return 0;
}