#pragma once

#include "ofMain.h"
class ball
{
	//static const int NumberBall = 100;
public:
	void setup();
	void update(int SpeedX, int SpeedY);
	void draw(ofColor Color);



	int radius;
	ofPoint position;
	ofVec2f speed;
	ofColor color;


};