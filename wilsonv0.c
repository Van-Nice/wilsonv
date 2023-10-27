//need to create the functions run the array notation. 
#define _CRT_SECURE_NO_WARNINGS  // lets us use depricated code

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// char ASM_FILE_NAME[ ] = "wilsonv.asm";

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

// read file function
FILE *fptr;

// create function for if it's a mov assembly call


void read_file()
{
    fptr = fopen("wilsonv.asm", "r"); 
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
        printf("%s", line_of_asm);
    }
    fclose(fptr);
}


int main()
{
    read_file();
    printf("Hello World!");
    return 0;
}