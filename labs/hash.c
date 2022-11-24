#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int hash(char *s) {
    
    for (int i = 0; i < strlen(s); i++) {
        
    }
    return 0.;
    
}


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "usage: %s inputFile\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *f = fopen(argv[1], "r");
  
  
  if (f == NULL)
  {
    fprintf(stderr, "%s: %s: cannot open file\n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }

  
  char *line = malloc(80 * sizeof *line);
  size_t n = 80;
  int rv = getline(&line, &n, f);

  while (rv > -1) {
	printf("%s", line);
	rv = getline(&line, &n, f);	
  }
  

    
        

	

}
