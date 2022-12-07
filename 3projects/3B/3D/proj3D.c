#include <stdio.h>
#include <stdlib.h>


// REVERSE POLISH NOTATION
// DOESN'T DEAL WITH NEGATIVES OR DIVISION 

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




# define STACK_SIZE 10

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



int main(int argc, char *argv[])
{
            
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
        //printf("%c%c\n",  argv[i][0], argv[i][1]);
        if (argv[i][0] == '+') {
            first = pop(&s);
            second = pop(&s);
            popped = second + first;
            Push(&s, popped);
            
        
        // If a negative number is added to the stack it pops the top 2 off for no reason
        } else if (argv[i][0] == '-' && argv[i][1] == '\0') {
            first = pop(&s);
            second = pop(&s);
            //popped = first - second;
            popped = second - first;
            Push(&s, popped);
            
        } else if (argv[i][0] == 'x') {

            first = pop(&s);
            second = pop(&s);
            popped = second * first;
            Push(&s, popped);
            
        } else {
            val = (float) StringToDouble(argv[i]);
            Push(&s, val);
           
        }

    }
    
    float result = pop(&s);
    printf("The total is %d\n", (int) result);
    
   
    return 0;

}


