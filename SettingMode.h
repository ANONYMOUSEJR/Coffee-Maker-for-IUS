// Note: This header file uses functions from QOL and audio headers,
// for an explenation on what these functions do go to the respective header file.
#pragma once // Uses libraries once.

#include <iostream>
#include <string>
#include <limits>
#include "audio.h"
#include "qualityOfLife.h"

#undef max
// Check line 8 in QOL header fer an explanation to this...

// This are just there to make life easier.
using namespace std;

/*
Note to self : 
* - Fix the true false stuff. // Done.
* - Remove switch case statements. // Done.
* - Create a func that can change the types(names) of coffee. // Done.
* - Put comments on everything.
* - Create a func for sound. // Done.
*/

// Allows the user to change the amount of coffees inside the machines inventory.
void coffeeInvent(int cAmnt[], string cTypes[]) {
	short choice;
	int temp;

	start:
	cls();
	cout << "Which type of coffee would you like to change the amount of?" << endl;
	for (short i = 0; i < 5; i++) {
		cout << (i + 1) << ") " << cTypes[i] << ": " << cAmnt[i] << endl;
	}
	cout << "6) Return." << endl << "~> ";
	cin >> choice;
	beepBeep();

	if (choice == 6) {
		cls();
		return;
	}
	
	if ((choice >= 1) && (choice <= 5)) {
		cout << cAmnt[choice - 1] << " ~> ";
			cin >> temp;
			beepBeep();
			if (!isPos(temp)) { 
				cout << "Your input is invalid, try again";
				error();
				pause();
				goto start; 
			}
			else { cAmnt[choice - 1] = temp; } // Checks if the Users input is pos, if it is it goes ahead with the change.
		goto start;
	}
	else{
		cout << "Your input is invalid, try again";
		error();
		cinFlush();
		pause();
		goto start;
	}

}

// Allows the user to change the amount of coins in inventory.
void coinInvent(int coinAmnt[], const long double arrVal[]) {
	short choice;
	int temp;

	start:
	cls();
	cout << "Which coin amount would you like to change?" << endl;
	for (short i = 0; i < 7; i++) {
		cout << (i + 1) << ") " << arrVal[i] << ": " << coinAmnt[i] << endl;
	}
	cout << "8) Return." << endl << "~> ";
	cin >> choice;
	beepBeep();

	if (choice == 8) {
		cls();
		return;
	}

	if ((choice >= 1) && (choice <= 7)) {
		cout << coinAmnt[choice - 1] << " ~> ";
		cin >> temp;
		beepBeep();

		if (isPos(temp)) {
			coinAmnt[choice - 1] = temp;
		}
		else{
			cout << "Your input is invalid, try again";
			error();
			pause();
		}
		goto start;
	}
}

// Allows for the user to change the price of certain coffees.
void changePrices(double cPrices[], string cTypes[]) {
	short choice;
	double temp;

	start:
	cls();
	cout << "Which coffee prices would you like to change?" << endl;
	for (short i = 0; i < 5; i++) {
		cout << (i + 1) << ") " << cTypes[i] << ": " << cPrices[i] << endl;
	}
	cout << "8) Return." << endl << "~> ";
	cin >> choice;
	beepBeep();

	if (choice == 8) {
		cls();
		return;
	}

	if ((choice >= 1) && (choice <= 7)) {
		cout << cPrices[choice - 1] << "~> ";
		cin >> temp;
		beepBeep();
		if (!isDouble(temp)) {
			cout << "Your input is invalid, try again";
			error();
			cinFlush();
			pause();
			goto start;
		}
		else{
			cPrices[choice - 1] = temp;
		}
	}else{
		cout << "Your input is invalid, try again";
		error();
		cinFlush();
		pause();
		goto start;
	}
	goto start;
}

// Allows the user to allow/disallow certain coin types.
void coinRule(bool arrAllow[], const long double arrVal[]) {
short choice;
char allow;

start:
cls();
cout << "Which coin type would you like to Allow/Disallow?" << endl;

for (short i = 0; i < 7; i++) {
	if (arrAllow[i] == true) {
		cout << (i + 1) << ") " << arrVal[i] << " BAM, it is set to: TRUE" << endl;
	}
	else if (arrAllow[i] == false){
		cout << (i + 1) << ") " << arrVal[i] << " BAM, it is set to: FALSE" << endl;
	}
}
cout << "8) Return." << endl << "~> "; // If the user made a mistake and wanted to go back.
cin >> choice;
beepBeep();

// Check so that user isnt able to input an invalid value.
if (!(choice >= 1) && !(choice <= 8)) {
	cout << "Your input is invalid, try again";
	error();
	cinFlush();
	pause();
	goto start;
}

if (choice == 8) {
	cls();
	return;
}

cout << "Set to true(t) or false(f): " << endl;

if (arrAllow[(choice - 1)] == true) {
	cout << arrVal[(choice - 1)] << " is allowed, set to: " << endl << "~> ";
	cin >> allow;
	beepBeep();
	
	if (allow != 't') {
		arrAllow[(choice - 1)] = false;
	}
}
else if(arrAllow[(choice - 1)] == false){
	cout << arrVal[(choice - 1)] << " is not allowed, set to: " << endl << "~> ";
	cin >> allow;
	beepBeep();
	if (allow != 'f') {
		arrAllow[(choice - 1)] = true;
	}
}
goto start;
}

// Allows the user to change the names of offered coffees.
void coffeeName(string cTypes[]) {
	short choice;

	start:
	cls();

	cout << "Which coffee name would you like to modify?" << endl;

	for (short i = 0; i < 5; i++) {
		cout << (i + 1) << ") " << cTypes[i] << "." << endl;
	}
	cout << "6) Return." << endl << "~> ";
	cin >> choice;
	beepBeep();

	// discard remaining characters in the input stream
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	/*
	*	This is because otherwise the function would automatically input a "." into the array...
	*	TYSM Şukru!
	*/

	if (choice == 6) {
		cls();
		return;
	}

	if ((choice >= 1) && (choice <= 5)) {
		cout << cTypes[choice - 1] << " ~> ";
		getline(cin, cTypes[choice - 1]);
		beepBeep();
	}
	else {
		cout << "Your input is invalid, try again";
		error();
		pause();
	}
	goto start;
}

// Shows the status and settings of all the functions.
void stat(const long double arrVal[], double cPrices[], string cTypes[], int coinAmnt[], int cAmnt[], bool arrAllow[]) {
	short choice;
	start:
	cls();

	cout << "Coffee details:" << endl;
	for (short i = 0; i < 5; i++) {
		cout << (i + 1) << ") " << cTypes[i] << ": " << cPrices[i] << " KM. 	Amount left:" << cAmnt[i] << endl;
	}

	cout << endl;
	boundary();
	cout << endl;

	cout << "Monetary details:" << endl;

	for (short i = 0; i < 7; i++) {
		if (arrAllow[i] == true) {
			cout << (i + 1) << ") " << arrVal[i] << " BAM, it is set to: TRUE.		Amount Left: " << coinAmnt[i] << endl;
		}
		else if (arrAllow[i] == false) {
			cout << (i + 1) << ") " << arrVal[i] << " BAM, it is set to: FALSE.		Amount Left: " << coinAmnt[i] << endl;
		}
	}
	cout << endl << endl << "Input 0 to Return." << endl << "~> ";
	cin >> choice;

	if (choice == 0){
		beepBeep();
		cls();
		return;
	}
	else {
		cout << "Your input is invalid, try again";
		error();
		cinFlush();
		pause();
		goto start;
	}
}

// Gives the user a menu of the above functions to choose from.
void settingModeMenu(const long double arrVal[], double cPrices[], string cTypes[], int coinAmnt[], int cAmnt[], bool arrAllow[]) {
	short choice;
	system("color e");
	beepBeep();

start:
	cls();
	cout << "Which menu would you like to access?" << endl;
	cout << "OPTIONS:\n1) Stored coffee.\n2) Stored coins.\n3) Change prices.\n4) Change Allowed coins.\n5) Change coffee names.\n6) Stats.\n7) Return." << "\n~> ";
	cin >> choice;
	beepBeep();


	switch (choice) {
	case 1:
		coffeeInvent(cAmnt, cTypes);
		break;

	case 2:
		coinInvent(coinAmnt, arrVal);
		break;

	case 3:
		changePrices(cPrices, cTypes);
		break;

	case 4:
		coinRule(arrAllow, arrVal);
		break;

	case 5:
		coffeeName(cTypes);
		break;

	case 6:
		stat(arrVal, cPrices, cTypes, coinAmnt, cAmnt, arrAllow);
		break;

	case 7:
		cls();
		system("color f");
		beepBeep();
		return;

	default:
		cout << "Your input is invalid, try again";
		error();
		pause();
		break;
	}
	goto start;
}