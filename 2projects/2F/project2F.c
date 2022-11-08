#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    /* Return the length of string s using the C convention of
     * being terminated by the NULL character. 
     * Do not call any other functions whatsoever.
     * Even my_strlen -- no solutions involving recursion. */
    
    int i, count = 0;
    for (i; s[i] != '\0' ; i++) {
        count ++;
    }
    
    // This returns 11?
    return count;
}

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed. 
     * The only function you can call is my_strlen.
     * Do not call malloc.  */
    
    char temp;
    int len = my_strlen(str);

    // Stop at the half way point because otherwise I will just re reverse the it (IMPORTANT)
    int half = len/2;
    for (int i = 0; str[i] != '\0'; i++) {
	if (i == half) {
		break;
	}

	temp = str[i];
	str[i] = str[len - i -1];
	str[len- i - 1] = temp;	
    }
    
}



int main()
{
    char *str = malloc(strlen("hello world")+1);
    strcpy(str, "hello world");
    str_reverse(str);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Project does not work yet.  You reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_FAILURE);
    }
}
