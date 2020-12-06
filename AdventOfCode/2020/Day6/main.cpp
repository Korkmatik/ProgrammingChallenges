#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::fstream inputFile;
    inputFile.open("input");
    if (!inputFile.is_open()) 
    {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    std::string input;
    std::string groupInput = ""; 
    std::vector<char>* groupAnswers = new std::vector<char>();
    int totalAnswers = 0;
    while (std::getline(inputFile, input))
    {   
        if (input.size() == 0)
        {
            std::cout << "Found empty line" << std::endl;
            std::cout << "Group Input: " << groupInput << std::endl;

            for (int i = 0; i < groupInput.length(); i++)
            {
                char c = groupInput.at(i);
                bool contains = false;
                for (int j = 0; j < groupAnswers->size(); j++)
                {
                    if (c == groupAnswers->at(j))
                    {
                        contains = true;
                        break;
                    }
                }

                if (!contains)
                {
                    groupAnswers->push_back(c);
                }
            }

            std::cout << "Number answers: " << groupAnswers->size() << std::endl;

            // New group
            totalAnswers += groupAnswers->size();
            delete groupAnswers;
            groupAnswers = new std::vector<char>();
            groupInput = "";

            std::cout << "Current answers: "  << totalAnswers << std::endl;

            std::cout << "------------------------------------------------------------------" << std::endl;
        }
        else
        {
            std::cout << "Answer of member in group: " << input << std::endl;
            groupInput += input;
        }
    }

    std::cout << "Sum of groups with yes: " << totalAnswers << std::endl; 

    return 0;
}