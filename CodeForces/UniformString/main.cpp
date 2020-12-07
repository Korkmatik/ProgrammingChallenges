#include <iostream>
#include <string>
#include <vector>

int main()
{
    int numberQueries;
    std::cin >> numberQueries;

    const std::string alphabet = "abcdefghiyklmnopqrstuvwxyz";

    int length, pos;
    std::vector<std::string> generatedStrings;
    for (int i = 0; i < numberQueries; i++)
    {
        std::cin >> length >> pos;
        std::string str = "";
        for (int j = 0; j < length; j++)
        {
            str += alphabet.at(j % pos);
        }

        generatedStrings.push_back(str);
    }

    for (const std::string& str : generatedStrings)
    {
        std::cout << str << std::endl;
    }

    return 0;
}