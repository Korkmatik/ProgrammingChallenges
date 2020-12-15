#include <iostream>
#include <vector>

using namespace std;

void ReadArr(vector<int>& arr, const int& n)
{
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr[i] = val;
    }
}

bool Rearrange(const vector<int>& a, vector<int>& b, const int& x)
{
    for (int i = 0; i < a.size(); i++) 
    {
        int startIndex = i;
        int index;
        int num = a[i];
        int max = -1;
        for (int j = i; j < b.size(); j++)
        {
            if ((b[j] + a[i] <= x) && (b[j] > max))
            {
                max = b[j];
                index = j;
            }
        }

        if (max != -1)
        {
            int tmp = b[startIndex];
            b[startIndex] = b[index];
            b[index] = tmp;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] + b[i] > x)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int testCases;
    cin >> testCases;

    int n, x;
    vector<string> output;
    while (testCases-- > 0)
    {
        cin >> n >> x;

        vector<int> a(n);
        vector<int> b(n);

        ReadArr(a, n);
        ReadArr(b, n);

        output.push_back(Rearrange(a, b, x) ? "Yes" : "No");
    }

    for (string& o : output)
    {
        std::cout << o << std::endl;
    }

    return 0;
}