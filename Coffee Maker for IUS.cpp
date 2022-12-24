// TryCoffe1.cpp : First version of the file, started on 10.12.2022. (December 12th 2022)
// Team members: - Ammar Omerika     220302227 SE
//               - Selma Alic        220302129 CSE
//               - Omer Becic        220302287 SE
//               - Altan Berk Eren   210302301 SE

//DID I CHANGE ANYTHING IN HERE?
//Selma changed this file, she didnt
#include <iostream>
#include <cstdlib>

#include "operationMode.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char setModeOrUserMode;
    char endOfTheDay;
    char settingModeAction;
    char continueSettingMode;

    int coffeeCups[5] = { 3,3,3,3,3 };
    double coffeePrices[5] = { 2,2,3.5,3,1.5 };//
    int CoffeePosition;
    double Change;
    //int coffeeChoice;
    
    double coinsValue[7] = { 0.05,0.1,0.2,0.5,1,2,5 };
    int coinsAmount[7] = {3,3,3,3,3,3,3};
    int coinsAllowed[7] = {1,1,1,1,1,1,1};//
    IceCream();

    do {
        start:
        //WHICH MODE:
        cout << "Do you wish the use the setting mode or operation mode <s/o>" << std::endl;
        cin >> setModeOrUserMode;

        if (setModeOrUserMode == 's') {
            //SETTING MODE
            cout << "SETTING MODE:" << std::endl;
            do {
                //Which action will be performed 
                cout << "OPTIONS:\nA) Add coffee\nB) Deposit coins\nC) Change prices\nD) Change acceptable coins\n";
                cin >> settingModeAction;
                switch (settingModeAction)
                {
                case 'A':
                    //Process A: Adding coffee
                    break;
                case 'B':
                    //Process B: Depositing coins
                    break;
                case 'C':
                    //Process C: Changing prices
                    break;
                case 'D':
                    //Process D: Changing acceptable coins
                    break;
                default:
                    cout << "Invalid input";
                    goto start;
                    //exit(1);
                    break;
                }
                //Does the user wish to stay or exit the setting mode
                cout << "Do you wish to continue in the setting mode? <y/n>";
                cin >> continueSettingMode;
                if (continueSettingMode == 'y') {
                    cout << endl;
                }
                else if (continueSettingMode == 'n') {
                    break;
                }
                else {
                    cout << "Invalid input";
                    exit(1);
                }
            } while (true);
        }
        else if (setModeOrUserMode == 'o') {
            cout << "OPERATION MODE:" << endl;
            cout << "Coffee options:" << endl;
            cout << "1) Espresso\n2) Cappucino\n3) Hot Chocolate\n4) Melange\n5) Americano" << endl;
            
            CoffeePosition = ReturnCoffeePosition(coffeeCups,5);
            cout << CoffeePosition;
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
    // Test.
}