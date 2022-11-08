#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char letter, char *string) {
	
	int i;
	int count;

	z = (int *) malloc(argc * sizeof(int));

	for (i = 0; i <= z; i++) {

		if (letter == string[i]) {
			count += 1;
		}
		printf("%d occurs in %d %d times", letter, string, count);
	}
	
}
