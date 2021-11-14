#ifndef LineProcessor_File
#define LineProcessor_File


typedef enum {
    Void_Line,
    AInst_Line,
    CInst_Line,
    Temp_Line,
    Label_Line
}LineType;

typedef struct{
    char bit[16];
    int valid;
}HackInst;

#include <string.h>
#include <stdlib.h>
#include "Cinstruction.h"
#include "SymbolicTable.h"
#include "Ainstruction.h"



LineType getLineType(const char* inp);
HackInst lineToHack(char* line,SymbolicTable* lab);

#endif


