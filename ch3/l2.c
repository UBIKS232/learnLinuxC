#include <stdio.h>

void newline(void) // void newline()
{
    printf("\n");
}

void threeline(void)
{
    newline(); // !!newline(1);
    newline();
    newline();
}

int main(void)
{
    printf("Three lines:\n");
    threeline();
    printf("Another three lines.\n");
    threeline();
    return 0;
}