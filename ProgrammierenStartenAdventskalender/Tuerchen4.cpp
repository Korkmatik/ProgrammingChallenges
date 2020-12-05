/* Aufgabe:
 * Methode nimm Euro Betrag als Parameter.
 * Methode gibt in der Konsole aus, wie man diesen Betrag in so wenig Münzen wie möglich aufteilen kann
 */

#include <iostream>
#include <vector>

void EuroToCoins(float);
int NumberCoins(float&, int);

using namespace std;

int main()
{
    float input;
    cin >> input;
    EuroToCoins(input);
    return 0;
}

void EuroToCoins(float euros)
{
    euros = euros * 100;

    cout << "2€   : " << NumberCoins(euros, 200) << endl;
    cout << "1€   : " << NumberCoins(euros, 100) << endl;
    cout << "0,50€: " << NumberCoins(euros, 50) << endl;
    cout << "0,20€: " << NumberCoins(euros, 20) << endl;
    cout << "0,10€: " << NumberCoins(euros, 10) << endl;
    cout << "0,05€: " << NumberCoins(euros, 5) << endl;
    cout << "0,02€: " << NumberCoins(euros, 2) << endl;
    cout << "0,01€: " << NumberCoins(euros, 1) << endl;
}

int NumberCoins(float& euros, int coinValue)
{
    int num = 0;
    while (euros >= coinValue)
    {
        euros -= coinValue;
        num++;
    }

    return num;
}