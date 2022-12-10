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


void SortArray(int *A, int N)
{
      
    // SORTING ARRAY
    //Hint: pull your code from 2B 
    int i, j=0, temp =0;
   	
    //(O(N^2))
	for (i = 0; i < N; i++) {
		for (j = i+1; j < N; j++) {
			if (A[j] < A[i]) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}	
		}
	} 
	
}


void DeallocateArray(int *A)
{
    free(A);
}


// DONE WITH RECURSIONS
// TIME COMPLEXITY IS O(nlogn)
// MERGE SORT ALGORITHM
void FastSort(int *A, int N) {
    // BASE CASES
    if (N <= 0) {
        printf("MESSED UP N is <= 0\n ");
        exit(EXIT_FAILURE);
    }
    
    if (N == 1) {
        return;
    }
    
    if (N == 2) {
        if (A[0] > A[1]) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    
    // NOW WE KNOW N IS >= 3
    int *A_left = A;
    int left_size = N/2;

    int *A_right = A+(N/2);
    int right_size = left-size-(N/2);
    
    FastSort(A_left, left_size); // LEFT HALF
    FastSort(A_right, right_size); // RIGHT HALF
    
    // 5 1 7 3
    // 1 5 3 7
    // THE LEFT AND RIGHT HAVE BEEN SORTED
    // NOW WE NEED TO MERGE THE LEFT AND RIGHT INTO ONE SORTED ARRAY
    int si = 0; // INDEX of where to place next elemtn in strach array
    int li = 0;
    int ri = N/2;
}
int main()
{
    
    // RUNNING WITH 8 OR 11 TAKES VERY LONG BECAREFUL
    //int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };
    int sizes[3] = {1000, 2000, 4000};

//For fun:
//int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000 }; 
 

    for (int i = 0 ; i < 3; i++)
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
