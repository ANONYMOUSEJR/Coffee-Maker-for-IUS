// TryCoffe1.cpp : First version of the file, started on 10.12.2022. (December 12th 2022)
// Team members: - Ammar Omerika     220302227 SE
//               - Selma Alic        220302129 CSE
//               - Omer Becic        220302287 SE
//               - Altan Berk Eren   210302301 SE

#include <iostream>
#include <cstdlib>

#include "operationMode.h"
#include "SettingMode.h"
#include "QualityOfLife.h"
#include "Log.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char setModeOrUserMode;
    char endOfTheDay;
    char settingModeAction;
    char continueSettingMode;

    string coffeeNames[5] = { "Espresso", "Cappucino", "Hot Chocolate", "Melange", "Americano"};
    int coffeeCups[5] = { 3,3,3,3,3 }; //Number of each coffee            
    double coffeePrices[5] = { 2,2,3.5,3,1.5 }; //Prices of coffees       
    int CoffeePosition; //Index of choosen coffe
    double Change; //Change that will be given back
    
    const long double coinsValue[7] = { 0.05,0.1,0.2,0.5,1,2,5 }; //Value of coins
    int coinsAmount[7] = {3,3,3,3,3,3,3}; //Amount of coins
    bool coinsAllowed[7] = {true, true, true, true, true, true, true}; //Acceptable coins

    do {
        start:
        //WHICH MODE:
        cout << "Do you wish the use the setting mode or operation mode <s/o>" << std::endl;
        cin >> setModeOrUserMode;

        if (setModeOrUserMode == 's') {
            //SETTING MODE
            cout << "SETTING MODE:" << endl;
            settingModeMenu(coinsValue, coffeePrices, coffeeNames, coinsAmount, coffeeCups, coinsAllowed);
            
        }
        else if (setModeOrUserMode == 'o') {
            cout << "OPERATION MODE:" << endl;
            cout << "Coffee options:" << endl;
            cout << "1) Espresso\n2) Cappucino\n3) Hot Chocolate\n4) Melange\n5) Americano" << endl;
            
            CoffeePosition = ReturnCoffeePosition(coffeeCups,5);
            cout << CoffeePosition;//Delete this sometime later
            Change= CoffeePayment(coinsAmount, coinsAllowed, coffeePrices, CoffeePosition);
            cout << Change;
            ReturnMoney(coinsValue,coinsAmount,coinsAllowed,Change);
        }
        else {
            cout << "Invalid input" << endl;
            exit(1);
        }

        //USE IT MORE OR NOT:
        cout << "Do you wish to use the machine more? <y/n>" << endl;
        cin >> endOfTheDay;
        if (endOfTheDay == 'y') {
            cout << endl;
        }
        else if (endOfTheDay == 'n') {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            exit(1);
        }

    } while (true);


    //END OF THE DAY EVALUATION
    cout << "END OF THE DAY EVALUATION: " << endl;
    logCoffee(coffeeCups);
    // Test.
    return 0;
}
/*
* https://www.youtube.com/watch?v=Uf0AnY9D9gw
*/