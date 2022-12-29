#pragma once

#include<iostream>

using namespace std;

// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// Quality Of Life Functions:

// Just to prettyfy stuff...
void Boundary() {
	cout << "*****************************************" << endl;
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

// Clears out a pottentially corrupted cin.
void cinFlush() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}