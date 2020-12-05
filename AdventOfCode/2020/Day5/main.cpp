#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int Row(const string& input, int index, int lower, int upper)
{
    char c = input.at(index++);

    int mid = (lower + upper) / 2;

    switch (c)
    {
        case 'F':
            cout << "Taking lower half from " << lower << ", " << upper << endl;
            
            upper = mid;
            break;
        case 'B':
            lower = mid;
            break;
        default:
            cout << "Default with character: " << c << endl;
            char previousChar = input.at(index - 2);

            cout << "Previous Character: "  << previousChar << endl;

            switch (previousChar)
            {
                case 'F':
                    return lower;
                case  'B':
                    return upper;
            }
            break;
    }

    cout << "Calliing with " << lower << ", " << upper << endl;

    return Row(input, index, lower, upper);
}

int Column(const string& input, int index, int lower, int upper) 
{
    int mid = (upper + lower) / 2;
    char c = input.at(index++);
    if (index == input.size())
    {
        switch (c)
        {
            case 'R':
                return upper - 1;
            case 'L':
                return lower;
            default:
                cout << "Last Character: " << c << endl;
                break;
        }
    }

    
    

    switch (c)
    {
        case 'R':
            cout << "Taking upper half" << endl;
            lower = mid;
            break;
        case 'L':
            cout << "Taking lower half" << endl;
            upper = mid;
            break;
        default:
            break;
    }

    cout << "Calling with: " << upper << ", " << lower << endl;

    return Column(input, index, lower, upper);
}

int main()
{
    string input;
    
    ifstream inputFile;
    inputFile.open("input");
    if (!inputFile.is_open()) {
        cout << "Could not open input file" << endl;
        return 1;
    }

    int maxSeatID = 0;
    int row, column, seatID;
    map<string, int> lines;

    vector<string> testData = {
        "FBFBBFFRLR", "BFFFBBFRRR", "FFFBBBFRRR", "BBFFBBFRLL"
    };

    while (getline(inputFile, input)) {

    /*for (int i = 0; i < testData.size(); i++) {*/

        row = Row(input, 0, 0, 128);
        column = Column(input, 0, 0, 8);
        seatID = row * 8 + column;

        maxSeatID = max(seatID, maxSeatID);

        lines[input] = seatID;
    }

    for (auto iter = lines.begin(); iter != lines.end(); iter++) 
    {
        std::cout << "Line: " << iter->first << ", Seat ID: " << iter->second << endl; 
    }

    inputFile.close();
    cout << "Maxium Seat ID: " << maxSeatID << endl;

    return 0;
}
