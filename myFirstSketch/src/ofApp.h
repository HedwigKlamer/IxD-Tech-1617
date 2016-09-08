#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

private:
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;

	float speedX1;
	float speedY1;
	float speedX2;
	float speedY2;
	float speedX3;
	float speedY3;

	int radius1;
	int radius2;
	int radius3;

	ofColor color1;
	ofColor color2;
	ofColor color3;
};
