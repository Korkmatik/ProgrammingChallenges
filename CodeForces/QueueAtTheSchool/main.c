#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length, time;
    scanf("%d %d", &length, &time);

    char* initialQueue = (char*)malloc(length+1);
    scanf("%s", initialQueue);

    for (int i = 0; i < time; i++) {
        for (int j = 0; j < length-1; j++) {
            if (initialQueue[j] == 'B' && initialQueue[j+1] == 'G') {
                initialQueue[j] = 'G';
                initialQueue[++j] = 'B';
            }
        }
    }

    printf("%s", initialQueue);

    free(initialQueue);

    return 0;
}