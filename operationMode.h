#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int ReturnCoffeePosition(int arr[], int sizeOfArr) {
	int userCoffeeChoice;
	cout << "Please enter the number of your chosen hot beverage:\n ";
	do {
		cin >> userCoffeeChoice;
		if ((userCoffeeChoice == 1) || (userCoffeeChoice == 2) || (userCoffeeChoice == 3) || (userCoffeeChoice == 4) || (userCoffeeChoice == 5)) {
			if (arr[(userCoffeeChoice - 1)] > 0) {
				return (userCoffeeChoice - 1);
			}
		}
	} while (true);
}

double CoffeePayment(int amount[], int allowed[], double price[],int coffeeType) {
	double sumOfCoins=0;//delete this sometime later
	double coin;
	double remainingPrice;
	int coinIndex;
	int coffeePrice;
	int coinInFening;
	coffeePrice = price[coffeeType];
	remainingPrice = coffeePrice;
	cout << "The coffee you have chosen costs "<<coffeePrice<<" BAM." << endl;
	cout << "Please insert the money: " << endl;//delete this sometime later
	do {
		cout << "Please insert "<<remainingPrice<<" BAM more:" << endl;
		cin >> coin;
		coinInFening = coin * 100;
		switch(coinInFening){
		case 5:
			coinIndex = 0;
			break;
		case 10:
			coinIndex = 1;
			break;
		case 20:
			coinIndex = 2;
			break;
		case 50:
			coinIndex = 3;
			break;
		case 100:
			coinIndex = 4;
			break;
		case 200:
			coinIndex = 5;
			break;
		case 500:
			coinIndex = 6;
			break;
		default:
			cout << "This type of coin is not acceptable." << endl;
			continue;
		}
		if (allowed[coinIndex] == 1) {
			amount[coinIndex]++;
			remainingPrice = remainingPrice - coin;
		}
		else {
			cout << "This type of coin is not acceptable." << endl;
		}

	} while (remainingPrice>0);
	return -remainingPrice;
}

void ReturnMoney(long double value[],int amount[],int allowed[], long double change) {
	cout << "Your change in coins: ";
	double sumMoney=0;

	for (int moneyIndex = 6; moneyIndex >= 0; moneyIndex--) {
		
		while ((change >= value[moneyIndex]) && (allowed[moneyIndex] == 1) && (amount[moneyIndex] > 0)) {
			if (change >= 0.05) {
				cout << value[moneyIndex] << " ";
				
			}
			else if (change > 0) {
				cout << change;
			}
			else {
				break;
			}
			sumMoney = sumMoney + value[moneyIndex];
			amount[moneyIndex]--;
			change = change - value[moneyIndex];
			
		}
		

	}
	
	
	

	
}

void CoffeePour(int amount[],int coffeeIndex) {
	cout << "Your coffee is being prepared ;)";
	amount[coffeeIndex]--;
}
