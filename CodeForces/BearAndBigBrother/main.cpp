#include <iostream>

int main()
{
    int weightLimak, weightBob;
    std::cin >> weightLimak >> weightBob;

    int years = 0;
    while (weightLimak <= weightBob) {
        years++;
        weightLimak *= 3;
        weightBob *= 2;
    }

    std::cout << years;
}