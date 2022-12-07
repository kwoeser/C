#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

int *AllocateArray(int N)
{
    /* Allocate an array with N integers.
     * The value of each element of the array should be a
     * random number between 0 and 10N.
     * Hint: use the rand() function and a modulo operator.
     */
    
    int *array = malloc(sizeof(int) * N);
    
    // O(N)
    for (int i = 0; i < N; i++) {
        array[i] = rand() % (10 * N);
    }
    
    return array;

}


	
int intCompare(const void *a, const void *b) {
    int *a_as_int = (int *) a;
    int *b_as_int = (int *) b;
}
	
void SortArray(int *A, int N)
{
      
//     SORTING ARRAY
//     Hint: pull your code from 2B 
//     int i, j=0, temp =0;
//    	
//     (O(N^2))
// 	for (i = 0; i <= N; i++) {
// 		for (j = i+1; j <= N; j++) {
// 			if (A[j] < A[i]) {
// 				temp = A[i];
// 				A[i] = A[j];
// 				A[j] = temp;
// 			}	
// 		}
// 	} 
    
    
    // WAY FASTER THEN BUBBLE SORT 
    qsort(A, N, sizeof(int), intCompare);
    
	
}


void DeallocateArray(int *A)
{
    free(A);
}



int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };
    //int sizes[3] = {1000, 2000, 4000};

//For fun:
    //int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000 }; 
 

    for (int i = 0 ; i < 8; i++)
    {
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;

        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */
        
        //gettimeofday(&startTime, &endTime);
        printf("Timings for array of size %d\n", sizes[i]);
        
        
        gettimeofday(&startTime, 0);
        int *arr = AllocateArray(sizes[i]);
        gettimeofday(&endTime, 0);
        //tv_sec seconds
        //tv_usec microseconds
        alloc_time =  (endTime.tv_sec - startTime.tv_sec) +  (endTime.tv_usec - startTime.tv_usec) /1000000.;
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);

  
        gettimeofday(&startTime, 0);
        SortArray(arr, sizes[i]);
        gettimeofday(&endTime, 0);
        sort_time = (endTime.tv_sec - startTime.tv_sec) +  (endTime.tv_usec - startTime.tv_usec) /1000000.;
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
      
        
        gettimeofday(&startTime, 0);
        DeallocateArray(arr);
        //DeallocateArray(sizes);
        gettimeofday(&endTime, 0);
        dealloc_time = (endTime.tv_sec - startTime.tv_sec) +  (endTime.tv_usec - startTime.tv_usec) /1000000.;
        printf("\tTime for deallocation is %g\n", dealloc_time);
    }
    
}
