#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int len(char *str) {
	int count = 0;
	for (int i = 0; str[i]!='\0'; i++) {
		count ++;
	}
	return count;
}

int main() {
	
	int i;
	int sum = 0;
	char *str = "123";
	//int length = len(str);

	// Iterate through the string until it reachs the null 
	for (i = 0; i < length ; i++) {
		sum = sum * 10 + (str[i] - '0');	
	}


	/*for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] >= '0' && str[j] <= '9') {
			sum = sum * 10 + (str[j] - '0');
		} else { 
			printf("Didn't enter anything that repersents an int");
		}
	}	
	printf("%d\n", sum);*/


}
