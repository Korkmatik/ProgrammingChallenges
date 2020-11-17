#include <iostream>

int main()
{
    int number, numberOfSubstractions;
    std::cin >> number >> numberOfSubstractions;

    for (int i = 0; i < numberOfSubstractions; i++) {
        if (number % 10 != 0) {
            number--;
        } else {
            number /= 10;
        }
    }

    std::cout << number;
}