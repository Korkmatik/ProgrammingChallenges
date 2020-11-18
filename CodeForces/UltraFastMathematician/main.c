#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char first[101];
    char second[101];
    scanf("%s", first);
    scanf("%s", second);

    int len = strlen(first);
    char* result = (char*)malloc(sizeof(char)*len + 1);
    int i;
    for (i = 0; i < len; i++) {
        result[i] = first[i] == second[i] ? '0' : '1';
    }

    result[i] = 0;

    printf("%s", result);

    return 0;
}