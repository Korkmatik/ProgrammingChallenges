#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* input = (char*)malloc(102);
    fgets(input, 101, stdin);

    int numberUpperCase = 0;
    int numberLowerCase = 0;
    char* iter = input;
    while (*iter != '\0') {
        if (('a' <= *iter) && (*iter <= 'z')) {
            numberLowerCase++;
        } 
        else if (('A' <= *iter) && (*iter <= 'Z')) {
            numberUpperCase++;
        }
        iter++;
    }

    if (numberUpperCase <= numberLowerCase) {
        while (*input != '\0') {
            if (*input == '\n' || *input == '\r') {
                break;
            }

            if (('a' <= (*input)) && ((*input) <= 'z')) {
                printf("%c", *input);
            }
            else {
                printf("%c", (*input + 32 ));
            }
            input++;
        }
    } else {
        while (*input != '\0') {
            if (*input == '\n' || *input == '\r') {
                break;
            }

            if (('A' <= (*input)) && ((*input) <= 'Z')) {
                printf("%c", *input);
            }
            else {
                printf("%c", (*input - 32 ));
            }
            input++;
        }
    }

    return 0;
}