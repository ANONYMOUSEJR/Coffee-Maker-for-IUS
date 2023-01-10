#pragma once
#include <iostream>
#include <cmath>
#include "qualityOfLife.h"
#include "audio.h"

using std::cin;
using std::cout;
using std::endl;
using std::fabs;


//Input which coffee the user wants, and returns its index position
int ReturnCoffeePosition(int arr[],string names[]) {
	do {
		cls();
		int userCoffeeChoice;
		cout << "Coffee options:" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i+1 << ") " << names[i] << endl;
		}
		cout << "Please enter the number of your chosen hot beverage:\n";
		cout <<"~> ";
		cin >> userCoffeeChoice;
		if ((userCoffeeChoice == 1) || (userCoffeeChoice == 2) || (userCoffeeChoice == 3) || (userCoffeeChoice == 4) || (userCoffeeChoice == 5)) {
			if (arr[(userCoffeeChoice - 1)] > 0) {
				return (userCoffeeChoice - 1);
			}
			else {
				cout << "We are out of " << names[userCoffeeChoice - 1] << ", please pick something else." << endl;
			}
		}
		else {
			cout << "We do not have that coffee, please pick something else" << endl;
			cinFlush();
			pause();
			cls();
		}
	} while (true);
}

//Inserting appropirate coins in the machine, and returns how much change should be given
double CoffeePayment(int amount[], bool allowed[], double price[],int coffeeType) {
	
	double coin; // The value of the coin inserted
	double remainingPrice; // How much more money is expected
	int coinIndex; // Index of the type of coin entered
	int coffeePrice; // Price of the coffee
	int coinInFening; //BAM into fenings, used because switch case does not support doubles
	coffeePrice = price[coffeeType];
	remainingPrice = coffeePrice;
	short count = 0;
	start:
	cls();
	if (count == 0) {
		cout << "The coffee you have chosen costs " << coffeePrice << " BAM." << endl << "~> ";
	}
	do {
		if (count >= 1) {
			cls();
			cout << "Please insert " << remainingPrice << " BAM more:" << endl << "~> ";
			if (!isDouble(coin)) {
				cls();
				cout << "This input is invalid, try again";
				cinFlush();
				pause();
				cls();
				goto start;
			}
		}
		cin >> coin;
		count++;

		if (!isDouble(coin)) {
			cls();
			cout << "This input is invalid, try again";
			cinFlush();
			pause();
			cls();
			count--;
			goto start;
		}

		money();
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
			cls();
			cout << "This type of coin is not acceptable." << endl;
			pause();
			count--;
			goto start;
		}
		if (allowed[coinIndex]) {
			amount[coinIndex]++;
			remainingPrice -= coin;
		}
		else {
			cls();
			cout << "This type of coin is not acceptable" << endl;
			pause();
			count--;
			goto start;
		}

	} while (remainingPrice>0);
	return -remainingPrice;
}

//Giving back change
void ReturnMoney(const long double value[],int amount[],bool allowed[], double change) {
	if (change == 0) {
		return;
	}
	cout << "Your change in coins: ";
	double sumMoney=0;

	for (int moneyIndex = 6; moneyIndex >= 0; moneyIndex--) {
		
		while ((change >= value[moneyIndex]) && (allowed[moneyIndex]) && (amount[moneyIndex] > 0)) {
			if (change >= 0.05) {
				cout << value[moneyIndex] << " ";
				
			}
			else if (change > 0) {
				cout << change;
			}
			else {
				break;
			}
			
			amount[moneyIndex]--;
			change = change - value[moneyIndex];
			
		}
		

	}
	double isItEpsilon = fabs(change-0.05); //Following few lines are for fixing the problem caused by cpps memory storage flaws
	if (isItEpsilon < 0.001) {
		cout << 0.05;
	}	
	cout << endl;
}

//Pouring coffee
void CoffeePour(int amount[],int coffeeIndex) {
	cout << endl << "Your coffee is being prepared ;)" << endl;
	pour();
	pause();
	cls();
	amount[coffeeIndex]--;
	cout << "Enjoy your coffee"<<endl;
}
