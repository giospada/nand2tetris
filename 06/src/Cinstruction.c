#include "LineProcessor.h"

int isCChar(char s)
{
    char* arr ="01-&;=|+!ADMJGETLNPQ";
    for(int i=0;i<strlen(arr);i++){
        if(s==arr[i])return 1;
    }
    return 0;
}

int getComp(char *st,HackInst* inst)
{
    char *validStrings[] = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A", "D+1", "A+1", "D-1", "A-1", "D+A", "A+D", "D-A", "A-D", "D&A", "D|A", "A&D", "A|D", "M", "!M", "-M", "M+1", "M-1", "D+M", "M+D", "D-M", "M-D", "D&M", "D|M", "M&D", "M|D"};
    char *val[] = {"0101010", "0111111", "0111010", "0001100", "0110000", "0001101", "0110001", "0001111", "0110011", "0011111", "0110111", "0001110", "0110010", "0000010", "0000010", "0010011", "0000111", "0000000", "0010101", "0000000", "0010101", "1110000", "1110001", "1110011", "1110111", "1110010", "1000010", "1000010", "1010011", "1000111", "1000000", "1010101", "1000000", "1010101"};
    for (int i = 0; i < 34; i++)
    {
        if (strcmp(validStrings[i], st) == 0)
        {
            for (int j = 0; j < 7; j++)
            {
                inst->bit[j+6] = val[i][6-j];
            }
        }
    }
}
void getDest(char *st, HackInst *inst)
{
    for (int i = 0; i < strlen(st); i++)
    {
        if (st[i] == 'A')
            inst->bit[5] = '1';
        if (st[i] == 'D')
            inst->bit[4] = '1';
        if (st[i] == 'M')
            inst->bit[3] = '1';
    }
}
void getJump(char *st, HackInst *inst)
{
    char *validStrings[] = {"JMP", "JLE", "JNE", "JLT", "JGE", "JGT", "JEQ"};
    char *val[] = {"111", "110", "101", "100", "011", "001", "010"};
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(validStrings[i], st) == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                inst->bit[j] = val[i][2 - j];
            }
        }
    }
}

HackInst decodeCInst(char *line)
{
    HackInst inst;
    for (int i = 0; i < 16; i++)
        inst.bit[i] = (i > 12) ? '1' : '0';
    inst.valid=0;
    int sInst = -1, fInst = -1;
    int cEq = -1;
    int cDc = -1;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '=')
            cEq = i;
        if (line[i] == ';')
            cDc = i;
        if (isCChar(line[i]))
        {
            if (sInst == -1)
                sInst = i;
        }
        else if (sInst != -1)
        {
            fInst = i - 1;
            break;
        }
    }
    if (cEq != -1)
    {
        char *tmp = calloc(cEq - sInst +2, sizeof(char));
        strncpy(tmp, line + sInst, cEq - sInst);
        sInst = cEq + 1;
        getDest(tmp, &inst);
    }
    if (cDc != -1)
    {
        char *tmp = calloc(fInst - cDc +2, sizeof(char));
        strncpy(tmp, line + cDc + 1, fInst - cDc);
        fInst = cDc - 1;
        getJump(tmp, &inst);
    }
    char *tmp = calloc(fInst - sInst +2 , sizeof(char));
    strncpy(tmp, line + sInst, fInst - sInst + 1);
    getComp(tmp,&inst);
    return inst;
}