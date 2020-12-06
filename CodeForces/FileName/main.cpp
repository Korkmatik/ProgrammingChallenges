#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string>

int main()
{
    int length = 0;
    scanf("%d", &length);

    char* fileName = (char*)malloc(length*sizeof(char));
    scanf("%s", fileName);

    bool xMode = false;
    int numberDel = 0;
    int x = 0;
    while (*fileName != '\0')
    {
        if (*fileName == 'x' && !xMode)
        {
            xMode = true;
        }

        if (xMode && *fileName != 'x')
        {
            xMode = false;
            numberDel = numberDel + std::max(0, x - 2);
            x = 0;
        }

        if (xMode)
        {
            x++;
        }

        fileName++;
    }

    if (xMode)
    {
        numberDel = numberDel + std::max(0, x - 2);
    }

    printf("%d\n", numberDel);

    return 0;
}