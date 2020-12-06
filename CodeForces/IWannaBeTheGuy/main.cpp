#include <iostream>
#include <vector>
#include <string>

void GetSolves(std::vector<int>& solvedLevels, const std::string& input)
{
    std::string number = "";
    for (int i = 0; i < input.size(); i++) 
    {
        if (input.at(i) == ' ') 
        {
            int num = std::atoi(number.c_str());
            number = "";
            bool contains = false;
            for (int i = 0; i < solvedLevels.size(); i++)
            {
                if (solvedLevels[i] == num) 
                {
                    contains = true;
                    break;
                } 
            }
            if (!contains) 
            {
                solvedLevels.push_back(num);
            }
        }
        else if (i == input.size() - 1)
        {
            number += input.at(i);
            int num = std::atoi(number.c_str());
            number = "";
            bool contains = false;
            for (int i = 0; i < solvedLevels.size(); i++)
            {
                if (solvedLevels[i] == num) 
                {
                    contains = true;
                    break;
                } 
            }
            if (!contains) 
            {
                solvedLevels.push_back(num);
            }
        }
        else 
        {
            number += input.at(i);
        }
    }
}

int main()
{
    

    std::string input;
    int levels;
    std::vector<int> solvedLevels;

    // getting max level
    std::getline(std::cin, input);
    levels = std::atoi(input.c_str());

    // getting solveds of little y
    std::getline(std::cin, input);
    GetSolves(solvedLevels, input);

    // getting solveds of little x
    std::getline(std::cin, input);
    GetSolves(solvedLevels, input);

    for (int i = 1; i < levels + 1; i++) 
    {
        bool contains = false;
        for (int j = 0; j < solvedLevels.size(); j++) 
        {
            if (solvedLevels[j] == i) 
            {
                contains = true;
                break;
            }
        }

        if (!contains)
        {
            std::cout << "Oh, my keyboard!" << std::endl;
            return 0;
        }
    }

    std::cout << "I become the guy." << std::endl;

    return 0;
}