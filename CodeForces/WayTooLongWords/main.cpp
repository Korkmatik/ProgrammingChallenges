#include <iostream>
#include <vector>
#include <string>

int main()
{
    int numberInput;
    std::cin >> numberInput;

    std::string word;
    std::vector<std::string> output;
    for (int i = 0; i < numberInput; i++)
    {
        std::cin >> word;
        if (word.length() > 10) 
        {
            int shorted = word.length() - 2;
            std::string shortedWord = word.at(0) + std::to_string(shorted) + word.at(word.lengt() - 1);
            output.push_back(shortedWord);
        }
        else
        {
            output.push_back(word);
        }
    }

    for (const std::string& o : output)
    {
        std::cout << o << "\n";
    }

    return 0;
}