#include <iostream>

int main()
{
    /*
    This somehow doesn't work. For the input "4744000695826", the server gets the answer "NO" instead of "YES". 
    But if I input the same number locally I get "YES" as answer, which is correct.

    long number;
    std::cin >> number;

    int luckyNumbers = 0;
    while (number != 0) {
        if ((number - 4) % 10 == 0) {
            luckyNumbers++;
        }
        else if ((number - 7) % 10 == 0) {
            luckyNumbers++;
        }

        number /= 10;
    }

    //printf("Lucky numbers: %d", luckyNumbers);
    if (luckyNumbers != 0 && (luckyNumbers == 7 || luckyNumbers == 4)) {
        std::cout << "YES";
    } 
    else {
        std::cout << "NO";
    }*/

    char* input = (char*)malloc(100);
    scanf("%s", input);

    int count = 0;
    while (*input != '\0') {
        if (*input == '4' || *input == '7') {
            count++;
        }
        input++;
    }

    if (count != 0 && (count == 7 || count == 4)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}