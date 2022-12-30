#pragma once

#include<iostream>
#include<limits>

using namespace std;

// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// Quality Of Life Functions:

// Just to prettyfy stuff...
void Boundary() {
	cout << "***********************************************************" << endl;
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
	if (num > 0) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if user input is a double... (Using the limits library, and knoweledge from the internet)
bool isDouble(double num) {
	if (cin.fail()) {
		// input could not be interpreted as a double
		return false;
	}
	else {
		// input is a valid double
		return true;
	}
}

// Self explanitory...
void easterEgg() {
	string Speech = "The coffee flowed from the machine in a smooth, steady stream, each droplet glistening in the light.\nIt was like a dance, a beautiful, mesmerizing performance that drew the eyeand captured the imagination.\nAs it made its way into the cup, the coffee seemed to come alive, filling the air with its rich, aromatic scent.\nIt was a fragrance that spoke of comfortand warmth, of cozy nights by the fireand quiet moments of reflection.\n";
	int x = 0;
	while (Speech[x] != '\0') {
		cout << Speech[x];
		sleep_for(milliseconds(50));
		x++;
	}
	cls();
}

// Clears out a pottentially corrupted cin.
void cinFlush() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}