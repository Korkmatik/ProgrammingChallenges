#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int size = 200;
    int *numbers = (int*)malloc(size * sizeof(int));
    int i = 0;
    
    fp = fopen("input", "r");
    if (fp == NULL) {
        printf("Failed to read file");
        return 1;
    }

    // Reading file line by line
    char* line;
    size_t len = 0;
    while(getline(&line, &len, fp) != -1) {
        if (i >= size) {
            printf("Numbers are to small");
            exit(2);
        }

        numbers[i++] = atoi(line);
    }

    fclose(fp);

    int num1, num2, num3;
    for (int x = 0; x < i; x++) {
        num1 = numbers[x];
        for (int y = 0; y < i; y++) {
            num2 = numbers[y];
            for (int z = 0; z < i; z++) {
                num3 = numbers[z];
                if (num1 + num2 + num3 == 2020) {
                    printf("Found numbers: (%d, %d, %d)\n", num1, num2, num3);
                    printf("%d * %d * %d = %d\n", num1, num2, num3, num1*num2*num3);
                    exit(0);
                }
            }
        }
    }

    return 0;
}