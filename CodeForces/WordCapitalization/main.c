#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* input = malloc(10*10*10);
    scanf("%s", input);

    if ('Z' < input[0]) {
        input[0] = input[0] - (97 - 65);
    }    

    printf("%s", input);

    free(input);

    return 0;
}