#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int len;
	FILE *fhandler = fopen(argv[0], "r");
	
	if (NULL == fhandler) {
		exit(1);	
	}

	// MOVES TO END OF FILE
	fseek(fhandler, 0, SEEK_END);
	// GETS VALUE OF FILE POSITION,
	len = ftell(fhandler);
	
	char *buffer = malloc(len);

	int read = fread(buffer, sizeof(char), len, fhandler);

	printf("%c", read);

	


	
	fclose(fhandler);
	free(buffer);
	buffer = NULL;
}
