#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GetMedian(int start, int n, const vector<int>& nums)
{
    int median = ceil(n / 2.0f) - 1;

    cout << "Median pos: " << start + median << endl;
    cout << "Num: " << nums[start + median] << endl;

    return nums[start + median];
}

int main()
{
    int testCases;
    cin >> testCases;

    int n, k, input;
    while (testCases-- > 0)
    {
        cin >> n >> k;

        vector<int> nums;
        for (int i = 0; i < n * k; i++)
        {
            cin >> input;
            nums.push_back(input);
        }

        vector<int> medians;
        int start = 0;
        for (int i = 0; i < k; i++)
        {
            medians.push_back(GetMedian(start, n, nums));
            start += n;
        }

        int sum = 0;
        for (int i = 0; i < medians.size(); i++)
        {
            sum += medians[i];
        }

        cout << sum << endl;
    }

    return 0;
}