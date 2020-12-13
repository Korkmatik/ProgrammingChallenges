#include <iostream>
#include <vector>
#include <cmath>

/* Problem: Paid Staircases
 * 
 * You are climbing a paid staircase. It takes n steps to reach to the top and you have to pay p[i]
 * to step on i-th stair. Each time you can climb 1 or 2 steps.
 * What's the cheapest amount you have to pay to get to the top of the staircase?
 */

int paidStaircase(int n, std::vector<int> p)
{
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = p[1];
    
    for (int i = 2; i <= n; i++)
    {
        dp[i] = std::min(dp[i-1], dp[i-2]) + p[i];
    }

    int ret = dp[n];
    delete dp;
    return ret;
}

int main()
{
    printf("f(3)=%d\n", paidStaircase(3, {0, 3, 2, 4}));
}