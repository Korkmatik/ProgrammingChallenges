/*
 * Problem:
 * Find the sum of the first N numbers.
 * 
 * Objective Function:
 * f(i) is the sum of the first i elements.
 * 
 * Recurrence relation:
 * f(n) = f(n-1) + n
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int f(int n) 
{
    int* dn = (int*)calloc((n + 1), sizeof(int));
    dn[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dn[i] = dn[i-1] + i;
    }

    int ret = dn[n];
    //free(ret);
    return ret;
}

int main()
{
    printf("Test Case 1:\n");
    int ret = f(0);
    printf("f(0) = %d\n", ret);

    printf("Test Case 2:\n");
    ret = f(1);
    printf("f(1) = %d\n", ret);

    printf("Test Case 3:\n");
    ret = f(5);
    printf("f(5) = %d\n", ret);

    return 0;
}