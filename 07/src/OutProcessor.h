#ifndef  OUTPROCESSOR_FILE
#define OUTPROCESSOR_FILE

#include "InputReader.h"
#include <stdio.h>
#include "Allocator.h"

char* fileName(Input* inp);
FILE* openFile(Input* inp);
void writeAllocator(FILE* f,Allocator* all);


#endif