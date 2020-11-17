#include <iostream>

int main()
{
    int length;
    std::cin >> length;

    int steps = 0;
    while (length > 0) {
        if (length >= 5) {
            length -= 5;
        } else if (length >= 4) {
            length -= 4;
        } else if (length >= 3) {
            length -= 3;
        } else if (length >= 2) {
            length -= 2;
        } else if (length >= 1) {
            length -= 1;
        }

        steps++;
    }

    std::cout << steps;

    return 0;
}