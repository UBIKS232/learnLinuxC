#include <stdio.h>

void increment(int *x)
{
	*x = *x + 1;
    
}

int main(void)
{
	int i = 1, j = 2;
    increment(&i);
    increment(&j);
	printf("%d\n", i); /* i now becomes 2 */
	printf("%d\n", j);/* j now becomes 3 */
	return 0;
}