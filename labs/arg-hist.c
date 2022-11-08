#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	for (int i = 0 ; i < argc; i ++) {
		int count = 0;
		for (int j = 0; argv[i][j] != '\0'; j++)  {
			count++;
		}
		printf("%s: %d\n", argv[i], count);
			
	}

}


