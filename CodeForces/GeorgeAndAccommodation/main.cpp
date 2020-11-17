#include <iostream>

int main()
{
    int numberRooms;
    std::cin >> numberRooms;

    int taken, total;
    int rooms = 0;
    while (numberRooms--) {
        std::cin >> taken >> total;
        if ((total - taken)  >= 2) {
            rooms++;
        }
    }

    std::cout << rooms;
    return 0;
}