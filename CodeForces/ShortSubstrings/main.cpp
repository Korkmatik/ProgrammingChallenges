#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);

    std::vector<std::string> allOutputs;
    for (int i = 0; i < numTestCases; i++)
    {
        std::string input;
        std::cin >> input;
        
        std::string output = "";

        for (int j = 0; j < input.size(); j++)
        {
            if (j < 2)
            {
                output += input.at(j);
            }
            else
            {
                output += input.at(++j);
            }
        }
        allOutputs.push_back(output);
    }

    for (int i = 0; i < allOutputs.size(); i++)
    {
        std::cout << allOutputs[i] << std::endl;
    }

    return 0;
}