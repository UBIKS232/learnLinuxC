#include <stdio.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void)
{
    // enum coordinate_type { RECTANGULAR = 1, POLAR };
	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}

/*
RECTANGULAR 最先寻找main内的定义(ch3.4):
1: 
7-3-2.c: In function ‘main’:
7-3-2.c:8:13: error: ‘RECTANGULAR’ redeclared as different kind of symbol
    8 |         int RECTANGULAR;
      |             ^~~~~~~~~~~
7-3-2.c:7:28: note: previous definition of ‘RECTANGULAR’ with type ‘enum coordinate_type’
    7 |     enum coordinate_type { RECTANGULAR = 1, POLAR };
      |                            ^~~~~~~~~~~
2: 
7-3-2.c: In function ‘main’:
7-3-2.c:9:9: warning: ‘RECTANGULAR’ is used uninitialized [-Wuninitialized]
    9 |         printf("%d %d\n", RECTANGULAR, POLAR);
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/