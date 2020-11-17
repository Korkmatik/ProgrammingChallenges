#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    scanf("%d", &len);

    char* s = (char*)malloc(len+1);
    scanf("%s", s);

    char* iter = s;
    int num = 0;
    int danik = 0;
    while (*iter != '\0') {
        if (*iter == 'A') {
            num++;
        }
        else {
            danik++;
        }
        iter++;
    }

    if (danik == num) {
        printf("Friendship");
    } 
    else if (danik < num) {
        printf("Anton");
    }
    else {
        printf("Danik");
    }

    free(s);
    return 0;
}