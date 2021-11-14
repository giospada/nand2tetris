#ifndef  OUTPROCESSOR_FILE
#define OUTPROCESSOR_FILE

#include <stdio.h>
#include "InputReader.h"
#include "SymbolicTable.h"
#include "LineProcessor.h"

void writeAllToFile(Input* i,SymbolicTable* st);
char* fileName(Input* i);
#endif