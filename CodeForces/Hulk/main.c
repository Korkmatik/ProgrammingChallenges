#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    const char* const hate = "I hate";
    const char* const love = "I love";
    const char* const it = "it";
    const char* const that = "that";

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            printf("%s ", hate);
        } else {
            printf("%s ", love);
        }

        if (i < n - 1) {
            printf("%s ", that);
        }
    }

    printf("%s", it);

    return 0;
}