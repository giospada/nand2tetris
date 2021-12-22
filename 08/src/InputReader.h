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

// legge tutte le righe dall'file e le alloca in nella struttura INPUt
void readInput(Input *write,FILE* file);
// sceglie se leggere il file dagli args o dallo stdin
Input readFileFromARG(int argc,char const *argv[]);

#endif


