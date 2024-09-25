#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VARS 100


typedef struct{
    char name[50];
    double value;

} Variable;


Variable vars[MAX_VARS];
int varCount = 0;


int findVariable(char *name){
    for (int i = 0; i < varCount; i++){
        if(strcmp(vars[i].name, name) == 0){
            return i;
        }
    }

    return -1;
}



double evaluate(char *expression){
    double num1, num2;
    char operator;
    char varName1[50], varName2[50];
    int varIndex1, varIndex2;



    if (strstr(expression, "sqrt")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "sqrt(%lf)", &x) == 1)
        {
            /* code */
            return sqrt(x);
        }
        
    } else if (strstr(expression, "pow")!= NULL)
    {
        /* code */
        double base, exponent;
        if (sscanf(expression, "pow(%lf, %lf)", &base, &exponent) == 2)
        {
            /* code */
            return pow(base, exponent);
        }
        
    }
    else if (strstr(expression, "log10")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "log10(%lf)", &x) == 1)
        {
            /* code */
            return log10(x);
        }
        
    }
    else if (strstr(expression, "log")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "log(%lf)", &x) == 1)
        {
            /* code */
            return log(x);
        }
        
    }
    else if (strstr(expression, "sin")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "sin(%lf)", &x) == 1)
        {
            /* code */
            return sin(x);
        }
        
    }
    else if (strstr(expression, "cos")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "cos(%lf)", &x) == 1)
        {
            /* code */
            return cos(x);
        }
        
    }
    else if (strstr(expression, "tan")!= NULL)
    {
        /* code */
        double x;
        if (sscanf(expression, "tan(%lf)", &x) == 1)
        {
            /* code */
            return tan(x);
        }
        
    }


    if(sscanf(expression,"%s %c %s", varName1, &operator, varName2 )==3){

        if (isalpha(varName1[0]))
        {
            varIndex1 = findVariable(varName1);
            if(varIndex1 == -1){
                printf("Error: Unefined variable `%s` ", varName1);
                return 0;
            }

            num1 = vars[varIndex1].value;

        } else{
            num1 = atof(varName1);
        }

        if (isalpha(varName2[0]))
        {
            varIndex2 = findVariable(varName2);
            if(varIndex2 == -1){
                printf("Error: Undefined variable `%s` ", varName2);
                return 0;
            }

            num2 = vars[varIndex2].value;

        } else{
            num2 = atof(varName2);
        }
        

        printf("\n\t\t");
        switch (operator)
        {
        case '+':
            return num1 + num2;

        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        case '%':
            return fmod(num1, num2);

        case '^':
            return pow(num1, num2);
        case '/':
            if(num2 == 0){
                printf("Error: You cant divide by zero");

                break;

            } else{
                return num1 / num2;
            }


            
        
        default:
            printf("Error unsuported operatior '%c'. \n", operator);
        }
    } else{
        printf("Error: Invalid input, use this format num operator num \n");
    }
    return 0;

}

void assignVariable(char *input){
    char varName[50];
    double value;

    if(sscanf(input, "%s = %lf", varName, &value)== 2){
        int varIndex = findVariable(varName);

        if(varIndex != -1){
            vars[varIndex].value = value;

        } else {
            if (varCount <MAX_VARS)
            {
                /* code */

                strcpy(vars[varCount].name, varName);
                vars[varCount].value = value;
                varCount++;

            }else{

                printf("Error: Variable limit reached. \n\n");
            }
            
        }
        printf("Assigned: %s = %lf \n", varName, value);

    } else {
        printf("Error: Invalid assignment format. Use the format: variable = value \n");

    }
}

int main(){



    char input[100];
    double result;

    printf("Welcome to Matlab Lite \n\n");
    printf("Enter your Arithmetic Opeation luike 5 + 4,\n\n Type 'help' to see menu  \n\n Type 'exit' to quit the program \n\n");

    while (1)
    {
        /* code */
        printf(">> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "exit")==0){
            break;

        }

        if (strchr(input, '=') != NULL)
        {
            /* code */
            assignVariable(input);
            
        } else
        {
            /* code */
            result = evaluate(input);

            printf("Result: %lf \n", result);
        }
        
        


    }
    
    printf("Exiting the Program");

    return 0;

}