#include "OperationFlow.h"

int isaccetable(char c)
{
    return ('0' <= c && c <= '9') ||
           ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z') ||
           (c == '$' || c == '.' || c == '_');
}

char* getLabel(char *line, int from)
{
    while (!isaccetable(line[from]) && from < strlen(line))
        from++;
    int s=from;
    while (isaccetable(line[from]) && from < strlen(line))from++;

    char* res=malloc(sizeof(char)*(from-s+1));

    for(int i=s;i<from;i++){
        res[i-s]=line[i];
    }
    res[from-s]='\0';
    return res;
}

void label(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "label";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,strcat(strcat(copyString("("),label),")"));
    free(label);
}
void opGoto(char *inp, Allocator *all, OperationSetting *op)
{
    char *name = "goto";
    int f = strFirstSub(inp, name);
    char *label = getLabel(inp, f + strlen(name));
    addElement(all,strcat(copyString("@"),label));
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
    addElement(all,strcat(copyString("@"),label));
    addElement(all,copyString("D;JNE"));
    free(label);
}