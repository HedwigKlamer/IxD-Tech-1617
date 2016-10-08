#pragma once

#include "ofMain.h"

class Ball {

public:

	Ball();

	void setup(int mySpeedX, int mySpeedY, int mySpeedZ, int myRadius, ofColor myColour);

	void update();

	void draw();

	// variables
	float x;
	float y;
	float z;
	float speedY;
	float speedX;
	float speedZ;
	float zMax;
	int radius;
	ofColor color;

private:

};
