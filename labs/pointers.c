#include <stdio.h>
#include <stdlib.h>

char x;
char *y;

int main() {
	x = 'A';
	y = &x;

	printf("x = %c\n", x);
	printf("*y = %c\n", *y);

	x = 'B';

	printf("*y = %c\n", *y); 
}

