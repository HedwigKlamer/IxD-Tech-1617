#pragma once


#include "ofMain.h"




class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	bool		bSetupArduino;			// flag variable for setting up arduino once

private:
	ofArduino arduino;
	void setupArduino(const int& version);
	void digitalPinChanged(const int& pinNum);
	void analogPinChanged(const int& pinNum);
	void updateArduino();

};

//arduino.sendDigital(PIN_RED, ARD_LOW);
//arduino.sendDigital(PIN_GREEN, ARD_LOW);
//arduino.sendDigital(PIN_BLUE, ARD_HIGH);
