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
  
  // If the donor has blood type O they match with any recipient blood type
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
  
  
  //printQueue(donors[2]);
//   enqueue("A", q);
//   printQueue(donors);
//   enqueue("O", q);
//   printQueue(donors);
//   printf("Dequeue: %s\n", dequeue(donors));
//   printQueue(donors);
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
      printf("COULD NOT OPEN FILE!\n");
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

  struct queue *donors[BLOOD_TYPES];
  struct queue *recipients[BLOOD_TYPES];
  struct queue *surgeons = malloc(sizeof *surgeons);  
  


  for (int i = 0; i < BLOOD_TYPES; i++) {
//         donors[i] = malloc(sizeof *donors);
//         recipients[i] = malloc(sizeof *recipients);
        // FIXED TEMP SEG FAULT
        donors[i] = malloc(sizeof(Queue));
        recipients[i] = malloc(sizeof(Queue));
        initializeQueue(donors[i]);
        initializeQueue(recipients[i]);
  }
  

  initializeQueue(surgeons);

  
  rewind(f);
  char *line = malloc(80 * sizeof *line);
  
  line = fgets(line, 80, f);
      
  while (line != NULL) {
    
    char *job = strtok(line, ":");

    
    // If line is donor
    if (strcmp(job, "D") == 0) {
        char *bloodType= strtok(NULL, ":");
        char *name = strtok(NULL, ":");
            
        int i = 0;
        while (strcmp(bloodType, types[i]) != 0) {
            i++;
        }
            
        if (surgeons->population == 0) {
            enqueue(name, donors[i]);
        } 
        
        // DIFFERENT BLOOD TYPES CAN MATCH WITH OTHER BLOOD TYPES
        
        if (recipients[i]->elements[recipients[i]->front] && surgeons->elements[surgeons->front] != NULL) {
            
            // MAYBE PUT THE PRINT STATEMENT BEFORE 
            printf("MATCH: %s donates to %s via Dr. %s", donors[i]->elements[donors[i]->front], recipients[i]->elements[recipients[i]->front], surgeons->elements[surgeons->front]);
            dequeue(recipients[i]);
            dequeue(surgeons);
            
        } else {
            enqueue(name, donors[i]);
        }
            
            
    }
    
 
    
    // If line is surgeon
    if (strcmp(job, "S") == 0) {
    
        char *name = strtok(NULL, ":");
        
        
        for (int i = 0; i < BLOOD_TYPES; i ++) {
            
            if ((donors[i]->elements[donors[i]->front] && recipients[i]->elements[recipients[i]->front]) != '\0') {
                printf("MATCH: %s donates to %s via Dr. %s", donors[i]->elements[donors[i]->front], recipients[i]->elements[recipients[i]->front], surgeons->elements[surgeons->front]);
                dequeue(donors[i]);
                dequeue(recipients[i]);
                
            } else {
                enqueue(name, surgeons);
            }    
                
        }
        
        
    }
    
    
    

    // If line is recipient
    if (strcmp(job, "R") == 0) {
        char *bloodType= strtok(NULL, ":");
        char *name= strtok(NULL, ":");
    
            
        int i = 0;
        while (strcmp(bloodType, types[i]) != 0) {
            i++;
        }
            
        if (surgeons->population == 0) {
            enqueue(name, recipients[i]);
        } 
        
        //isDonorToRecipient();
        if ((donors[i]->elements[donors[i]->front] && surgeons->elements[surgeons->front]) != '\0') {
            printf("MATCH: %s donates to %s via Dr. %s", donors[i]->elements[donors[i]->front], recipients[i]->elements[recipients[i]->front], surgeons->elements[surgeons->front]);
            dequeue(donors[i]);
            dequeue(surgeons);
            
        } else {
            enqueue(name, recipients[i]);
        }

        
        //printf("job = %s type = %s name = %s", job, bloodType, name);
    }
    
    

        
    // BASICALLY STOPS THE FILE
    line = fgets(line, 80, f);
    
    
  }
	


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
//   free(surgeons);
//   free(donors);
//   free(recipients);
  free(surgeons);
  free(line);

  fclose(f);
  return EXIT_SUCCESS;
}


/* End. */
