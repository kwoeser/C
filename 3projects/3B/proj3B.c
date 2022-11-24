/* 
The timing for hash table's are heavily based on your hash functions. When I used very weak hash functions like {key % MAX_SIZE} it caused a lot of collisions. The hash function from the Sventek book was the fastest hash function to use but it always caused a small number of collisions. I took that into consideration and looked for another polynomial hash function on the internet. After doing some research I found that the djb2 and polynomial rolling hash functions were the most efficent string hash functions to use for double hashing. They had a fast execution time and also caused 0 collisions.The MAX_SIZE for the Array dict or hashtable can't be lower the amount of items you want to store. But if you change the MAX_SIZE for the Hashtable or Array dict to around a cap of 695000. The timings for both increase by a minuscule amount. The timings for both become around 0.013000 assuming we are fetching 91 keys. Nothing to insane. But where Hashtables vary from Array dicts is the when you fetch. The Hash Table has a time complexity of O(1). While the Array Dict has a time complexity of O(N). No matter many items we need to fetch using the hashtable the timing always stays the same. The average execution time I got for my hash table fetch was around 0.000053. And that average never changed no matter how many items I had to fetch.

AVERAGE PROGRAM EXECUTION TIME (Hash Table 3B)
Fetching 91 keys = 0.010000
Fetching 182 keys = 0.010000
Fetching 364 keys = 0.010000
Fetching 728 keys = 0.010000
Fetching 1456 keys = 0.010000
Fetching 2912 keys = 0.010000
Fetching 5824 keys = 0.010000

AVERAGE PROGRAM EXECUTION TIME (Array Dict 3A)
Fetching 91 keys = 0.011000
Fetching 182 keys = 0.010000
Fetching 364 keys = 0.020000
Fetching 728 keys = 0.26256
Fetching 1456 keys = 0.40974
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_SIZE 20000

typedef struct
{    
    char *keys[MAX_SIZE]; // Store keys
    float values[MAX_SIZE]; // Function pointer for fetch
    
} HashTable;



//https://stackoverflow.com/questions/7666509/hash-function-for-string
unsigned long Hash1(unsigned char *key)
{
    unsigned long hash = 5381;
    int c;

    while (c = *key++)
        hash = ((hash << 5) + hash) + c; 

    return hash % MAX_SIZE;
}

//https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
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
 



void Initialize(HashTable *htd)
{
    // Initalizes all the keys to NULL and values to -1
    for (int i = 0; i < MAX_SIZE; i++) {
        htd->keys[i] = NULL;
        htd->values[i] = -1.;
        
    }
    
}

void Store(HashTable *htd, char *key, float value)
{
   
    int firstHash = Hash1(key);
    int secondHash = Hash2(key);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        int idx = (firstHash + (i * secondHash)) % MAX_SIZE;
            
        if (htd->keys[idx] == NULL) {
                
            htd->keys[idx] = key;
            htd->values[idx] = value;
            return;
        }
        
//         if (i == MAX_SIZE - 1) {
//             printf("%s\n", htd->keys[idx]);
//         }
            
    }
    
    exit(EXIT_FAILURE);
   
        
}
    
    



float Fetch(HashTable *htd, char *key)
{
   
    int firstHash = Hash1(key) % MAX_SIZE;
    int secondHash = Hash2(key);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        int idx = (firstHash + (i * secondHash)) % MAX_SIZE;
        
        if (htd->keys[idx] == NULL) {
            continue;
        }
        
        if (strcmp(htd->keys[idx], key) == 0) {
            return htd->values[idx];
        }
        
    }
    
    exit(EXIT_FAILURE);
}



int main()
{
    
    clock_t start, end;
    double execution_time;
    start = clock();
    
    FILE *f = fopen("DJIA", "r");
    
    if (f == NULL)
    {
         fprintf(stderr, "Unable to open file \"DJIA\" ... did you copy it to the current directory?\n");
         exit(EXIT_FAILURE);
    }
    
    

    HashTable htd;
    Initialize(&htd);

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
       
        Store(&htd, str, closePrice);
        
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
        // You will need to repeat the code from the last while loop to get the data as a "char *"
        
        
        //THIS IS THE CLOSING PRICE
        float val = Fetch(&htd, dates[i]);
        
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
    
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken to execute: %f\n", execution_time);
    
    
}



