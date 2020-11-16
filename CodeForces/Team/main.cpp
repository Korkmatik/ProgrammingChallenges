#include <iostream>
#include <stdio.h>


int main() {
    int numberQuestions;

    scanf("%d", &numberQuestions);

    int numberTake = 0;
    int petya, vasya, tonya;
    for (int i = 0; i < numberQuestions; i++) {
        std::cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2) {
            numberTake++;
        } 
    }

    printf("%d", numberTake);
}