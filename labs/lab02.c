#include <stdio.h>


int main() {
	int hour = 15;
	

	// Conditionals
	if (hour < 12) {
		printf("Good Morning\n");
	} 
	
	else if (hour >= 12 && hour < 18) {
		printf("Good Afternoon\n");
	}

	else if (hour >= 18) {
		printf("Good Night\n");
	}
	

	

	int i = 0;	
	
	// For Loops
	for (i; i <= 10; i++) {

		if (i % 2 == 0) {
			printf("For loop: %d\n", i);
		}
	}

	
	// While loops
	
	int w = 0;	
	while (w <= 10) {

		if (w % 2 == 0) {
			printf("While loop: %d\n", w);

		}
		w += 1;
	}
}



