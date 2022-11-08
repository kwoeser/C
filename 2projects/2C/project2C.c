#include <stdio.h>
#include <stdlib.h>

int main() {
	int *A = malloc(sizeof(int) * 21);
	int *B[3] = {A, A+7, A+14};
	int i;
	
	printf("(A+7) - (A+2) = %d\n", (A+7) - (A+2));
	printf("A[7] = %d\n", A[7]);
	

	printf("*A = %d\n", *A);
	printf("B[1][4] = %d\n", B[1][4]);
	printf("*(A+4) = %d\n", *(A+4));
	printf("(A+6) = %d\n", (A+6));
	printf("B[2][0] - B[1][6] = %d\n", B[2][0] - B[1][6]);
	printf("B[2][0] - B[1][7] = %d\n", B[2][0] - B[1][7]);
	printf("*(A+5) - *(A+3) = %d\n", *(A+5) - *(A+3));
	printf("A[5] - *(A+4) = %d\n", A[5] - *(A+4));
	printf("(A+12) - B[1] = %d\n", (A+12) - B[1]);
	printf("B[1] = %d\n", B[1]);	
	printf("B[2][3] - A[16] = %d\n", B[2][3] - A[16]);
	printf("&(B[2][3]) - &(A[15]) = %d\n", &(B[2][3]) - &(A[15]));
	printf("*(&[6]) = %d\n", *(&A[6]));	
	printf("B[3] - B[1] = %d\n", B[3] - B[1]);	
	
	



	free(A);

}
