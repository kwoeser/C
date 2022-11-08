#include <stdio.h>
#include <stdlib.h>

int main () {


	char *src = "hello";
	char *dest = "goodbye";
	int count = 0;

	for (int i = 0; src[i] != '\0'; i++) {
		count ++;
	}

	char *temp;
	for (int j = 0; j < count; j++) {
		temp[j] = src[j];
	}
	dest = temp;
	printf("%c", dest);

}
