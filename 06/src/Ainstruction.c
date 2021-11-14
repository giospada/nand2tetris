#include "Ainstruction.h"


void toBin(HackInst* hack,int num){
    int i=0;
    while(num!=0){
        hack->bit[i]=(num%2==0)?'0':'1';
        num/=2;
        i++;
    }
}

int isNumber(char* lab){
    for (int i = 0; i < strlen(lab); i++)
        if(!('0' <= lab[i] && lab[i] <= '9'))
            return 0;
    return 1;
}

HackInst decodeAInst(char *line, SymbolicTable *st)
{
    HackInst inst;
    inst.valid = 0;
    for(int i=0;i<16;i++)inst.bit[i]='0';
    int s = -1, f = -1;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '@')
        {
            s = i;
        }
        else if (s != -1 && !(('0' <= line[i] && line[i] <= '9') ||
                              ('a' <= line[i] && line[i] <= 'z') ||
                              ('A' <= line[i] && line[i] <= 'Z') ||
                              (line[i] == '$' || line[i] == '.' || line[i] == '_')))
        {
            f = i;
            break;
        }
    }
    assert(s != -1);
    assert(f != -1);
    char *lab = calloc(f - s, sizeof(char));
    s += 1;
    strncpy(lab, line + s, f - s);
    int num;
    if (isNumber(lab))
    {
        num = atoi(lab);
    }
    else
    {
        num = getValueOfST(st, lab);
        if (num == -1)
        {
            num=addRowToSt(st,lab); 
        }
    }
    toBin(&inst,num);
    free(lab);
    return inst;
}