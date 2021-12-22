#include "OperationSubroutine.h"


void pushRegister(Allocator* all,char* rg){
    addElement(all,strConcat(copyString("@"),copyString(rg)));
    addElement(all,copyString("D=M"));
    addElement(all,copyString("@SP"));
    addElement(all,copyString("M=M+1"));
    addElement(all,copyString("A=M-1"));
    addElement(all,copyString("M=D"));
}

void opFunction(char *inp, Allocator *all, OperationSetting *op) {
    char* name="function";
    int pos=strFirstSub(inp,name);
    char* label=getLabel(inp,strlen(name)+pos);
    int k=toInt(pos+strlen(name)+strlen(label),inp);
    for (int i = 0; i < k; i++)
    {
        addElement(all, copyString("@SP"));
        addElement(all, copyString("M=M+1"));
        addElement(all, copyString("A=M-1"));
        addElement(all, copyString("M=0"));
    }
    addElement(all,strConcat(strConcat(copyString("("),label),")"));
    free(label);
}
void opCall(char *inp, Allocator *all, OperationSetting *op)
{
    char* name="call";
    int pos=strFirstSub(inp,name);
    char* label=getLabel(inp,strlen(name)+pos);
    int k=toInt(pos+strlen(name)+strlen(label),inp);
    char* kstr=intToString(k);
    op->returnN++;
    {
        char *tmp = strAppendInt(strConcat(copyString("RET_"), label), op->returnN);
        addElement(all,strConcat(copyString("@"),tmp));
        addElement(all, copyString("D=A"));
        addElement(all, copyString("@SP"));
        addElement(all, copyString("M=M+1"));
        addElement(all, copyString("A=M-1"));
        addElement(all, copyString("M=D"));
        free(tmp);
    }
    pushRegister(all, "LCL");
    pushRegister(all, "ARG");
    pushRegister(all, "THIS");
    pushRegister(all, "THAT");

    addElement(all, copyString("@SP"));
    addElement(all, copyString("D=M"));
    addElement(all, copyString("@5"));
    addElement(all, copyString("D=D-A"));
    addElement(all, strConcat(copyString("@"), kstr));
    addElement(all, copyString("D=D-A"));
    addElement(all, copyString("@ARG"));
    addElement(all, copyString("M=D"));

    addElement(all, copyString("@SP"));
    addElement(all, copyString("D=M"));
    addElement(all, copyString("@LCL"));
    addElement(all, copyString("M=D"));

    addElement(all, strConcat(copyString("@"), label));
    addElement(all, copyString("0;JMP"));

    addElement(all, strConcat(strAppendInt(strConcat(copyString("(RET_"), label), op->returnN), ")"));
}

void getFromFrame(Allocator *all, int n, char *reg)
{
    char *kstr = intToString(n);
    addElement(all, copyString("@R13"));
    addElement(all, copyString("D=M"));
    addElement(all, strConcat(copyString("@"), kstr));
    addElement(all, copyString("A=D-A"));
    addElement(all, copyString("D=M"));
    addElement(all, strConcat(copyString("@"), copyString(reg)));
    addElement(all, copyString("M=D"));
    free(kstr);
}

void opReturn(char *inp, Allocator *all, OperationSetting *op)
{
    addElement(all, copyString("@LCL"));
    addElement(all, copyString("D=M"));
    addElement(all, copyString("@R13"));
    addElement(all, copyString("M=D"));

    getFromFrame(all, 5, "R14");

    addElement(all, copyString("@SP"));
    addElement(all, copyString("A=M-1"));
    addElement(all, copyString("D=M"));
    addElement(all, copyString("@ARG"));
    addElement(all, copyString("A=M"));
    addElement(all, copyString("M=D"));

    addElement(all, copyString("@ARG"));
    addElement(all, copyString("D=M+1"));
    addElement(all, copyString("@SP"));
    addElement(all, copyString("M=D"));

    getFromFrame(all, 1, "THAT");
    getFromFrame(all, 2, "THIS");
    getFromFrame(all, 3, "ARG");
    getFromFrame(all, 4, "LCL");

    addElement(all, copyString("@R14"));
    addElement(all, copyString("A=M"));
    addElement(all, copyString("D;JMP"));
}
