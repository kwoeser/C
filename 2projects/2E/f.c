#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wordCount(char *buffer, int buff_size, char *findWord) {
	int i, ncmp, word_count = 0;

    
	int wordLen = strlen(findWord);
	char *eachWord;
    
    
   
    
    
        
    /*if (&buffer[i] == " " || &buffer[i] == "," || &buffer[i] == "." || &buffer[i] == "\n") {
            printf("here");
            ncmp = strncmp(findWord, eachWord, wordLen);
            if (ncmp == 0) {
                word_count++;
            }
                
    } */
    
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
                
        
        
        
#if 0
        /* failed attempt #3 */
        /* If we're at the start of a word */
        if (i == 0 || (buffer[i - 1] == ' ' || buffer[i - 1] == '\n' || buffer[i - 1] == ',' || buffer[i - 1] == '.')) {
            letter_count = 0;
            while (letter_count < wordLen && buffer[i] == findWord[letter_count]) {
                letter_count++;
                i++;
            }
            
            /* If we're at the end of a word (or the end of the buffer) */
            if (i == (buff_size - 1)
                    || (buffer[i + 1] == ' ' || buffer[i + 1] == '\n' || buffer[i + 1] == ',' || buffer[i + 1] == '.')) {
                /* If we matched all the characters */
                if (letter_count == wordLen) {
                    word_count ++;
                    /* we're on a word separating character, so skip ahead */
                    i += 2;
                }
            }
        }
#endif /* end of attempt #3 */
            
            /*if (letter_count == wordLen) {
                if (buffer[i - 1] == ' ' || buffer[i - 1] == '\n' || buffer[i - 1] == ',' || buffer[i - 1] == '.' || buffer[i + 1] == ' ' || buffer[i + 1] == '.' || buffer[i + 1] == ',' || buffer[i + 1] == '\n') {
                    word_count ++;
                }
                    
            } */

        /* failed second attempt
        if (start_counting) {
            if (buffer[i] == findWord[letter_count]) {
                letter_count++;
            } else {
                start_counting = 0;
            }
        }
        
        if ((i == (buff_size - 1) || buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == ',' || buffer[i] == '.')) {
            if (start_counting && (letter_count == wordLen)) {
                word_count ++;
            }
            letter_count = 0;
            start_counting = 1;
        }
        end failed second attempt*/
        
            
        /*
            if (check_before && (buffer[i - 1] == ' ' || buffer[i - 1] == '\n' || buffer[i - 1] == ',' || buffer[i - 1] == '.' || buffer[i + 1] == ' ' || buffer[i + 1] == '.' || buffer[i + 1] == ',' || buffer[i + 1] == '\n')) {
                
                if (letter_count == wordLen) {
                    word_count ++;
                } 
                
            }
            
            
            
            
        } else {
            letter_count = 0;
        
        }*/
    }
        
        /*if (temp == " " || temp == "," || temp == "," || temp == "\n" ) {
            ncmp = strncmp(findWord, temp, wordLen);
            if (ncmp == 0) {
                word_count++;
            } else {
                temp = NULL;
                continue;
            }
        }&/
        
    }
    printf("%s", temp);
    
    /*for (i = 0; i < buff_size; i ++) {
        //printf("%c ", buffer[i]);
        
        if (buffer[i] == " " || buffer[i] == "," || buffer[i] == "." || buffer[i] == "\n") {
            ncmp = strncmp(findWord, eachWord, wordLen);
            if (ncmp == 0) {
                word_count++;
            } else {
                continue;
            }
            
    }*/
            
        
	
	
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
    
    // IS THIS NEEDED?
    // char *buffer = malloc(sizeof(char) * buff_size + 1);
	fread(buffer, sizeof(char), buff_size, fhandler);
     	
      	//int number_of_words;
	//char *counter = malloc(sizeof(int) * number_of_words);	
	
	for (i = 2; i < argc; i++) {
        // argv[i] = argv[2 and beyond] 
		printf("The word %s occurs %d times.\n", argv[i], wordCount(buffer, buff_size, argv[i]));	
	}
	

    free(buffer); 
	buffer = NULL;
	fclose(fhandler);
	

}
