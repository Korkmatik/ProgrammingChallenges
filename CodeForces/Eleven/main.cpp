#include <iostream>
#include <string>
#include <cmath>

// A utility function that returns true if x is perfect square 
bool isPerfectSquare(int x) 
{ 
    int s = sqrt(x); 
    return (s*s == x); 
} 
  
// Returns true if n is a Fibinacci Number, else false 
bool isFibonacci(int n) 
{ 
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both 
    // is a perferct square 
    return isPerfectSquare(5*n*n + 4) || 
           isPerfectSquare(5*n*n - 4); 
} 

int main()
{
    int length;
    std::cin >> length;

    std::string name = "";
    for (int i = 0; i < length; i++)
    {
        if (isFibonacci(i + 1))
            name += 'O';
        else
            name += 'o';
    }

    std::cout << name << std::endl;

    return 0;
}