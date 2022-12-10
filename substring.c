#include <stdio.h> // printf, file/io
#include <stdlib.h> // malloc
#include <string.h> // strlen


int substring (const char *whole, const char *sub) {
        
    // loop thorugh whole and substring
    
    int flag = 0;
    for (int i = 0; i < strlen(whole); i ++) {
        
        
        for (int j = 0; j < strlen(sub); j ++) {
                
            if (whole[i] != sub[j]) {
                
            }
        }
    }
    
    
    
}



int main () {
    char *s = "helloworld";
    char *s2 = "world";
    int index = substring(s, s2);
    printf("%s\n", index);
}
