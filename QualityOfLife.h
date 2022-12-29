#pragma once

#include<iostream>

using namespace std;

// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::seconds;

// Quality Of Life Functions:

// Just to prettyfy stuff...
void Boundary() {
	cout << "*****************************************" << endl;
}

// Creates the three dot loading thing...
void pause() {
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1));
}

// 
void cls() {
	system("cls");
}
