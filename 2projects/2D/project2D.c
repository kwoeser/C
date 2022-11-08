#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
        
    switch (op) {
       case ADD:
       	 result = v+v2;
         break;
       /* Implement more cases... */
       case MULT:
	 result = v*v2;
	 break;
       case SUBTRACT: 
	 result = v-v2;
	 break;
       case DIV:
	 result = v/v2;
	 break;
    }
    printf("%d\n", (int) result);
 
    return 0;

}


