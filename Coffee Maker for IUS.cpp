// TryCoffe1.cpp : First version of the file, started on 10.12.2022. (December 12th 2022)
// Coffee_Maker_for_IUS.cpp : Last version of the file, ended on __.12.2022. (December __ 2022)
// Team members: - Ammar Omerika     220302227 SE
//               - Selma Alic        220302129 CSE
//               - Omer Becic        220302287 SE
//               - Altan Berk Eren   210302301 SE

#include <iostream>
#include <cstdlib>


#include "operationMode.h"
#include "settingMode.h"
#include "qualityOfLife.h"
#include "log.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    //FUNCTIONAL VARIABLES
    char setModeOrUserMode;   //Which mode to use
    char endOfTheDay;         //Finish the machine

    //COFFEE VARIABLES
    string coffeeNames[5] = { "Espresso", "Cappucino", "Hot Chocolate", "Melange", "Americano"};
    int coffeeCups[5] = { 3,3,3,3,3 };            //Number of each coffee            
    double coffeePrices[5] = { 2,2,3.5,3,1.5 };   //Prices of coffees       
    int CoffeePosition;                           //Index of choosen coffee
    double Change;                                //Change that will be given back
    
    //COIN VARIABLES
    const long double coinsValue[7] = { 0.05,0.1,0.2,0.5,1,2,5 };        //Value of coins
    int coinsAmount[7] = {3,3,3,3,3,3,3};                                //Amount of coins
    bool coinsAllowed[7] = {true, true, true, true, true, true, true};   //Acceptable coins

    do {
        //MODE MENU
        oasis1:
        white();
        cls();
        cout << "Do you wish the use the setting mode or operation mode <s/o>" << endl << "~> ";
        cin >> setModeOrUserMode;
        cls();
        if (setModeOrUserMode == 's') {
            yello();
            cinFlush();
            settingModeMenu(coinsValue, coffeePrices, coffeeNames, coinsAmount, coffeeCups, coinsAllowed);
            white();
            
        }
        else if (setModeOrUserMode == 'o') {
            purple();
            cinFlush();
            CoffeePosition = ReturnCoffeePosition(coffeeCups,coffeeNames);
            Change= CoffeePayment(coinsAmount, coinsAllowed, coffeePrices, CoffeePosition);
            ReturnMoney(coinsValue,coinsAmount,coinsAllowed,Change);
            CoffeePour(coffeeCups,CoffeePosition);
            white();
        }
        else if (setModeOrUserMode == 'e') {
            cinFlush();
            easterEgg();
        }
        else {
            cout << "Invalid input" << endl;
            cinFlush();
            pause();
            goto oasis1;
        }

        //CONTINUE OR NOT
        oasis2:
        cout << "Do you wish to use the machine more? <y/n>" << endl << "~> ";
        cin >> endOfTheDay;
        if (endOfTheDay == 'y') {
            cout << endl;
            cinFlush();
        }
        else if (endOfTheDay == 'n') {
            cout << endl;
            cinFlush();
            break;
        }
        else {
            cout << "Invalid input" << endl;
            pause();
            cinFlush();
            goto oasis2;
        }

    } while (true);


    //END OF THE DAY EVALUATION
    cout << "END OF THE DAY EVALUATION: " << endl;
    cout << "Creating file"; loading(); pause();
    logCoffee(coffeeNames, coffeePrices, coinsValue, coffeeCups, coinsAmount, coinsAllowed);
    cout << "Look for it in the text file attached ;)" << endl;
    system("notepad.exe database.txt"); // ACTUALLY OPENS UP THE FILE XD!!!!!!!!@!@q!!@!@!!!!!!!retwe%yre^%#qrt

    return 0;
}
