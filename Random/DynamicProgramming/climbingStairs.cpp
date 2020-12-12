#include <iostream>

/*
 *  Problem: Climbing Stairs
 * 
 *  You are climbing a stair case. It takes n steps to reach to the top.
 *  Each time you can either climb 1 or 2 steps.
 *  In how many distinct ways can you climb to the top?
 * 
 *  Framework for solving DP Problems:
 *  
 *  1. Define the objective function
 *      f(i) is the number of distinct ways to reach the i-th stair.
 *  2. Identify base cases
 *      f(0) = 1
 *      f(1) = 1
 *      f(2) = 2
 *  3. Write down a recurrence relation for the optimized objective function
 *      f(n) = f(n-1) + f(n-2)
 *  4. What's the order of execution?
 *      bottom-up
 *  5. Where to look for the answer?
 *      f(n)
 */

int climbStairs(int n)
{
    int* dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 2; i <= n; i++) 
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int ret =  dp[n];
    delete dp;
    return ret;
}

int main()
{
    printf("Test Case 1:\n");
    printf("f(3)=%d\n", climbStairs(3));

    printf("Test Case 2:\n");
    printf("f(5)=%d\n", climbStairs(5));
    
    return 0;
}