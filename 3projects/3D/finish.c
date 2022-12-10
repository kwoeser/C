#include <stdio.h>
#include <stdlib.h>


// REVERSE POLISH NOTATION
typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}




# define STACK_SIZE 100

typedef struct {
	// Your data members go here //
    int top;
    float elements[STACK_SIZE];
    
} Stack;


void InitializeStack(Stack *s) {
    s->top = 0;
}


void Push(Stack *s, float X) {
    if (s->top == STACK_SIZE) {
	printf("STACK IS FULL");
	exit(EXIT_FAILURE);
    }

    s->elements[s->top] = X;
    s->top++;
}


float pop(Stack *s) {
    // Pop from the top of the stack 
    float rn = s->elements[s->top - 1];
    s->top--;
    return rn;
}



MathOperation GetOperation(char *op)
{
	/* Implement me! */
	int i;
	int addCount = 0;
	int subCount = 0;
	int mulCount = 0;
 	int divCount = 0;
	for (i=0; op[i] != '\0'; i++) {
		if (op[i] == '+') {
			addCount += 1;
		} else if (op[i] == '-') {
			subCount += 1;
		} else if (op[i] == 'x' ) {
			mulCount += 1;
 		} else if (op[i] == '/') {
 			divCount += 1;
 		}
		
	}
	
	if (addCount >= 1 && subCount >= 1) {
		IssueBadOperationError();
	} else if (addCount >= 1 && mulCount >= 1) {
		IssueBadOperationError();
	} else if (addCount >= 1 && divCount >= 1) {
		IssueBadOperationError();
	} else if (subCount >= 1 && addCount >= 1) {
		IssueBadOperationError();
	} else if (subCount >= 1 && mulCount >= 1) {
		IssueBadOperationError();
	} else if (subCount >= 1 && divCount >= 1) {
		IssueBadOperationError();
	} else if (mulCount >= 1 && addCount >= 1) {
		IssueBadOperationError();
	} else if (mulCount >= 1 && subCount >= 1) {
		IssueBadOperationError();
	} else if (mulCount >= 1 && divCount >= 1) {
		IssueBadOperationError();
	} else if (divCount >= 1 && addCount >= 1) {
 		IssueBadOperationError();
 	} else if (divCount >= 1 && subCount >= 1) {
 		IssueBadOperationError();
 	} else if (divCount >= 1 && mulCount >= 1) {
 		IssueBadOperationError();
 	} 	



	if (addCount == 1) {
		MathOperation op = ADD;
		return op;
	} else if (subCount == 1) {
		MathOperation op = SUBTRACT;
		return op;
	} else if (mulCount == 1) {
		MathOperation op = MULT;
		return op;
	} else if (divCount == 1) {
 		MathOperation op = DIV;
 		return op;
	} else {
		IssueBadOperationError();
	}	


}

double StringToDouble(char *str)
{	
    /* Implement me! */
	int i;
	double sum = 0;
	int isDec = 0;
	int isNeg = 0;
	double result;
	
	for (i = 0; str[i] != '\0'; i++) {

		if (str[i] == 'a') {
		 	IssueBadNumberError();
		} else if (str[i] == 'b') {
			IssueBadNumberError();
		} else if (str[i] == 'c') {
			IssueBadNumberError();
		}else if (str[i] == 'd') {
			IssueBadNumberError();
		} else if (str[i] == 'e') {
			IssueBadNumberError();
		}else if (str[i] == 'f') {
			IssueBadNumberError();
		} else if (str[i] == 'g') {
			IssueBadNumberError();
		}else if (str[i] == 'h') {
			IssueBadNumberError();
		} else if (str[i] == 'i') {
			IssueBadNumberError();
		}else if (str[i] == 'j') {
			IssueBadNumberError();
		} else if (str[i] == 'k') {
			IssueBadNumberError();
		}else if (str[i] == 'l') {
			IssueBadNumberError();
		} else if (str[i] == 'm') {
			IssueBadNumberError();
		}else if (str[i] == 'n') {
			IssueBadNumberError();
		} else if (str[i] == 'o') {
			IssueBadNumberError();
		}else if (str[i] == 'p') {
			IssueBadNumberError();
		} else if (str[i] == 'q') {
			IssueBadNumberError();
		}else if (str[i] == 'r') {
			IssueBadNumberError();
		} else if (str[i] == 's') {
			IssueBadNumberError();
		}else if (str[i] == 't') {
			IssueBadNumberError();
		} else if (str[i] == 'u') {
			IssueBadNumberError();
		} else if (str[i] == 'v') {
			IssueBadNumberError();
		}else if (str[i] == 'w') {
			IssueBadNumberError();
		}else if (str[i] == 'y') {
			IssueBadNumberError();
		} else if (str[i] == 'z') {
			IssueBadNumberError();
		}																									
		// Checks for Negative at start
		if (str[0] == '-' && isNeg != 1) {
			isNeg = 1;
		} else if (str[i] == '-') {
			IssueBadNumberError();
		}
		
		// Checks for decimal
		if (str[i] == '.' && isDec == 0) {
			isDec = 1;
		} else if (isDec >= 10 && str[i] == '.') {
			IssueBadNumberError();
		}

		if (str[i] >= '0' && str[i] <= '9') {
			sum = sum * 10.0 + (str[i] - '0');
			// After a decimal is found we multiply by 10 for each place value
			isDec *= 10;			
		} 

			
		
	}
	if (isNeg == 1) {
		sum = (sum * -1);
	}
	
	if (isDec >= 10) {
		// If there is a decimal divide sum by the amount of 0's past the decimal
		result = sum / isDec;
		
	} else {
		result = sum;
	}
	
	

}


void printQueue(Stack *q)
{

  printf("Printing queue %p\n", q);
  printf("\tThe index for the front of the queue is %d\n", q->top);
  if (q->top == 0)
  {
    printf("\tThe queue is empty.\n");
  }
  else
  {
    for (int i = 0; i < q->top; i++)
    {
      
      printf("\t\tEntry[%d]: \"%lf\"\n", i, q->elements[q->top]);
    }
  }

}


int main(int argc, char *argv[])
{
//     double v = StringToDouble(argv[1]);
//     MathOperation op = GetOperation(argv[2]);
//     double v2 = StringToDouble(argv[3]);
    //double result = 0.;
        
    
    Stack s;
    InitializeStack(&s);
    float val = 0.;
    float first = 0.;
    float second = 0.;
    float popped = 0.;
    int i;
    
    
    
    
    // SEARCH FOR MATH OPERATIONS AND IF IT'S A MATH OPERATION 
    // POP THE TOP 2 NUMBERS IN THE STACK AND THEN APPLY THAT OP TO THEM
    // THEN GET THE RESULT OF THOSE TWO AND THEN PUSH THAT RESULT ONTO THE STACK
    // SKIP ARGV[1] because its a.out
    for (i = 1; i < argc; i++) {
//         printQueue(&s);
        //printf("%s\n", argv[i]);
        if (argv[i][0] == '+') {
            //printQueue(&s);
            //printf("here");
            first = pop(&s);
            second = pop(&s);
            popped = first + second;
            //printf("%f %f", first, second);
            Push(&s, popped);
            
            
        } else if (argv[i][0] == '-') {
//             MathOperation op = GetOperation(argv[i]); 
            //printf("here");
            first = pop(&s);
            second = pop(&s);
            popped = first - second;
            Push(&s, popped);
            
        } else if (argv[i][0] == 'x') {
//             MathOperation op = GetOperation(argv[i]); 
            //printf("here");
            first = pop(&s);
            second = pop(&s);
            popped = first * second;
            Push(&s, popped);
            
        } else {
            val = (float) StringToDouble(argv[i]);
            //printf("val = %f\n", val);
            Push(&s, val);
           
        }

    }
    
    //printQueue(&s);
    float result = pop(&s);
    //printQueue(&s);
    printf("%d\n", (int) result);
    
    /*
    
    for (int i = 0; j < argc; i++) {
        
        if (argc == i + 1) {
            double v = StringToDouble(argv[i]);
            printf("here1");
            Push(&s, v);
        } else if (argc == i + 2) {
            double v2 = StringToDouble(argv[i]);
            Push(&s, v2);
        } else if (argc == i + 3) {
            MathOperation op = GetOperation(argv[i]);
            printf("op %s\n", op);
            
            
            switch (op) {
                case ADD:
                first = pop(&s);
                second = pop(&s);
                printf("\t Pop 1 = %f Pop 2 = %f", first, second);
                float val = first+second;
                Push(&s, val);
                break;
            case MULT:
                first = pop(&s);
                second = pop(&s);
                printf("\t Pop 1 = %f Pop 2 = %f", first, second);
                float val = first*second;
                Push(&s, val);
                break;
            case SUBTRACT: 
                first = pop(&s);
                second = pop(&s);
                printf("\t Pop 1 = %f Pop 2 = %f", first, second);
                float val = first-second;
                Push(&s, val);
                break;
                // REMOVED DIVISON FOR PROJ3D
            }
            
        } 
    
        
    }
    */
   // printf("%d\n", (int) val);
    /*
    // Starts at one for it skps ./a.out
    if (argc > 3) {
        for (i = 4; i < argc; i++) {
                // argv[1] = first number (still char) argv[2] = second number (still char) argv[3] = operation (char)
                // IF IT'S an operation do this (Assuming that the operation is not at the very front)
            
                if (GetOperation(argv[i])) {
//                     fprintf(stderr, "here");
                    MathOperation op = GetOperation(argv[i]);
                    
                    switch (op) {
                    case ADD:
                        first = pop(&s);
                        second = pop(&s);
                        val = first+second;
                        Push(&s, val);
                        break;
                    case MULT:
                        first = pop(&s);
                        second = pop(&s);
                        val = first*second;
                        Push(&s, val);
                        break;
                    case SUBTRACT: 
                        first = pop(&s);
                        second = pop(&s);
                        val = first-second;
                        Push(&s, val);
                        break;
                        // REMOVED DIVISON FOR PROJ3D
                    }
                
                // Other wise push that number onto the stack    
                } else { 
                    printf("here");
                    double v = StringToDouble(argv[i]);
                    Push(&s, v);
                    
                }
        }
    }
    
    */
    
    /*
    switch (op) {
       case ADD:
//         Push(&s, v);
//         Push(&s, v2);
//         float first = pop(&s);
//         float second = pop(&s);
//         float val = first+second;
//         push(&s, val);
//         break;
       case MULT:
          result = v*v2;
          break;
       case SUBTRACT: 
          result = v-v2;
          break;
        // REMOVED DIVISON FOR PROJ3D
    }
    */
    //printf("%d\n", (int) result);
 
    return 0;

}


