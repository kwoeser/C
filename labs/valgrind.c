#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

  //Type of error:  
  int i;
  int *a = (int*)malloc(sizeof(int) * 10);
  if (!a) {
	return -1; /*malloc failed*/
  }
  for (i = 0; i < 11; i++){
    a[i] = i;
  }
  free(a);

  
  //Type of error: 
  int *b;
  for (i=0; i < 10; i++){
    b = malloc(sizeof(int) * 100);
    free(b);
  }
  //free(b);

  //Type of error: Didnt free memory (c)
  int c[10];
  for (i = 0; i < 9; i++)
    c[i] = i;
    
  for (i = 0; i < 10; i++){
    printf("%d ", c[i]);
  }
  printf("\n");
  return 0;
}





