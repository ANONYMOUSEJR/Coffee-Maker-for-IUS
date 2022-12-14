#pragma once

#include<iostream>
#include<limits>
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

// Self explanitory...
void easterEgg() {
	yello();
	cls();
	egg();
	// Sets the given text into a string var.
	string Speech = "The coffee flowed from the machine in a smooth, steady stream, each droplet glistening in the light.\nIt was like a dance, a beautiful, mesmerizing performance that drew the eye and captured the imagination.\nAs it made its way into the cup, the coffee seemed to come alive, filling the air with its rich, aromatic scent.\nIt was a fragrance that spoke of comfort and warmth, of cozy nights by the fire and quiet moments of reflection.\n";
	int x = 0;
	// Prints out the words letter-by-letter until the end character '\0'. 
	while (Speech[x] != '\0') {
		cout << Speech[x];
		sleep_for(milliseconds(50));
		x++;
	}
	pause();// This give the user enough time to read.
	pause();
	cls();
	white();
}

// Clears out a potentially corrupted cin.
void cinFlush() {
	cin.clear(); // Clears any error flags in the input stream.
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores all characters up until the newline character.
}
