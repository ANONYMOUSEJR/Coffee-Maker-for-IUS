#pragma once

#include<iostream>
#include <string>
#include<limits>
#include <iomanip> // For setw() func.
#include"audio.h"

#undef max 
// This somehow fixes an error code that could come from "max()" in the cin.ignore function, here's where I got it from: [https://stackoverflow.com/a/21959303].

using namespace std;

// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// Quality Of Life Functions:

// Colors.
void white() {
	system("color f");
}

void purple() {
	system("color d");
}

// Spelled like this on purpose!
void yello() {
	system("color e");
}

// Just to prettify stuff...
void boundary() {
	cout << endl;
	string load = "*****************************************************************";
	short x = 0;
	
	while (load[x] != '\0') {
		cout << load[x];
		sleep_for(milliseconds(50));
		x++;
	}
	cout << endl;
}

// Creates the three dot loading thing...
void pause() {
	sleep_for(milliseconds(500)); cout << ".";
	sleep_for(milliseconds(500)); cout << ".";
	sleep_for(milliseconds(500)); cout << ".";
	sleep_for(milliseconds(500)); cout << endl;
}

// Clears the screen.
void cls() {
	system("cls");
}

// Checks if user input is Positive...
bool isPos(int num) {
	if (num >= 0) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if user input is a double... (Using the limits library, and knoweledge from the internet)
bool isDouble(double num) {
	if (cin.fail()) {
		// Input could not be interpreted as a double
		return false;
	}
	else {
		// Input is a valid double
		return true;
	}
}

void hearts(short amnt) {
	cout << "\n";
	string heart = "\003";
	for (short i = 0; i < amnt; i++) {
		cout << heart[0];
		sleep_for(milliseconds(1));
	}
	cout << "\n";
}

// Self explanitory...112
void easterEgg() {
	yello();
	cls();
	egg();
	hearts(112);
	// Sets the given text into a string var.
	string Speech = "The coffee flowed from the machine in a smooth, steady stream, each droplet glistening in the light.\nIt was like a dance, a beautiful, mesmerizing performance that drew the eye and captured the imagination.\nAs it made its way into the cup, the coffee seemed to come alive, filling the air with its rich, aromatic scent.\nIt was a fragrance that spoke of comfort and warmth, of cozy nights by the fire and quiet moments of reflection.\n";
	int x = 0;
	// Prints out the words letter-by-letter until the end character '\0'. 
	while (Speech[x] != '\0') {
		cout << Speech[x];
		sleep_for(milliseconds(50));
		x++;
	}
	hearts(112);
	system("pause");// This give the user enough time to read.
	cls();
	white();
}

// Counts how many digits are in a single double variable.
int _digCount(double cPrice) {
	int x = int(cPrice);
	return (to_string(x).length());
}

// To find the longest digit in an array.
int digCount(double cPrice[]) {
	int digCount = 0;
	for (short i = 0; i < 5; i++) {
		if (digCount < to_string(cPrice[i]).length()) {
			digCount = to_string(cPrice[i]).length();
		}
	}
	return digCount;
}

// To find the longest coffee name in an array.
int charCount(string cTypes[]) {
	int strSize = 0;
	for (short i = 0; i < 5; i++) {
		if (strSize <= cTypes[i].length()) {
			strSize = cTypes[i].length();
		}
	}
	return strSize;
}

// Uses the counted digits to know how many to print out... plus 3 for the dot and two decimal points.
void print(string str, double cPrice, int i) {
	string x = str, y;
	short n = 0;
	while (n < (_digCount(cPrice) + 3)) {
		y +=  x[n];
		n++;
	}
	cout << setw(i) << y;
}

// Clears out a potentially corrupted cin.
void cinFlush() {
	cin.clear(); // Clears any error flags in the input stream.
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores all characters up until the newline character.
}
