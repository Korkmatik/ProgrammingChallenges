#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main()
{
    int number;
    scanf("%d", &number);

    std::string in;
    char* input = (char*)malloc((number * 2) *sizeof(char));
    size_t len = 0;

    int i = 0;
    int* gifts = (int*)malloc(number*sizeof(int));
    for (i = 0; i < number; i++) {
        std::cin >> gifts[i];
    }

    int* output = (int*)malloc(sizeof(int)*number);
    for (i = 0; i < number; i++) {
        output[gifts[i]-1] = i+1;
    }

    i = 0;
    for (i = 0; i < number-1; i++) {
        printf("%d ", output[i]);
    }

    printf("%d ", output[i]);

    return 0;
}