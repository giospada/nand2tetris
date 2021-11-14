#include "SymbolicTable.h"

SymbolicTable genereateST()
{
    int LEN_ARR=23;
    char *initKey[] = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15", "SCREEN", "KBD", "SP", "LCL", "ARG", "THIS", "THAT"};
    int initVal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16384, 24576, 0, 1, 2, 3, 4};
    SymbolicTable st;
    st.rows=createAllocator();
    st.reg=16;
    for (int i = 0; i < LEN_ARR; i++)
    {
        STRow *row = malloc(sizeof(STRow));
        addElement(&st.rows, row);
        row->key = initKey[i];
        row->val = initVal[i];
    }
    return st;
}
void addLabelToST(SymbolicTable *st, Label *lab)
{
    for (int i = 0; i < lab->el.len; i++)
    {
        STRow *row = malloc(sizeof(STRow));
        addElement(&st->rows, row);
        LRow* r = (LRow * )getFromAllocator(&lab->el, i);
        row->key=r->key;
        row->val =r->val;
    }
}

int addRowToSt(SymbolicTable *st, char *lab)
{
    STRow *row = malloc(sizeof(STRow));
    addElement(&st->rows, row);
    char* temp=malloc(sizeof(char)*(strlen(lab)+1));
    strcpy(temp,lab);
    row->key = temp;
    row->val = st->reg;
    st->reg++;
    return row->val;
}

int getValueOfST(SymbolicTable *st, char *lab)
{
    for (int i = 0; i < st->rows.len; i++)
    {
        STRow *row = (STRow *)getFromAllocator(&st->rows, i);
        if (strcmp(row->key, lab)==0)
            return row->val;
    }
    return -1;
}