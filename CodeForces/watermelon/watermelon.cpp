#include <iostream>

int main() 
{
    int weight;
    std::cin >> weight;

    if (weight % 2 == 0) {
        for (int i = 2; i <= weight / 2; i += 2) {
            for (int j = weight; j >= weight / 2; j -= 2) {
                if (i+j == weight) {
                    std::cout << "YES";
                    return 0;
                }
            }
        }

        std::cout << "NO";
    } else {
        std::cout << "NO";
    }

    return 0;
}