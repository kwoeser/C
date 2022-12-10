/* CS 212 Project: Donations (2022)
   ~Always appreciated, never expected, non-refundable~

   Author: S. Isaac Geronimo Anderson (Fall 2022)
   */

#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strcmp */

/* Do not change these values for your submission. */
#define QUEUE_SIZE 12  /* Note: Works with 12 on 3C-input.txt */
#define BLOOD_TYPES 4
#define LINE_LENGTH 80

/* Your code goes below this line. */

struct queue
{
  /* Add your struct members here. */
  int front; 
  int back;
  int population;
  //char **strings;
  //char *strings[QUEUE_SIZE];
  //int num_elements;
  
  char *elements[QUEUE_SIZE];
};

typedef struct queue Queue;



void initializeQueue(Queue *q) {
    q->population = 0;
    q->front = 0;
    q->back = 0;
	
}

void enqueue(char *str, Queue *q) {
    if (q->population > QUEUE_SIZE) {
            printf("QUEUE IS FULL\n");
            exit(EXIT_FAILURE);
    }
    
	q->elements[q->back] = str;
    q->back = (q->back + 1) % QUEUE_SIZE;
	q->population++;
    
    // front is the first one to go and back
    // is just now added on
}


char *dequeue(Queue *q) {
    
    char *rs = q->elements[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->population --;
    return rs;
    
}

char *checkFront (Queue *q) {
    
    return q->elements[q->front];
}

char *checkBack (Queue *q) {
    
    return q->elements[q->back];
}

/* Your code goes above this line. */




/* Here is a suggested helper function for checking blood type
   compatibility. */
int isDonorToRecipient(char *donor, char *recipient)
{
  // If donor blood type is O or donor and recipient
  if (strcmp(donor, "O") == 0 || strcmp(donor, recipient) == 0)
    return 1;
  
  // If donor blood type is A and recipient blood type is AB
  if (strcmp(donor, "A") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  
  // If donor blood type is B and recipient blood type is AB
  if (strcmp(donor, "B") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  
  
  return 0;
}


/* Uncomment printQueue and prettyPrintQueue when your queue struct
   and functions are implemented. */


void printQueue(struct queue *q)
{

  printf("Printing queue %p\n", q);
  printf("\tThe index for the front of the queue is %d\n", q->front);
  printf("\tThe index for the back of the queue is %d\n", q->back);
  if (q->population == 0)
  {
    printf("\tThe queue is empty.\n");
  }
  else
  {
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("\t\tEntry[%d]: \"%s\"\n", index, q->elements[index]);
    }
  }

}

/*
void prettyPrintQueue(struct queue *q, char *label, char *type)
{
  if (q->population == 0)
  {
    printf("No unmatched entries for %s (%s)\n", label, type);
  }
  else
  {
    printf("Unmatched %s (%s):\n", label, type);
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("%s\n", q->strings[index]);
    }
  }
}
*/


int main(int argc, char **argv)
{
  /***  STEP #1: Implement your queue code and test it.  ***/

  /* This test code: */
//   struct queue *q = malloc(sizeof (struct queue));
//   initializeQueue(q);
//   printQueue(q);
//   enqueue("hello", q);
//   printQueue(q);
//   enqueue("world", q);
//   printQueue(q);
//   printf("Dequeue: %s\n", dequeue(q));
//   printQueue(q);
//   free(q);
  
  /* Gives this output (with different pointers):

Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 0
	The queue is empty.
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 1
		Entry[0] = "hello"
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 0
	The index for the back of the queue is 2
		Entry[0] = "hello"
		Entry[1] = "world"
Dequeue: hello
Printing queue 0x7fff5e6878a8
	The index for the front of the queue is 1
	The index for the back of the queue is 2
		Entry[1] = "world"
  */

  /***
    STEP #2: Open the input file (argc/argv stuff).
             You should read the file line-by-line in the next step
             using fgets (or fscanf or getline).
             Note: You must not hard-code the input file name.
             You must not use fread.
             You should exit with an error if file opening fails.
  ***/
  FILE *f = fopen(argv[1], "r");
  
  if (f == NULL) {
      printf("COULD NOT OPEN FILE!");
      exit(EXIT_FAILURE);
  }
  
  
  
  /***
    STEP #3: After your queue code works and after you can read the
             file, implement the prompt.
             Note: Here is the print statement to use for a match:

  printf(
      "MATCH: %s donates to %s via Dr. %s\n",
      donor,
      recipient,
      surgeon);

    You will need four queues for recipients, and four queus for
    donors, so using arrays seems sensible. Suggested declarations
    for these arrays are included below this comment.

  ***/

  /* Here is a suggested helper array for facilitating matching as
    described in the prompt. The blood types are listed from most
    rare to least rare. */
  
  
  char *types[BLOOD_TYPES] = {"AB", "B", "A", "O"};

//   struct queue *donors[BLOOD_TYPES];
//   struct queue *recipients[BLOOD_TYPES];
  struct queue *surgeons = malloc(sizeof *surgeons);
  
  
  struct queue *donors = malloc(sizeof *donors);
  //struct queue *recipients = malloc(sizeof(struct queue));
  struct queue *recipients = malloc(sizeof *recipients);
  
  initializeQueue(donors);
  initializeQueue(surgeons);
  initializeQueue(recipients);
  
  
 
  size_t size = 1024;
  char *buffer = malloc(size*sizeof(char));
    

  char *date = malloc(80);
  char *job;
  char *bloodType;
  char *name;
    
  while (getline(&buffer, &size, f) > 0) {
        
        // Hint 1: sscanf is great.  Turn that line into numbers!
        
        sscanf(buffer, "%c:%s:%s", job, bloodType, name);
       
     
        printf("%c\n %s\n %s\n", job, bloodType, name);
        
  }
    
    
	
    /*
    if (strcmp(job, "D") == 0) {
       
        
        printf("line = %s\n"
        enqueue(job, donors);
        printf("donor name= %s\n", donors->elements[donors->front]);
        //printf("")
    }
    
    
    
    if (strcmp(job, "S") == 0) {
       
        enqueue(job, surgeons);
        printf("suregon= %s\n", surgeons->elements[surgeons->front]);
        //printf("")
    }
  
     if (strcmp(job, "R") == 0) {
       
        enqueue(job, recipients);
        printf("recipient = %s\n", recipients->elements[recipients->front]);
        //printf("")
    }
    */
    // A RECIPIENT WITH BLOOD TYPE AB CAN MATCH WITH ANY DONOR
    // A RECIPIENT WITH BLOOD TYPE B CAN BE MATCHED WITH A DONOR WITH TYPE B OR O
    // A RECIPIENT WITH BLOOD TYPE A CAN BE MATCHED WITH A DONOR WITH TYPE A OR O
    // A RECIPIENT WITH BLOOD TYPE 0 CAN ONLY BE MATCHED WITH A DONOR WITH TYPE O
    
    /*
   //isDonorToRecipient(donor, recipient);
   // If the line has a recipient
   if (strcmp(job, "R") == 0) {
       
       
        // If the the queue does NOT have a surgeon then enqueue the recipient
        if (suregons->elements[suregons->front] == NULL) {
            enqueue(job, recipients);
        }
        

        
        // If there is a donor and a suregon waiting in the queue dequeue the donors and suregons
        if ((donors->elements[donors->front] && surgeons->elements[surgeons->front]) != NULL) {
            dequeue(donors);
            dequeue(surgeons);
            printf("MATCH: %s donates to %s via Dr. %s\n", donors->elements[donors->front], recipient->elements[recipient->front], surgeons->elements[surgeons->front]);
        // Otherwise enqueue the recipient
        } else {
            enqueue(job, recipient);
        }
            
    }
    */
    /*
    
    // If line has a Donor
    if (strcmp(job, "D") == 0) {
        
        
        // If the the queue does NOT have a surgeon then enqueue the recipient
        if (suregons->elements[suregons->front] == NULL) {
            enqueue(job, donors);
        }
        
        // If there is a donor and a suregon waiting in the queue dequeue the donors and suregons
        if ((recipients->elements[recipients->front] && surgeons->elements[surgeons->front]) != NULL) {
            dequeue(recipients);
            dequeue(surgeons);
            printf("MATCH: %s donates to %s via Dr. %s\n", recipients->elements[recipients->front], donors->elements[donors->front], surgeons->elements[surgeons->front]);
        // Otherwise enqueue the recipient
        } else {
            enqueue(job, donors);
        }
        
    }
    
    
    if (strcmp(job, "S") == 0) {
        
        // If recipient and donor are waiting in queue
        if ((recipients->elements[recipients->front] && donors->elements[donors->front]) != NULL) {
            dequeue(recipients);
            dequeue(donors);
            printf("MATCH: %s donates to %s via Dr. %s\n", recipients->elements[recipients->front], donors->elements[donors->front], surgeons->elements[surgeons->front]);
        // Otherwise dequeue suregons
        } else {
            dequeue(suregons);
        }
        
    }
    */
    
    // BASICALLY STOPS THE FILE
    

  free(buffer);
  
  

 
  //printf("MATCH: %s donates to %s via Dr. %s\n",donor, recipient, surgeon);


  /***
    STEP #4: After your matching code is done, add prettyPrintQueue
             calls for each of your recipient queues, your donor
             queues, and your surgeon queue. If you used the
             suggested "recipients" and "donors" arrays, and the
             "types" array, then you can use these print statements:

  for (int r = 0; r < BLOOD_TYPES; r++)
    prettyPrintQueue(recipients[r], "recipients", types[r]);
  for (int d = 0; d < BLOOD_TYPES; d++)
    prettyPrintQueue(donors[d], "donors", types[d]);
  prettyPrintQueue(surgeons, "surgeons", "type-agnostic");

             If you did not use arrays for your recipient and donor
             queues, then you should print your recipient queues in
             this order, for example:

  prettyPrintQueue(recipients_AB, "recipients", "AB");
  prettyPrintQueue(recipients_A, "recipients", "B");
  prettyPrintQueue(recipients_B, "recipients", "A");
  prettyPrintQueue(recipients_O, "recipients", "O");

             Then, print your donor queues in the same order, then
             print your surgeon queue.
  ***/

  /* If you have time, be sure to free any memory you allocated. */
  free(surgeons);
  free(donors);
  free(recipients);
  fclose(f);
  return EXIT_SUCCESS;
}


/* End. */
