#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.0000001

enum coordinate_type
{
    RECTANGULAR,
    POLAR
};
struct complex_struct
{
    enum coordinate_type t;
    double a, b;
};

double real_part(struct complex_struct z)
{
    switch (z.t)
    {
    case RECTANGULAR:
        return z.a;
    case POLAR:
        return z.a * cos(z.b);
    default:
        printf("error type\n");
        // exit(1);
        return 0;
        // break;
    }
}

double img_part(struct complex_struct z)
{
    switch (z.t)
    {
    case RECTANGULAR:
        return z.b;
    case POLAR:
        return z.a * sin(z.b);
    default:
        printf("error type\n");
        // exit(1);
        return 0;
        break;
    }
}

double magnitude(struct complex_struct z)
{
    switch (z.t)
    {
    case RECTANGULAR:
        return sqrt(z.a * z.a + z.b * z.b);
    case POLAR:
        return z.a;
    default:
        printf("error type\n");
        // exit(1);
        return 0;
        // break;
    }
}

double angle(struct complex_struct z)
{
    switch (z.t)
    {
    case RECTANGULAR:
        return atan2(z.b, z.a);
    case POLAR:
        return z.b;
    default:
        printf("error type\n");
        // exit(1);
        return 0;
        // break;
    }
}

struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.t = RECTANGULAR;
    z.a = x;
    z.b = y;
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.t = POLAR;
    z.a = r;
    z.b = A;
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2),
                              img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2),
                              img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) * magnitude(z2),
                             angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitude(z1) / magnitude(z2),
                             angle(z1) - angle(z2));
}

void printZ(struct complex_struct z)
{
    if (fabs(real_part(z) - 0) >= DELTA) // double 精度较高, 使用DELTA作为容限, 可改进
    {
        printf("%f", real_part(z));
        if (img_part(z) > 0)
        {
            printf("+%fi", img_part(z));
        }
        if (img_part(z) < 0)
        {
            printf("%fi", img_part(z));
        }
    }
    else
    {
        if (img_part(z) > 0)
        {
            printf("%fi", img_part(z));
        }
        if (img_part(z) < 0)
        {
            printf("%fi", img_part(z));
        }
        if (fabs(img_part(z) - 0) < DELTA)
        {
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    printf("V2\n");

    struct complex_struct z1, z2, z3;
    z1 = make_from_mag_ang(2, 1.047);
    z2 = make_from_real_img(0.866, 0.5);
    z3 = make_from_real_img(0, 3);

    z3.t = 10; // error handler test

    printZ(z1);
    printZ(z2);
    printZ(z3);

    printZ(add_complex(z1, z2));
    printZ(sub_complex(z1, z2));
    printZ(mul_complex(z1, z2));
    printZ(div_complex(z1, z2));

    return 0;
}