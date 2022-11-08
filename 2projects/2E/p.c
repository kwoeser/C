#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wordCount(char *buffer, int buff_size, char *findWord) {
	int i, word_count = 0;

	int wordLen = strlen(findWord);
    
    int letter_count = 0;
    
    for (i = 0; i< buff_size; i++) {
        
        if (buffer[i] == findWord[letter_count]) {
            letter_count++;
        } else {
            char current;
            if (i < buff_size - 1) {
                current = buffer[i];
            } else {
                current = ' ';
            }
            
            char previous;
            if (i > 0) {
                previous = buffer[i - letter_count - 1];
            } else {
                previous = ' ';
            }
            
            if ((current == ' ' || current == '\n' || current == ',' || current == '.') &&
                (previous == ' ' || previous == '\n' || previous == ',' || previous == '.') &&
                letter_count == wordLen) {
                word_count++;
                //printf("%s at character position: %d\n", findWord, i);
            }
            letter_count = 0;
        }
                


    }

            
	return word_count;

} 





int main (int argc, char *argv[]) {
	int i, buff_size;
	
	// argv[0] is the project name
	// argv[1] is the textfile 
	// argv[2 and beyond] are the arguemnts  
	FILE *fhandler = fopen(argv[1], "r");
	
	if (NULL == fhandler) {
		printf("%s is not a valid file.\n", argv[1]);
		exit(1);
	}

	fseek(fhandler, 0, SEEK_END);
	buff_size = ftell(fhandler);
	fseek(fhandler, 0, SEEK_SET);
    
	// STORES CONTENTS OF THE FILE	
	char *buffer = malloc(sizeof(char) * buff_size);
	fread(buffer, sizeof(char), buff_size, fhandler);
     	
    
    /*int num_of_words;
    for(int i = 2; i < argc; i++) {
        num_of_words = strlen(argv[i]);
        
    }*/
    
    
    int *counter = malloc(sizeof(int) * argc);
    
 

    
    /*printf("%s\n", counter);*/

    
	for (i = 2; i < argc; i++) {
        //argv[i] = argv[2 and beyond] 
        counter[i] = wordCount(buffer, buff_size, argv[i]);
        printf("The word %s occurs %d times.\n", argv[i], counter[i]);	

		//printf("The word %s occurs %d times.\n", argv[i], wordCount(buffer, buff_size, argv[i]));	
        
	}
	

    free(buffer); 
	buffer = NULL;
    free(counter);
    counter = NULL;
	fclose(fhandler);
	

}
