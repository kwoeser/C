#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Palidrome
int main() {

	char *str = "level1";
	int isNotPal = 0;
	int i;

	int len = strlen(str);

	for (i = 0; i < len; i++) {
	
		if (str[i] != str[len - i - 1]) {
			isNotPal = 1;
			break;
		}

	}
	if (isNotPal == 1) {
		printf("Is a not a palidrome\n");
	} else {
		printf("Is a palidrome\n");
	}





}	



