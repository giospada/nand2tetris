#include "StringOperation.h"

char *strAppendInt(char *str, int i)
{
    char *temp = intToString(i);
    strcat(str, temp);
    free(temp);
    return str;
}

int strFirstSub(char *s1, char *s2)
{
    int pos = -1;
    int ls1 = strlen(s1);
    int ls2 = strlen(s2);
    for (int i = 0; i <= (ls1 - ls2) && pos == -1; i++)
    {
        int j = 0;
        while (j < ls2 && s1[i + j] == s2[j])
            j++;

        if (j == ls2)
            pos = i;
    }
    return pos;
}

char *copyString(char *s1)
{
    char *newStr = malloc(sizeof(char) * (strlen(s1) + 2));
    for (int i = 0; i < strlen(s1); i++)
    {
        newStr[i] = s1[i];
    }
    newStr[strlen(s1)]='\0';
    return newStr;
}

int getDigit(char a)
{
    if ('0' <= a && a <= '9')
        return ((int)a - '0');
    else
        return -1;
}

int toInt(int i, char *s)
{
    int res = 0;
    int digit = 0;
    while (i < strlen(s) && (digit = getDigit(s[i])) == -1)
        i++;

    for (; i < strlen(s) && (digit = getDigit(s[i])) != -1; i++)
    {
        res *= 10;
        res += digit;
    }
    return res;
}

char *intToString(int from)
{
    int n = 0;
    {
        int temp = from;
        while (temp > 0)
        {
            n++;
            temp /= 10;
        }
    }
    char *res = malloc(sizeof(char) * (n + 2));
    int i = 0;
    for (; i < n; i++)
    {
        int resto = from % 10;
        from /= 10;
        res[n - i - 1] = ((char)(resto + '0'));
    }
    res[i] = '\0';
    return res;
}