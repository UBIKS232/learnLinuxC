#include <stdio.h>
#include <math.h>

#define DELTA 0.0000001

typedef struct complexRA
{
    double r;
    double A;
} complexRA_t;

// layer 1: how to store
double img(complexRA_t z)
{
    return z.r * sin(z.A);
}

double real(complexRA_t z)
{
    return z.r * cos(z.A);
}

double angle(complexRA_t z)
{
    return z.A;
}

double magnitude(complexRA_t z)
{
    return z.r;
}

complexRA_t initRA(double r, double A)
{
    complexRA_t z;
    z.r = r;
    z.A = A;
    return z;
}

complexRA_t initXY(double x, double y)
{
    complexRA_t z;
    z.r = sqrt(x * x + y * y);
    z.A = asin(y / z.r);
    return z;
}

// layer 2: how to compute
complexRA_t addZ(complexRA_t z1, complexRA_t z2)
{
    return initXY(real(z1) + real(z2), img(z1) + img(z2));
}

complexRA_t subZ(complexRA_t z1, complexRA_t z2)
{
    return initXY(real(z1) - real(z2), img(z1) - img(z2));
}

complexRA_t mulZ(complexRA_t z1, complexRA_t z2)
{
    return initRA(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}

complexRA_t divZ(complexRA_t z1, complexRA_t z2)
{
    return initRA(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void printZ(complexRA_t z)
{
    if (fabs(real(z) - 0) >= DELTA) // double 精度较高, 使用DELTA作为容限吗可改进
    {
        printf("%f", real(z));
        if (img(z) > 0)
        {
            printf("+%fi", img(z));
        }
        if (img(z) < 0)
        {
            printf("%fi", img(z));
        }
    }
    else
    {
        if (img(z) > 0)
        {
            printf("%fi", img(z));
        }
        if (img(z) < 0)
        {
            printf("%fi", img(z));
        }
        if(fabs(img(z) - 0) < DELTA)
        {
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    printf("V1\n");

    complexRA_t z1, z2, z3;
    z1 = initRA(2, 1.047);
    z2 = initXY(0.866, 0.5);
    z3 = initXY(0, 3);

    printZ(z1);
    printZ(z2);
    printZ(z3);

    printZ(addZ(z1, z2));
    printZ(subZ(z1, z2));
    printZ(mulZ(z1, z2));
    printZ(divZ(z1, z2));

    return 0;
}