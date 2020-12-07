#include <iostream>
#include <string>
#include <map>
#include <locale>

int main()
{
    int length;
    std::cin >> length;
    std::string input;
    std::cin >> input;

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if (input.length() < alphabet.length())
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    
    std::map<char, bool> contains;
    for (int i = 0; i < alphabet.length(); i++)
    {
        contains.insert(std::make_pair(alphabet.at(i), false));
    }

    std::string tmp = input;
    input = "";
    for (auto c : tmp)
    {
        input += std::tolower(c);
    }
    for (int i = 0; i < input.length(); i++)
    {
        contains[input.at(i)] = true;
    }

    for (auto iter = contains.begin(); iter != contains.end(); iter++)
    {
        if (iter->second == false)
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}