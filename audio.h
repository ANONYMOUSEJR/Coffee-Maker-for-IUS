#pragma once

// Note: for this to work you need to add all the .wav files to the project...

#include<Windows.h>
#pragma comment(lib, "winmm.lib") // This is to link this library to the project because it is needed to play a sound file...

// Sounds used: [https://www.youtube.com/watch?v=FBVrgBNzC8k]. (For beepBeep)
//			   [https://www.youtube.com/watch?v=b1Kd3Pa3sHM]. (For pour and money)
//			   [https://www.youtube.com/watch?v=qTX1lI8COuQ]. (For loading)
//			   [https://youtu.be/watch?v=FwVRkhy5G04].        (For error)
//			   [https://www.youtube.com/watch?v=92VhExh27xQ]. (For egg)

void beepBeep() {
	PlaySound(L"beepbeep.wav", NULL, SND_ASYNC);
	/*
	* - The "L" before the file name is used to tell the compiler to expect the file name to be a Unicode string.
	* - The file name itself is self-explanitory.
	* - the NULL is the parameter set for which output device to use, in this case its the computers default output device.
	* - SND_ASYNC is used to tell the function to play the sound asynchronously (in the background),
	*   this is so that i can play the sound without terminating of the program.
	*/
}

void pour() {

	PlaySound(L"coffeepour.wav", NULL, SND_ASYNC);
	// Look at beepBeep() function for thurough explanation.
}

void money() {
	PlaySound(L"coin.wav", NULL, SND_ASYNC);
	// See line #23.
}

void loading() {
	PlaySound(L"fax.wav", NULL, SND_ASYNC);
	// This is too fun!
}

void error() {
	PlaySound(L"error.wav", NULL, SND_ASYNC);
}

void egg() {

	PlaySound(L"coffeeislove.wav", NULL, SND_ASYNC);
}