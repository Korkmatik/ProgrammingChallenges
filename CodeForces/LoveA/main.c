#include <stdio.h>
#include <string.h>

int main()
{
    char str[51];
    scanf("%s", str);

    const char* iterator = str;
    int numAs = 0;
    int length = strlen(str);
    while (*iterator != '\0') 
    {
        if (*iterator == 'a') numAs++;
        iterator++;
    }

    int notA = length - numAs;
    int newLen = length;
    if (notA >= numAs)
        newLen = length - (notA - numAs) - 1;
    printf("%d\n", newLen);

    return 0;
}