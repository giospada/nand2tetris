#ifndef SYMBOLICTABLE_FILE
#define SYMBOLICTABLE_FILE

#include "Allocator.h"

typedef struct {
    char* key;
    int val;
}STRow;

typedef struct {
    Allocator rows;
    int reg;
}SymbolicTable;

#include "Labels.h"



SymbolicTable genereateST();
void addLabelToST(SymbolicTable *st, Label* lab);
int addRowToSt(SymbolicTable *st, char *lab);
int getValueOfST(SymbolicTable *st, char *lab);


#endif
