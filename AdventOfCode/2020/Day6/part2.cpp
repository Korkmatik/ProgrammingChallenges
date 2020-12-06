#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

int main()
{
    using namespace std;

    fstream inputFile;
    inputFile.open("input");

    string line;
    int numberGroupMembers = 0;
    int numberAnswers = 0;
    map<char, int>* groupAnswers = new map<char, int>();
    while (getline(inputFile, line))
    {
        if (line.size() == 0)
        {
            for (auto it = groupAnswers->begin(); it != groupAnswers->end(); it++)
            {
                if (it->second == numberGroupMembers)
                {
                    numberAnswers++;
                }
            }

            delete groupAnswers;
            groupAnswers = new map<char, int>();
            numberGroupMembers = 0;
        }
        else
        {
            numberGroupMembers++;
            for (int i = 0; i < line.size(); i++)
            {
                char c = line.at(i);
                if (groupAnswers->find(c) != groupAnswers->end())
                {
                    (*groupAnswers)[c] += 1;
                }
                else
                {
                    (*groupAnswers)[c] = 1;
                }
            }
            
        }
    }

    std::cout << "Number Answers: " << numberAnswers << std::endl;

    return 0;
}