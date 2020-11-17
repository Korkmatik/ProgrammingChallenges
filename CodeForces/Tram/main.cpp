#include <iostream>

int main()
{
    int numberTrams, in, out, max = 0;

    std::cin >> numberTrams;

    int currentNumber = 0;
    for (int i = 0; i < numberTrams; i++) {
        std::cin >> in >> out;
        currentNumber = currentNumber - in + out;
        if (currentNumber > max) {
            max = currentNumber;
        }
    }

    std::cout << max;

    return 0;
}