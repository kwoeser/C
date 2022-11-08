#include <stdio.h>

int main() {

	int comp = 10, e = 500, count = 0, d;

	for (comp; comp <= e; comp += 1){
		count =0;
		for (d = 1; d <= comp; d += 1){
			if (comp % 2 != 0) {
				
				if (comp % d == 0) {
					count += 1;
				}

				if (count > 2) {
					printf("%d is a composite number.\n", comp);
					break;
				}
			}
		}

	}

	

}
