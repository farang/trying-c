#include <string.h>

void removeLineBreaks(char *str)
{
    int strLen = strlen(str);
    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == '\n')
        {
            for (int i1 = i; i1 < strLen; i1++)
            {
                str[i1] = str[i1 + 1];
                i--;
                strLen--;
            }
        }
    }
}
