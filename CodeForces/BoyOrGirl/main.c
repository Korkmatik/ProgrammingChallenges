#include <stdlib.h>
#include <stdio.h>

int main() 
{
    char* input = (char*)malloc(100 * sizeof(char));
    scanf("%s", input);

    char* checked = (char*)malloc(100 * sizeof(char));
    int len = 0;
    int num_distrinct = 0;
    int i = 0;
    int found = 0;
    while (*input != '\0') {
        found = 0;
        for (i = 0; i < len; i++) {
            if (checked[i] == *input) {
                input++;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            checked[len++] = *input;
            num_distrinct++;
            input++;
        }

    }

    if (num_distrinct % 2 == 0) {
        printf("CHAT WITH HER!");
    } else {
        printf("IGNORE HIM!");
    }

    return 0;
}