#ifndef InputReader_File
#define InputReader_File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Allocator.h"
#include <assert.h>
#include <dirent.h> 
#include "StringOperation.h"

#define INPBUFFSIZE 1024

typedef struct {
    Allocator files;
    int error;
    char* dirName;
}InputDir;

typedef struct {
    Allocator input;
    int error;
    char* fileName;
}Input;

// legge tutte le righe dall'file e le alloca in nella struttura INPUt
void readInput(Input *write,FILE* file);
// legge la cartella dagli args e mette tutti i file in InputDir 
InputDir readDirFromArgs(int argc, char const *argv[]);
Input readFileFrom(char* dirname,char* name);
#endif


