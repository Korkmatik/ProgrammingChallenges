#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    fstream input;
    input.open("input");
    if (!input.is_open()) 
    {
        cout << "Could not open file" << endl;
        return 1;
    }    

    vector<long> numbers;
    string line;
    while (getline(input, line))
    {
        numbers.push_back(stol(line));
        //cout << "Number: " << line << endl;
    }

    long wrongNumber; 

    /* Part 1 */
    for (int i = 25; i < numbers.size(); i++)
    {
        bool found = false;
        long num = numbers[i];
        for (int j = i - 25; j < i; j++) 
        {
            for (int k = j; k < i; k++) {
                long summand1 = numbers[j];
                long summand2 = numbers[k];

                if (summand1 + summand2 == num) 
                {
                    found = true;
                    break;
                }
            }

            if (found) 
            {
                break;
            }
        }

        if (!found)
        {
            cout << "Found wrong number: " << num << endl;
            wrongNumber = num;
            break;
        }
    }

    /* Part 2 */
    for (int i = 0; i < numbers.size(); i++) 
    {
        int sum = 0;
        vector<long> contiguousNumbers;
        for (int j = i; j < numbers.size(); j++) 
        {
            sum += numbers[j];
            contiguousNumbers.push_back(numbers[j]);
            if (sum == wrongNumber)
            {
                cout << "Found streak" << endl;
                long minNum = contiguousNumbers[0];
                long maxNum = 0;

                cout << "Numbers: " << endl;
                for (int k = 0; k < contiguousNumbers.size(); k++) 
                {
                    cout << contiguousNumbers[k] << endl;

                    minNum = min(minNum, contiguousNumbers[k]);
                    maxNum = max(maxNum, contiguousNumbers[k]);
                }

                cout << "Min: " << minNum << endl;
                cout << "Max: " << maxNum << endl;
                cout << "Encryption weakness: " << minNum + maxNum << endl;
                return 0;
            }

            if (sum > wrongNumber)
            {
                break;
            }
        }
    }

    return 0;
}