#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NumDifferences
{
public:
    NumDifferences() : m_diff1(0), m_diff2(0), m_diff3(0) {};

    int m_diff1;
    int m_diff2;
    int m_diff3;
};

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

    NumDifferences differences;

    for (int i = 1; i < adapterJolts.size(); i++)
    {
        long diff = adapterJolts[i] - adapterJolts[i-1];
        switch (diff)
        {
        case 1:
            differences.m_diff1 += 1;
            break;
        case 2:
            differences.m_diff2 += 1;
            break;
        case 3:
            differences.m_diff3 += 1;
            break;
        default:
            cout << "Default?" << endl;
            break;
        }
    }

    cout << "Differences of 1 Jolt: " << differences.m_diff1 << endl;
    cout << "Differences of 2 Jolt: " << differences.m_diff2 << endl;
    cout << "Differences of 3 Jolt: " << differences.m_diff3 << endl;
    cout << "Multiplikation: " << differences.m_diff1 * differences.m_diff3 << endl;

    return 0;
}