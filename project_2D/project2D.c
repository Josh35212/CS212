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
    if (op[1] != '\0')      // Ensure that op is a single char string
    {
        IssueBadOperationError();
    }
    switch (op[0])
    {
        case '+':
            return ADD;
        case 'x':
            return MULT;
        case '-':
            return SUBTRACT;
        case '/':
            return DIV;
        default:
            return UNSUPPORTED;
    }
}


double StringToDouble(char *str)
{
    int i = 0;          
    int flag = 0;           // Signal to change char to decimal logic
    int sign = 1;           // Determine +/- (*1 or *-1)
    double val = 0.0;
    double shift = 10.0;    // Shifter of decimal places
    
    if (str[0] == '-')
    {
        sign = -1;
        i = 1;              // Change starting index
    }
    
    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            flag += 1;      // Count decimal points typed
            if (flag > 1)
            {
                IssueBadNumberError();
            }
        }
        
        else if (str[i] >= '0' && str[i] <= '9')            // Check for valid input
        {
            if (flag == 0)                                  // Left side of decimal point
            {
                val = val * 10.0 + str[i] - '0';            // ASCII conversion trick and base-10 shifting
            }
            else                                            // Right side of decimal point
            {
                val += (str[i] - '0') / shift;
                shift *= 10.0;                              // Shift from 10ths, to 100ths, to 1000ths, etc.
            }
        }
        
        else
        {
            IssueBadNumberError();
        }       
        i++;
    }
    return val * sign;
}


int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
        case ADD:
            result = v+v2;
            break;
        case MULT:
            result = v*v2;
            break;
        case SUBTRACT:
            result = v-v2;
            break;
        case DIV:
            result = v/v2;
            break;
        case UNSUPPORTED:
            IssueBadOperationError();
            break;
    }
    printf("%d\n", (int) result);
    return 0;
}