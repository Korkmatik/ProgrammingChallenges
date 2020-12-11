#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long numArrangements = 0;

void rec(vector<int> adapterJolts)
{
    vector<int> possibilities;
    possibilities.push_back(1);

    for (int i = 0; i < adapterJolts.size(); i++)
    {
        int num = adapterJolts[i];
        if (possibilities.size() < 3)
        {
            
        }
    }
}

int main()
{
    fstream input;
    vector<int> adapterJolts;

    input.open("input");
    if (!input.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }

    string line;
    adapterJolts.push_back(0);
    while (getline(input, line)) 
    {
        adapterJolts.push_back(stoi(line));
    }

    sort(adapterJolts.begin(), adapterJolts.end());
    adapterJolts.push_back(adapterJolts[adapterJolts.size() - 1] + 3);
    cout << "Numbers:" << endl;
    for_each(adapterJolts.begin(), adapterJolts.end(), [](int n) {
        cout << n << endl;
    });

    rec(adapterJolts);

    std::cout << "Number Arrangements: " << numArrangements << endl;

    return 0;
}