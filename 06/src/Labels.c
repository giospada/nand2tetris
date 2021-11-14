#include "Labels.h"

Label readAllLabels(Input *inp)
{
    Label labels;
    labels.codeLines = 0;
    labels.el = createAllocator();
    for (int row = 0; row < inp->input.len; row++)
    {
        char *line = getFromAllocator(&inp->input, row);
        LineType linetype = getLineType(line);
        switch (linetype)
        {
        case Label_Line:
        {
            int posI = 0, posF = 0;
            for (int i = 0; i < strlen(line); i++)
            {
                if (line[i] == '(')
                    posI = i + 1;
                else if (line[i] == ')')
                    posF = i;
            }
            char *toCopy = calloc(posF - posI + 2, sizeof(char));
            for (int i = posI; i < posF; i++)
            {
                toCopy[i - posI] = line[i];
            }
            toCopy[posF] = '\0';

            LRow *codeline = (LRow *)calloc(1, sizeof(LRow));
            codeline->key=toCopy;
            codeline->val = labels.codeLines;
            addElement(&labels.el, codeline);
        }
        break;
        case AInst_Line:
        case CInst_Line:
            labels.codeLines++;
            break;
        }
    }
    return labels;
}
