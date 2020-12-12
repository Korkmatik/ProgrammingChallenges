#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long numArrangements = 0;

unsigned long long rec(const vector<int>& jolts)
{
    vector<unsigned long long> n;
    int max = jolts[jolts.size()-1];
    cout << "Max: " << max << endl;
    for (int i = 0; i <= max; i++)
    {
        n.push_back(0);
    }

    cout << "N size: " << n.size() << endl;

    n[0] = 1;
    int j = 1;
    int i = 3;
    for (; j < jolts.size(); i++, j++)
    {
        int pos = jolts[j];
        unsigned long long calc = 0;
        for (int k = 1; k <= 3; k++) 
        {
            if (pos - k >= 0)
            {
                calc += n[pos-k];
            }            
        }
        

        cout << "Calc: " << calc << " for: " << pos << endl;
        n[pos] = calc;
    }

    return n[n.size() - 1];
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

    std::cout << "Number Arrangements: " << rec(adapterJolts) << endl;

    return 0;
}