#include <iostream>
#include <string>

int main()
{
    int numberPersons;
    int input;
    int max;

    std::cin >> numberPersons;
    for (int i = 0; i < numberPersons; i++) {
        std::cin >> input;
        if (input) {
            std::cout << "HARD";
            return 0;
        }
    }

    std::cout << "EASY";
    return 0;
}