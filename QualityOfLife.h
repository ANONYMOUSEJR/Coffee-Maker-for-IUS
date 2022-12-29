#pragma once

#include<iostream>

using namespace std;

// The following two libraries and standards are for the time...
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::seconds;

// Quality Of Life Functions:
void Boundary() {
	cout << "*****************************************" << endl;
}
void pause() {
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1)); cout << ".";
	sleep_for(seconds(1));
}
void cls() {
	system("cls");
}
