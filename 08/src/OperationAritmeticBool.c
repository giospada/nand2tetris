#include "OperationAritmeticBool.h"



void getTwoOperand(Allocator* all);
int compareStart(Allocator  *all,OperationSetting* op);
int compareFinish(Allocator *all,OperationSetting* op);

void add(char* inp,Allocator* all,OperationSetting* op)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M+D"));
    addElement(all, copyString("M=D"));
}

void sub(char* inp,Allocator* all,OperationSetting* op)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M-D"));
    addElement(all, copyString("M=D"));
}

void and (char* inp,Allocator* all,OperationSetting* op)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M&D"));
    addElement(all, copyString("M=D"));
}
void or (char* inp,Allocator* all,OperationSetting* op)
{
    getTwoOperand(all);
    addElement(all, copyString("D=M|D"));
    addElement(all, copyString("M=D"));
}

void not(char* inp,Allocator* all,OperationSetting* op)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=!M"));
}

void neg(char* inp,Allocator* all,OperationSetting* op)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=-M"));
}

void eq(char* inp,Allocator* all,OperationSetting* op)
{
    compareStart(all,op);
    addElement(all, copyString("D;JNE"));
    compareFinish(all,op);
}
void gt(char* inp,Allocator* all,OperationSetting* op)
{
    compareStart(all,op);
    addElement(all, copyString("D;JGE"));
    compareFinish(all,op);
}
void lt(char* inp,Allocator* all,OperationSetting* op)
{
    compareStart(all,op);
    addElement(all, copyString("D;JLE"));
    compareFinish(all,op);
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

int compareStart(Allocator *all,OperationSetting* op)
{
    op->staticN++;
    getTwoOperand(all);
    addElement(all, copyString("D=D-M"));
    addElement(all, copyString("M=0"));
    addElement(all, strAppendInt(copyString("@ENDCOND"), op->staticN));
}

int compareFinish(Allocator *all,OperationSetting* op)
{
    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("M=!M"));
    addElement(all, strConcat(strAppendInt(copyString("(ENDCOND"), op->staticN), ")"));
}