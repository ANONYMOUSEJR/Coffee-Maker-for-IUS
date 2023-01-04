#pragma once
#pragma warning(disable : 4996) // To disable the deprecated error that show us when ctime function is used.

#include<iostream>
#include<fstream>
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include <ctime>


void logCoffee(std::string coffeeNames[], double coffeePrices[], const long double coinsValue[], int coffeeCups[], int coinsAmount[], bool arrAllow[]) {

	time_t rawDate = time(nullptr);// taking the time as second

	std::string date = ctime(&rawDate);

	std::ofstream dbW("dataBase.txt", std::ios_base::out);

	dbW << date << "\n\n";

	dbW << "Coffee types:\n";
	for (int i = 0; i < 5; i++)
		dbW << coffeeNames[i] << "\n";

	dbW << "\nCoffee prices:\n";
	for (int i = 0; i < 5; i++)
		dbW << coffeeNames[i] << " -> " << coffeePrices[i] << " KM." << "\n";
	dbW << "\nValid Coin Types:\n";
	for (int i = 0; i < 5; i++)
		dbW << coinsValue[i] << " -> " << arrAllow[i] << "\n";

	dbW << "\nNumber of each coffee:\n";
	for (int i = 0; i < 5; i++)
		dbW << coffeeNames[i] << " -> " << coffeeCups[i] << '\n';

	dbW << "\nCoin amounts:\n";

	double total = 0;

	for (int i = 0; i < 7; i++) {
		dbW << coinsValue[i] << ": " << coinsAmount[i] << '\n';
		total += coinsValue[i] * coinsAmount[i];
	}

	dbW << "\nMoney Earned: "<< (total - 26.55);
	dbW << "\nTotal in Machine: " << total << " KM.\n\n" << "\n\nEnd of the Log file\n\n";
}

