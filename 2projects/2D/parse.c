#include <stdio.h>
#include <stdlib.h>

double stringtodouble(char *str) {
	int i, j, c;
	double result;
	int num = 0;
	for (i = 0; str[i] != '\0'; i++) {

		if (str[i] == '.') {
			for (j = 0; str[j] != '\0'; j++) {	
				num = num * 10 + (str[j] - 48);	
				if (num < 0) {
					// num = num * 10 + (str[j] + 30);
					result = num * -1;
					continue;
				} else {
					result = num;
					continue;
				}
			
			}
		

		} else {
			for (c = 0; str[c] != '\0'; c++) {
				num = num * 10 + (str[c] - 48);
				if (num < 0) {
					result = num * -1;
					break;
				} else {
					result = num;
					break;
				}
			}
		}

	
		

					
		
	}	
	
}

int main(int argc, char *argv[]) {

	double v = stringtodouble(argv[1]);

	printf("%f\n", v);
} 
