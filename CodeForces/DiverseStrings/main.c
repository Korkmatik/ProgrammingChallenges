#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    char** output = (char**)malloc(sizeof(char*)*test_cases);
    char buffer[101];
    const char* iter;
    int diverse;
    for (int i = 0; i < test_cases; i++) {
        scanf("%s", buffer);
        iter = buffer;

        diverse = 1;
        if (strlen(buffer) > 1) {
            while (*iter != '\0') {
                int adjacent = 0;
                int duplicate = 0;
                const char* iter2 = buffer;
                while (*iter2 != '\0') {
                    if (iter2 == iter) {
                        iter2++;
                        continue;
                    }

                    if (*iter2 == *iter) {
                        duplicate = 1;
                        break;
                    }

                    if ((*iter2) == (*iter) - 1 || (*iter2) == (*iter) + 1) {
                        adjacent = 1;
                        break;
                    }

                    iter2++;
                }

                if(!adjacent || duplicate) {
                    diverse = 0;
                    break;
                }

                iter++;
            }
        }
        

        if (diverse) {
            output[i] = "Yes";
        } else {
            output[i] = "No";
        }
    }

    for (int i = 0; i < test_cases; i++) {
        printf("%s\n", output[i]);
    }

    free(output);

    return 0;
}