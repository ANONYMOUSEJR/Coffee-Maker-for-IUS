#pragma once
#include <iostream>

void IceCream(){
	std::cout << " IT WORKS MATE";
}
//This file is not avaliable immediately
int ReturnCoffeePosition(int arr[], int sizeOfArr) {
	int userCoffeeChoice;
	std::cout << "Please enter the number of your chosen hot beverage:\n ";
	do {
		std::cin >> userCoffeeChoice;
		if ((userCoffeeChoice == 1) || (userCoffeeChoice == 2) || (userCoffeeChoice == 3) || (userCoffeeChoice == 4) || (userCoffeeChoice == 5)) {
			if (arr[(userCoffeeChoice - 1)] > 0) {
				return (userCoffeeChoice - 1);
			}
		}
	} while (true);
}

void CoffeePayment() {

}

void CoffeeDecr() {

}