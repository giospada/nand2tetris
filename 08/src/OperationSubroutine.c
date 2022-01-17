#include "OperationSubroutine.h"


void pushRegister(Allocator* all,char* rg){
    addElement(all,strConcat("@",(rg)));
    addElement(all,copyString("D=M"));
    addElement(all,copyString("@SP"));
    addElement(all,copyString("M=M+1"));
    addElement(all,copyString("A=M-1"));
    addElement(all,copyString("M=D"));
}

void opFunction(char *inp, Allocator *all, OperationSetting *op) {
    char* name="function";
    int pos = strFirstSub(inp, name);
    char *label = getLabel(inp, strlen(name) + pos);
    int k = toInt(pos + strlen(name) + strlen(label)+1, inp);
    updateFunction(op,label);
    {
        char *t = strConcat("(", label);
        char *t1 = strConcat(t, ")");
        addElement(all, t1);
        free(t);
    }
    if (k <= 2)
    {
        for (int i = 0; i < k; i++)
        {
            addElement(all, copyString("@SP"));
            addElement(all, copyString("M=M+1"));
            addElement(all, copyString("A=M-1"));
            addElement(all, copyString("M=0"));
        }
    }
    else if (2 < k)
    {
        addElement(all, strAppendInt("@", k));
        addElement(all, copyString("D=A"));
        addElement(all, copyString("@SP"));
        addElement(all, copyString("M=M+D"));
        addElement(all, copyString("A=M-D"));
        for (int i = 0; i < k; i++)
        {
            addElement(all, copyString("M=0"));
            addElement(all, copyString("A=A+1"));
        }
    }
    free(label);
}
void opCall(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "call";
    int pos = strFirstSub(inp, name);
    char *label = getLabel(inp, strlen(name) + pos);
    int k = toInt(pos + strlen(name) + strlen(label)+1, inp);
    char *kstr = intToString(k);
    op->returnN++;
    {
        char *t = strConcat("RET_", label);
        char *tmp = strAppendInt(t, op->returnN);
        addElement(all, strConcat("@", tmp));
        addElement(all, copyString("D=A"));
        free(tmp);
        free(t);
    }
    if (!isCaschedCall(op, label))
    {
        {
            char *c = getCashedCallLabel(label);
            char *f = strConcat("(", c);
            addElement(all, strConcat(f, ")"));
            free(c);
            free(f);
        }
        addElement(all, copyString("@SP"));
        addElement(all, copyString("M=M+1"));
        addElement(all, copyString("A=M-1"));
        addElement(all, copyString("M=D"));
        pushRegister(all, "LCL");
        pushRegister(all, "ARG");
        pushRegister(all, "THIS");
        pushRegister(all, "THAT");

        addElement(all, copyString("@SP"));
        addElement(all, copyString("D=M"));
        {
            char *t = intToString(k + 5);
            addElement(all, strConcat("@", t));
            free(t);
        }
        addElement(all, copyString("D=D-A"));
        addElement(all, copyString("@ARG"));
        addElement(all, copyString("M=D"));

        addElement(all, copyString("@SP"));
        addElement(all, copyString("D=M"));
        addElement(all, copyString("@LCL"));
        addElement(all, copyString("M=D"));

        addElement(all, strConcat("@", label));
        addElement(all, copyString("0;JMP"));
        addCaschedCall(op, label);
    }
    else
    {
        char *c = getCashedCallLabel(label);
        addElement(all, strConcat("@", c));
        addElement(all, copyString("0;JMP"));
        free(c);
    }
    {
        char *t = strConcat("(RET_", label);
        char *t1 = strAppendInt(t, op->returnN);
        addElement(all, strConcat(t1, ")"));
        free(t);
        free(t1);
    }
    free(kstr);
    free(label);
}

void getFromFrame(Allocator *all, int n, char *reg)
{
    char *kstr = intToString(n);
    addElement(all, copyString("@R13"));
    addElement(all, copyString("D=M"));
    addElement(all, strConcat(("@"), kstr));
    addElement(all, copyString("A=D-A"));
    addElement(all, copyString("D=M"));
    addElement(all, strConcat(("@"), (reg)));
    addElement(all, copyString("M=D"));
    free(kstr);
}

void opReturn(char *inp, Allocator *all, OperationSetting *op)
{
    if (!op->returnCached)
    {
        addElement(all, copyString("(CACHED_RET)"));
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
        op->returnCached = 1;
    }
    else
    {
        addElement(all, copyString("@CACHED_RET"));
        addElement(all, copyString("0;JMP"));
    }
}
