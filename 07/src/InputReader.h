#ifndef InputReader_File
#define InputReader_File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Allocator.h"
#include <assert.h>

typedef struct {
    Allocator input;
    int error;
    char* fileName;
}Input;

void readInput(Input *write,FILE* file);
Input readFileFromARG(int argc,char const *argv[]);

#endif


