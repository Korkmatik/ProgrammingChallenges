#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>

int main() 
{
    char input[100];
    scanf("%s", input);

    std::vector<int> numbers;

    char* iter = input;
    int num;
    while(*iter != '\0') {
        num = *iter - '0';
        if (0 <= num <= 9) {
            numbers.push_back(num);
        }
        iter++;
    }

    std::sort(numbers.begin(), numbers.end());

    int len = numbers.size();
    for (int i = 0; i < len; i++) {
        num =  numbers.at(i);
        if (num == -5) {
            continue;
        }
        std::cout << num;
        if (i < len - 1) {
            printf("+");
        }
    }
}