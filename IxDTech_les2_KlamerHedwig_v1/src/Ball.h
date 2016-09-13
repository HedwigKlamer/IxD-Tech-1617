#pragma once
#include "ofMain.h"

class Ball {
	static const int Amount = 5;

public:
	void setup();
	void update();
	void draw();

	float x[Amount];
	float y[Amount];
	float speedX[Amount];
	float speedY[Amount];
	int radius[Amount];
	ofColor colour[Amount];

	//float step[Amount};
	//float a[Amount];
	//float b[Amount];
	//float c[Amount];
};

