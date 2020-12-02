#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> numbers(200); 
    std::ifstream inputFile;
    inputFile.open("input");

    if (!inputFile.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return 1;
    }

    // Reading contents of file into vector
    std::string line;
    while (std::getline(inputFile, line)) {
        numbers.push_back(std::stoi(line));
    }
    inputFile.close();

    // Finding the two numbers that sum to the year variable
    int year = 2020;
    int length = numbers.size();
    int num;

    int num2;

    for (int i = 0; i < length; i++) {
        num = numbers.at(i);
        for (int j = 0; j < length; j++) {
            num2 = numbers.at(j);
            if (num + num2 == year) {
                std::cout << "Found numbers: (" << num << ", " << num2 << ")" << std::endl;
                std::cout << num << " * " << num2 << " = " << num * num2 << std::endl;
                exit(0);
            }
        }
    }
    return 0;
}