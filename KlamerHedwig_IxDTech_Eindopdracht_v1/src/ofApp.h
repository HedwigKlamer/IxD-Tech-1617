#pragma once


#include "ofMain.h"
#include "ofxJSON.h"



class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	//void setColor(int red, int green, int blue);
	//void keyPressed(int key);

	ofxJSONElement json;

	

private:
	//ofArduino arduino;
	//void setupArduino(const int& version);
	//void digitalPinChanged(const int& pinNum);
	//void analogPinChanged(const int& pinNum);

};
