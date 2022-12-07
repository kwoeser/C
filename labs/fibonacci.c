#include <stdio.h>
#include <time.h>
#include <math.h>
#include<stdlib.h>

unsigned long fibonacci(unsigned long n){
	/*
	 * Solve for F(n) recursively
	 */
    
    
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
    
}
// O(2^n)



unsigned long improved_fibonacci(unsigned long n){
	/*
	 * Solve recurrence relation to get F(n)
	 */
    
    long *arr = malloc(sizeof(long) * n);
    
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
//     if (arr[0] == 0) {
//         return 0;
//     } else if (arr[1] == 1) {
//         return 1;
//     }
    
    return arr[n - 1] + arr[n - 2];

    
}
//  

int main(){
	unsigned long n;
	clock_t t;
	printf("Give me an int n to print to: ");
	scanf("%ld", &n);

// 	t = clock();
// 	printf("F(n) acquired recursively: %ld\n", fibonacci(n));
// 	t = clock()- t;
// 	printf("Time taken to execute recursively: %f\n",((double)t)/CLOCKS_PER_SEC);
	
	printf("\n");

	t = clock();
	printf("F(n) acquired by solving recurrence relation: %ld\n", improved_fibonacci(n));
	t = clock()- t;
	printf("Time taken to execute using solved method: %f\n",((double)t)/CLOCKS_PER_SEC);
	return 1;
}
