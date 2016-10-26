#pragma once


#include "ofMain.h"
#include "weatherCheck.h"
//#include "ofxJSON.h"



class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	bool bSetupArduino;	// flag variable for setting up arduino once

	weatherCheck check;

	float red;
	float green;
	float blue;

private:
	ofArduino arduino;
	void setupArduino(const int& version);
	void digitalPinChanged(const int& pinNum);
	void analogPinChanged(const int& pinNum);

};
