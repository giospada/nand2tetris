#ifndef AINST_FILE
#define AINST_FILE

#include "SymbolicTable.h"
#include <stdlib.h>
#include <string.h>

HackInst decodeAInst(char* line,SymbolicTable* lab);
int isNumber(char* lab);
void toBin(HackInst* hack,int num);

#endif