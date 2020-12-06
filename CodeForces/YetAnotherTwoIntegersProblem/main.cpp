#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int numTestCases;
    std::cin >> numTestCases;

    int a, b;
    int* minMoves = (int*)calloc(numTestCases, sizeof(int));
    for (int i = 0; i < numTestCases; i++)
    {
        std::cin >> a;
        std::cin >> b;
       
        int max = std::max(a, b);
        int min = std::min(a, b);
        a = min;
        b = max;

        int k = 10;
        minMoves[i] = 0;
        int diff = b - a;

        while (diff)
        {
            int times = diff / k;
            if (times > 0)
            {
                diff = (diff % (k*times));
            }
            

            minMoves[i] += times;
            k--;
        }
    }

    for (int i = 0; i < numTestCases; i++)
    {
        std::cout << minMoves[i] << std::endl;
    }

    return 0;
}