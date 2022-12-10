#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome(char *str) {
	// Palidrome is a word that is the same when reversed
	// level, radar, civil
	// Check if the first character is equalivent to the last character
	

	// Finds length of the string
	int count = 0, flag = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count ++;
	}
	
	// NULL CHARACTER IS MATCHED WITH START IF THERE IS NO -1
    int end = count - 1;
	for (int j = 0; j < count; j ++) {
		// Check if first character is same as the last charcter
		if (str[j] != str[end--]) {
            flag = 1;
            break;		
        } 
			

    } 
	

	if (flag == 1) {
		printf("The word %s is not a palindrome\n", str);	
		
	} else {
		printf("The word %s is a palindrome\n", str);			
	}

}


// int workingPalindrome(char *str) {
// 
// 
// 	int start = 0;
// 	int flag = 0;
// 	int end = strlen(str) - 1;
// 	while (end > start) {
// 		Can't do + 1 because it won't check 0
// 		if (str[start++] != str[end--]) {
// 			flag = 1;
// 			break;
// 		} 
// 	}
// 
// 	if (flag == 1) {
// 		printf("NO");
// 	} else {
// 		printf("YES");
// 	}
// }


int main () {
	char *word1 = "pe";
	char *word2 = "madam";
	palindrome(word1);
	palindrome(word2);
}
