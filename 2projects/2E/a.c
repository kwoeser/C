#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int *argv[]) {

	FILE *fp = fopen(argv[0], "r");
	
	if (NULL == fp) {
		printf("File not opening\n");
	}
	
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);

	char *buffer = malloc(len);
	fread(buffer, sizeof(char), len, fp);


	for (int i = 1; i < len, i ++) {
		if (argv[i] ==  "./") {
			continue;
		}

		c = fgets(argv[i], strlen(argv[i]), fp); 
		if (c != NULL ) {
			puts(argv[i]);
		}
	}


	fclose(fp);
	return 0;

}
