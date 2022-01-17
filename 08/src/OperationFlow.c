#include "OperationFlow.h"


char* createLabel(OperationSetting *op,char* label){
    char* t=strConcat(op->filename,"__");
    char* t1=strConcat(t,label);
    char* t2=strConcat(t1,"__");
    char* t3=strConcat(t2,op->currentFunction);
    free(t);
    free(t1);
    free(t2);
    return t3;

}

void label(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "label";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    {
        char* t1=createLabel(op,label);
        char* t2=strConcat(t1,")");
        addElement(all,strConcat("(",t2));
        free(t1);
        free(t2);
    }
    free(label);
}
void opGoto(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "goto";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    {
        char* t=createLabel(op,label);
        addElement(all,strConcat("@",t));
        free(t);
    }
    addElement(all,copyString("0;JMP"));
    free(label);
}
void opIfgoto(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "if-goto";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,copyString("@SP"));
    addElement(all,copyString("AM=M-1"));
    addElement(all,copyString("D=M"));
    {
        char* t=createLabel(op,label);
        addElement(all,strConcat("@",t));
        free(t);
    }
    addElement(all,copyString("D;JNE"));
    free(label);
}