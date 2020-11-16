#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

int main() {
    int n,k;
    std::string input;

    std::cin >> n >> k;
    std::getline(std::cin, input);
    std::getline(std::cin, input);

    // split the string 
    std::vector<std::string> tokens;

    std::stringstream ss(input);
    std::string token;

    int numberPassed = 0;
    int i = 0;
    int num;
    int comp;
    std::vector<int> nums(n);
    while(std::getline(ss, token, ' ')) {
        nums.push_back(atoi(token.c_str()));

        if (i +1 == k) {
            comp = atoi(token.c_str());
        }

        i++;
        if (i >= n) {
            break;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        num = nums.at(i);
        if (num >= comp && num > 0) {
            numberPassed++;
        }
    }

    std::cout << numberPassed;

    return 0;
}