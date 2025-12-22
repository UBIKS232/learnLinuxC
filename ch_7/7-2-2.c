#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b);
int max(int a, int b);
int gcd(int a, int b);

typedef struct rationalNum
{
    int h;
    int l;
} rational;

// layer 1: storage
int ratNumH(rational rn)
{
    return rn.h;
}

int ratNumL(rational rn)
{
    if (rn.l == 0)
        exit(1);
    return rn.l;
}

rational make_rational(int h, int l)
{
    rational rn = {h, l};
    if (ratNumH(rn) * ratNumL(rn) < 0)
    // make_rational(-fabs(ratNumH(rn)), fabs(ratNumL(rn))) ... 不小心写成递归了
    {
        rn.h = -fabs(ratNumH(rn));
        rn.l = fabs(ratNumL(rn));
    }
    else
    {
        rn.h = fabs(ratNumH(rn));
        rn.l = fabs(ratNumL(rn));
    }

    return rn;
}

// layer 2: compute
rational simplify_rational(rational rn)
{
    return make_rational(ratNumH(rn) / gcd(ratNumH(rn), ratNumL(rn)), ratNumL(rn) / gcd(ratNumH(rn), ratNumL(rn)));
}

rational add_rational(rational a, rational b)
{
    rational rn = {
        .h = ratNumH(a) * ratNumL(b) + ratNumH(b) * ratNumL(a),
        .l = ratNumL(a) * ratNumL(b)};
    return simplify_rational(rn);
}

rational sub_rational(rational a, rational b)
{
    rational rn = {
        .h = ratNumH(a) * ratNumL(b) - ratNumH(b) * ratNumL(a),
        .l = ratNumL(a) * ratNumL(b)};
    return simplify_rational(rn);
}

rational mul_rational(rational a, rational b)
{
    rational rn = {
        .h = ratNumH(a) * ratNumH(b),
        .l = ratNumL(a) * ratNumL(b)};
    return simplify_rational(rn);
}

rational div_rational(rational a, rational b)
{
    rational rn = {
        .h = ratNumH(a) * ratNumL(b),
        .l = ratNumL(a) * ratNumH(b)};
    return simplify_rational(rn);
}

// ?
void print_rational(rational rn)
{
    if (ratNumH(rn) == ratNumL(rn))
    {
        printf("1");
    }
    else if (ratNumH(rn) == -ratNumL(rn))
    {
        printf("-1");
    }
    else if (ratNumH(rn) != 0)
    {
        printf("%d/%d", ratNumH(rn), ratNumL(rn));
    }
    else
    {
        printf("0");
    }

    printf("\n");
}

int main(void)
{
    rational a = make_rational(1, 8);  /* a=1/8 */
    rational b = make_rational(-1, 8); /* b=-1/8 */
    print_rational(add_rational(a, b));
    print_rational(sub_rational(a, b));
    print_rational(mul_rational(a, b));
    print_rational(div_rational(a, b));

    return 0;
}

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int max(int a, int b)
{
    return (a <= b) ? b : a;
}

int gcd(int a, int b)
{
    a = fabs(a);
    b = fabs(b);
    int m = min(a, b);
    int M = max(a, b);

    if (m == 0)
    {
        return M;
    }
    else
    {
        return gcd(m, M % m);
    }
}