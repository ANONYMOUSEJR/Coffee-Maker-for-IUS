// TryCoffe1.cpp : First version of the file, started on 10.12.2022. (December 12th 2022)
// Team members: - Ammar Omerika     220302227 SE
//               - Selma Alic     bot cul   220302129 CSE
//               - Omer Becic   is cul     220302287 SE
//               - Altan Berk Eren   210302301 SE

#include <iostream>
#include <cstdlib>

int main()
{
    char setModeOrUserMode;
    char endOfTheDay;
    char settingModeAction;
    char continueSettingMode;
    int coffeeCups[5] = { 3,3,3,3,3 };
    int coffeePrices[5] = { 2,2,3.5,3,1.5 };
    int coffeeChoice;
    do {
        //WHICH MODE:
        std::cout << "Do you wish the use the setting mode or operation mode <s/o>" << std::endl;
        std::cin >> setModeOrUserMode;
        if (setModeOrUserMode == 's') {
            //SETTING MODE
            std::cout << "SETTING MODE:" << std::endl;
            do {
                //Which action will be performed
                std::cout << "OPTIONS:\nA) Add coffe\nB) Deposit coins\nC) Change prices\nD) Change acceptable coins\n";
                std::cin >> settingModeAction;
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
                    std::cout << "Invalid input";
                    exit(1);
                    break;
                }
                //Does the user wish to stay or exit the setting mode
                std::cout << "Do you wish to continue in the setting mode? <y/n>";
                std::cin >> continueSettingMode;
                if (continueSettingMode == 'y') {
                    std::cout << std::endl;
                }
                else if (continueSettingMode == 'n') {
                    break;
                }
                else {
                    std::cout << "Invalid input";
                    exit(1);
                }
            } while (true);
        }
        else if (setModeOrUserMode == 'o') {
            std::cout << "OPERATION MODE:" << std::endl;
            std::cout << "Coffee options:" << std::endl;
            std::cout << "1) Espresso\n2) Cappucino\n3) Hot Chocolate\n4) Melange\n5) Americano" << std::endl;
            std::cin >> coffeeChoice;
            if (coffeeCups[coffeeChoice - 1] > 0) {
                coffeeCups[coffeeChoice]--;
                //void 
            }
            do {
            } while (true);
        }
        else {
            std::cout << "Invalid input" << std::endl;
            exit(1);
        }
        //USE IT MORE OR NOT:
        std::cout << "Do you wish to use the machine more? <y/n>" << std::endl;
        std::cin >> endOfTheDay;
        if (endOfTheDay == 'y') {
            std::cout << std::endl;
        }
        else if (endOfTheDay == 'n') {
            break;
        }
        else {
            std::cout << "Invalid input" << std::endl;
            exit(1);
        }
    } while (true);
    //END OF THE DAY EVALUATION
    std::cout << "END OF THE DAY EVALUATION: " << std::endl;
}