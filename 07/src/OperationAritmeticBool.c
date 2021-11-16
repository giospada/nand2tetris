#include "OperationAritmeticBool.h"

static int counter=0;


void getTwoOperand(Allocator* all);
int compareStart(Allocator *all);
int compareFinish(Allocator *all);

void add(char *inp, Allocator *all)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M+D"));
    addElement(all, copyString("M=D"));
}

void sub(char *inp, Allocator *all)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M-D"));
    addElement(all, copyString("M=D"));
}

void and (char *inp, Allocator *all)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M&D"));
    addElement(all, copyString("M=D"));
}
void or (char *inp, Allocator *all)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M|D"));
    addElement(all, copyString("M=D"));
}

void not(char *inp, Allocator *all)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=!M"));
}

void neg(char *inp, Allocator *all)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=-M"));
}

void eq(char *inp, Allocator *all)
{
    compareStart(all);
    addElement(all, copyString("D;JNE"));
    compareFinish(all);
}
void gt(char *inp, Allocator *all)
{
    compareStart(all);
    addElement(all, copyString("D;JGE"));
    compareFinish(all);
}
void lt(char *inp, Allocator *all)
{
    compareStart(all);
    addElement(all, copyString("D;JLE"));
    compareFinish(all);
}

//specific fun

void getTwoOperand(Allocator *all)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("M=M-1"));
    addElement(all, copyString("A=M"));
    addElement(all, copyString("D=M"));
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
}

int compareStart(Allocator *all)
{
    counter++;
    getTwoOperand(all);
    addElement(all, copyString("D=D-M"));
    addElement(all, copyString("M=0"));
    addElement(all, strAppendInt(copyString("@ENDCOND"), counter));
}

int compareFinish(Allocator *all)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=!M"));
    addElement(all, strcat(strAppendInt(copyString("(ENDCOND"), counter), ")"));
}