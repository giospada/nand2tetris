#include "LineProcessor.h"


LineType getLineType(const char* inp){
    LineType linetype=Temp_Line;
    int n=strlen(inp);
    for(int i=0;i<n && linetype==Temp_Line;i++){
        switch (inp[i])
        {
        case '@':
            linetype=AInst_Line;
            break;
        case 'A':
        case 'D':
        case 'M':
        case '0':
        case '1':
            linetype=CInst_Line;
            break;
        case '/':
            linetype=Void_Line;
            break;
        case '(':
            linetype=Label_Line;
            break;
        default:
            break;
        }
    }
    return linetype;
}




HackInst lineToHack(char* line,SymbolicTable* st){
    HackInst hackInst;
    hackInst.valid=1;
    switch (getLineType(line))
    {
    case AInst_Line:
        hackInst=decodeAInst(line,st);
        break;
    case CInst_Line:
        hackInst=decodeCInst(line);
        break;
    }
    return hackInst;
}