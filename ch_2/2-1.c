#include <stdio.h>

int main(){
    printf("Hello Linux: %d.\n", 23);
    printf("Bye,\acruel world.\r\n\n");
    printf("Bye,\tcruel\b world.\b\b\b\n");
    printf("Bye,\fcruel world.\n");
    printf("test: \\%, \%, %d, %c, %s, %f, %c\n", 'H', 'e', "llo", 2.72, 57);
    printf("test: \\, %%, %d, %c, %s, %f, %c\n", 'H', 'e', "llo", 2.72, 57);
    return 0;
}