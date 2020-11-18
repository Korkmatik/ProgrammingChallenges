#include <iostream>

int main()
{
    long long n;
    std::cin >> n;

    n = n % 2 ? -(n+1) / 2 : n / 2;
    std::cout << n;
    return 0;
}