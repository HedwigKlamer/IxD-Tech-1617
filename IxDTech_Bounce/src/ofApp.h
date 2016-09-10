#pragma once

#include "ofMain.h"

#define AmountBalls 100

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

private:
	float x[AmountBalls];
	float y[AmountBalls];
	float speedX[AmountBalls];
	float speedY[AmountBalls];
	int radius[AmountBalls];
	ofColor color[AmountBalls];
};