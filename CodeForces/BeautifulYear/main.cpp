#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int initialYear;
    std::cin >> initialYear;
    std::vector<int> digits;
    int digit;
    int year;
    bool found = false;
    
    while (!found) {
        
        year = ++initialYear;
        while (year != 0) {
            digit = year % 10;
            if(std::find(digits.begin(), digits.end(), digit) != digits.end()) {
                found = false;
                break;
            } else {
                digits.push_back(digit);
                found = true;
            }

            year /= 10;
        }

        digits.clear();
    }

    std::cout << initialYear;


    return 0;
}