#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20000


typedef struct
{
    // DATE = KEYS
    //char *keys[MAX_SIZE];
    char **keys;
    // CLOSE PRICE = VALUES
    //float values[MAX_SIZE];
    float *values;
    
} HashTable;


int Hash1(char *key) {
    
    int *keyNum = (int*)key;
    int val = *keyNum % MAX_SIZE;
    
    
    return val;

}


// https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
int count = 0;

int Hash2(char *key) {
    int length = strlen(key);
    const int p = 32;
    int hash_value = 0;
    long p_pow = 1;
    for(int i = 0; i < length; i++) {
        hash_value = (hash_value + (key[i] - '0' + 1) * p_pow) % MAX_SIZE;
        p_pow = (p_pow * p) % MAX_SIZE;
    }
    
    return hash_value;
}

void Initialize(HashTable *ad)
{
    // Implemzent me!
    ad->keys = malloc(MAX_SIZE * sizeof(char*));
    ad->values = malloc(MAX_SIZE * sizeof(float));
    
}

void Store(HashTable *ad, char *key, float value)
{
   // Implement me!
    int idx = Hash1(key);
    int idx2 = Hash2(key);
    
    int index = (idx + idx2) % MAX_SIZE;
    
    
    if (index >= MAX_SIZE) {
        exit(EXIT_FAILURE);
    } else {
        ad->keys[index] = key;
        ad->values[index] = value;
    }    
    
    
}



float Fetch(HashTable *ad, char *key)
{
   // Implement me!
    int idx = Hash1(key);
    int idx2 = Hash2(key);
    
    int index = (idx + idx2) % MAX_SIZE;
    //int length = strlen(key);
    for (int i = 0; i < index; i++) {
        if (strncmp(ad->keys[i], key, index) == 0) {
            return ad->values[i];
        }
        

            
    }
    
   return 0.;
}



int main()
{
    FILE *f = fopen("DJIA", "r");
    
    if (f == NULL)
    {
         fprintf(stderr, "Unable to open file \"DJIA\" ... did you copy it to the current directory?\n");
         exit(EXIT_FAILURE);
    }
    
    

    HashTable ad;
    Initialize(&ad);

    //
    //  Step 1: parse the file and place contents in the Dictionary.
    //  The key should be the date (a char *)
    //  The value should be the closing price.  (look at DJIA for more info)
    //
    size_t size = 1024;
    char *buffer = malloc(size*sizeof(char));
    

    char *date = malloc(80);
    float Open, High, Low, closePrice;
    
    while (getline(&buffer, &size, f) > 0)
    {
        
        // Hint 1: sscanf is great.  Turn that line into numbers!
        
        sscanf(buffer, "%s %f %f %f %f", date, &Open, &High, &Low, &closePrice);
        
        // Hint 2: be very careful about what you send in to Store.
        //         The memory at buffer will be changing, so you can't
        //         use that.  Big hint: strdup
        
        
        char *str;
        str = strdup(date);
       
        Store(&ad, str, closePrice);
        
    }

    
    //
    //  For each data, do a fetch.
    //  For each returned closing price, add it to a running sum.
    //  Your goal is ultimately to get the average closing price over
    //  all of the dates in the file.
    //
    char dates[91][10] = {
                 "02/19/21", "02/19/20", "12/19/19", "12/12/19", "12/02/19", "11/22/19", "11/12/19", "10/22/19", "10/02/19", 
                 "09/12/19", "08/22/19", "08/12/19", "08/02/19", "07/22/19", "07/12/19", "07/02/19", "06/12/19", "05/22/19", 
                 "05/02/19", "04/22/19", "04/12/19", "04/02/19", "03/22/19", "03/12/19", "02/22/19", "02/19/19", "02/12/19", 
                 "01/22/19", "01/02/19", "12/19/18", "12/19/17", "12/19/16", "02/19/16", "02/19/15", "12/19/14", "02/19/14", 
                 "12/19/13", "02/19/13", "12/19/12", "12/19/11", "02/19/10", "02/19/09", "12/19/08", "02/19/08", "12/19/07", 
                 "12/19/06", "12/19/05", "02/19/04", "12/19/03", "02/19/03", "12/19/02", "02/19/02", "12/19/01", "12/19/00", 
                 "02/19/99", "02/19/98", "12/19/97", "02/19/97", "12/19/96", "12/19/95", "12/19/94", "02/19/93", "02/19/92", 
                 "12/19/91", "02/19/91", "12/19/90", "12/19/89", "12/19/88", "02/19/88", "02/19/87", "12/19/86", "02/19/86", 
                 "12/19/85", "02/19/85", "12/19/84", "12/19/83", "02/19/82", "02/19/81", "12/19/80", "02/19/80", "12/19/79", 
                 "12/19/78", "12/19/77", "02/19/76", "12/19/75", "02/19/75", "12/19/74", "02/19/74", "12/19/73", "12/19/72", 
                 "02/19/71"
           };
    
   
    float sum = 0.;
    for (int i = 0 ; i < 91 ; i++)
    {
        
        printf("%d\n", i);
        //THIS IS THE CLOSING PRICE
        float val = Fetch(&ad, dates[i]);
        
        if (val == 0.)
        {
            printf("badfetch = %f ||| Bad fetch!\n", val);
            exit(EXIT_FAILURE);
        }
        
        sum += val;
    }
    
    // Uncomment this.  Note it assumes you called your sum variable "sum"
    printf("Over the 91 days, the average value was %d\n", (int)(sum/91.0));
    // It should print:
    //    Over the 91 days, the average value was 13209
    
    fclose(f);
    
    
}



