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
	//void setColor(int red, int green, int blue);
	void keyPressed(int key);

	bool bSetupArduino;	// flag variable for setting up arduino once

	//ofxJSONElement json;

	//int temp;
	//string weather;
	
	//int redFade;
	//int greenFade;
	//int blueFade;

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
