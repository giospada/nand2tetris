#include "OperationFlow.h"


void label(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "label";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,strConcat(strConcat(copyString("("),label),")"));
    free(label);
}
void opGoto(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "goto";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,strConcat(copyString("@"),label));
    addElement(all,copyString("0;JMP"));
    free(label);
}
void opIfgoto(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "if-goto";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,copyString("@SP"));
    addElement(all,copyString("M=M-1"));
    addElement(all,copyString("A=M"));
    addElement(all,copyString("D=M"));
    addElement(all,strConcat(copyString("@"),label));
    addElement(all,copyString("D;JNE"));
    free(label);
}