#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> years;
    int year;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> year;
        years.push_back(year);
    }

    int currentRank, targetRank;
    std::cin >> currentRank >> targetRank;

    int totalYear = 0;
    for (int i = currentRank - 1; i < targetRank - 1; i++)
    {
        totalYear += years.at(i);
    }

    std::cout << totalYear << std::endl;

    return 0;
}