#pragma once

#include <iostream>
// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::seconds;

// These are just there to make life easier.
using std::cin;
using std::cout;
using std::endl;


/*
int coffeeCups[5] = { 3,3,3,3,3 }; //Number of each coffee
double coffeePrices[5] = { 2,2,3.5,3,1.5 }; //Prices of coffees
int CoffeePosition; //Index of choosen coffee
double Change; //Change that will be given back
long double coinsValue[7] = { 0.05,0.1,0.2,0.5,1,2,5 }; //Value of coins
int coinsAmount[7] = {3,3,3,3,3,3,3}; //Amount of coins
bool coinsAllowed[7] = {true, true, true, true, true, true, true}; //Acceptable coins
system ("cls");
*/

void coinRule(bool arrAllow[], long double arrVal[]) {
	int choice;
	char allow;
	do {
		coinStart:
		system("cls");
		cout << "Which coin type would you like to Allow/Disallow?" << endl;

		for (short i = 0; i < 7; i++) {
			cout << (i + 1) << ") " << arrVal[i] << " BAM, it is set to: " << arrAllow[i] << endl;
		}
		cout << "8) Return." << endl << "~> "; // If the user made a mistke and wanted to go back.
		cin >> choice;

		if (choice != 8) {
			cout << "Set to true(t) or false(f):" << endl;
		}

		switch (choice){
		case 1:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else{
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 2:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 3:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 4:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 5:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 6:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 7:
			if (arrAllow[(choice - 1)]) {
				cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			else {
				cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
				cin >> allow;
			}
			break;

		case 8:
			system("cls");
			break;

		default:
			cout << "This input is invalid, try again";
			sleep_for(seconds(1)); cout << ".";
			sleep_for(seconds(1)); cout << ".";
			sleep_for(seconds(1)); cout << "."; 
			sleep_for(seconds(1));
			goto coinStart;
		}

	} while (1);
}