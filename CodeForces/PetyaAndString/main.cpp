#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string input1;
    std::string input2;

    std::cin >> input1;
    std::cin >> input2;

    std::transform(input1.begin(), input1.end(), input1.begin(),
        [](unsigned char c){return std::tolower(c);});

    std::transform(input2.begin(), input2.end(), input2.begin(),
        [](unsigned char c){return std::tolower(c);});

    const char* i1 = input1.c_str();
    const char* i2 = input2.c_str();
    for (int i = 0; i < input1.length(); i++) {
        if (*i1 < *i2) {
            std::cout << -1;
            return 0;
        }

        if (*i1 > *i2) {
            std::cout << 1;
            return 0;
        }

        i1++;
        i2++;
    }

    std::cout << 0;

    return 0;
}