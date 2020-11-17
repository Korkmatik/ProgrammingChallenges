#include <iostream>

int main()
{
    int bananaCost, initialMoney, numberBananas;
    std::cin >> bananaCost >> initialMoney >> numberBananas;

    int totalCost = 0;
    for (int i = 1; i <= numberBananas; i++) {
        totalCost += i * bananaCost;
    }

    int moneyToBorrow = totalCost - initialMoney;
    if (moneyToBorrow < 0) {
        moneyToBorrow = 0;
    }
    std::cout << moneyToBorrow;

    return 0;
}