//need to create the functions run the array notation. 
#define _CRT_SECURE_NO_WARNINGS  // lets us use depricated code

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ASM_FILE_NAME[ ] = "wilsonv.asm";

#define MAX 150			// strlen of simulators memory can be changed
#define COL 7			// number of columns for output
#define LINE_SIZE 20	// For c-strings

//OPERAND TYPES, REGISTERS AND OTHER
#define AXREG 0
#define BXREG 1
#define CXREG 2
#define DXREG 3

//commands
#define HALT 5
#define MOVREG 192

//boolean
#define TRUE 1
#define FALSE 0

enum operType { reg, mem, constant, arrayBx, arrayBxPlus, none };  //list of all types of operand types

//Registers and flag add the stack pointer
struct Registers
{
	int AX;
	int BX;
	int CX;
	int DX;
	int flag;
}regis;

// file pointer
FILE *fptr;

// function for converting hex to signed decimal


// function for converting signed decimal to binary

char* removeBrackets(char* part)
{
    int i = 0;
    int j = 0;

    while (part[i] != '\0')
    {
        if (part[i] != '[' && part[i] != ']')
        {
            part[j] = part[i];
            j++;
        }
        i++;
    }
    part[j] = '\0';
    return part;
}

char* split_plus(char *part)
{
    const char delimiter[] = "+";
    char *token;
    char first_part[100];
    char second_part[100];
    int count = 0;
    while (token != NULL) 
    {
        if (count == 0)
        {
            strcpy(first_part, token);
            printf("first_part: %s\n", first_part);
        }
        else if (count == 1)
        {
            strcpy(second_part, token);
            printf("second_part: %s\n", second_part);
        }
        token = strtok(NULL, delimiter);
        count++;
    }
}


void process_line(char *line_of_asm)
{
    // break the line of code into 3 parts 1. command 2. data type 3. data type
    const char delimiters[] = " ,";
    char *token;

    // get first token
    token = strtok(line_of_asm, delimiters);
    int count = 0;
    while(token != NULL)
    {
        
        if (count == 0)
        {
            char command[5];
            strcpy(command, token);
            printf("first: %s\n", command);
        }
        else if (count == 1)
        {
            char second_input[100];
            strcpy(second_input, token);
            printf("\nsecond: %s", second_input, "\n");
            // find if [] is contained
            if (second_input[0] == '[')
            {
                // this block of code is for if second_input is memory
                char no_brack_second[100];
                strcpy(no_brack_second, removeBrackets(second_input));
            }
        }
        else if (count == 2)
        {
            char third_input[100];
            strcpy(third_input, token);
            printf("\nthird: %s", third_input, "\n");
            // find if [] is contained
            if (third_input[0] == '[')
            {
                // this block of code is for if third_input is memory
                char no_brack_third[100];
                strcpy(no_brack_third, removeBrackets(third_input));
                // check for + operand
                if (strchr(no_brack_third, '+'))
                {
                    // now we have to split the two values
                }

            }

        }
        // get next token
        token = strtok(NULL, delimiters);
        count++;
    }
    
}

void read_file()
{
    fptr = fopen(ASM_FILE_NAME, "r"); 
    if (fptr == NULL)
    {
        perror("Unable to open file!");
        exit(1);
    }

    char line_of_asm[128];
    while(fgets(line_of_asm, 128, fptr))
    {
        // if first three characters are mov call mov function and do that for each needed function
        // but first write the function of converting from decimal to binary
        process_line(line_of_asm);
        // printf("%s", line_of_asm);
        
    }
    fclose(fptr);
}


int main()
{
    read_file();
    return 0;
}