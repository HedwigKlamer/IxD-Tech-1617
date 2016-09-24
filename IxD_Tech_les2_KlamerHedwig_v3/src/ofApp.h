
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ball.h"

class ofApp : public ofBaseApp {
	static const int NumberBall = 100;
public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

	void mousePressed(int x, int y, int button);

	ball ballGroup[NumberBall];
	ofxPanel gui;
	//ofParameterGroup ballParameters;
	//ofxPanel ballParameters;
	//ofParameter<int> radius;
	ofParameter<float> speedX;
	ofParameter<float> speedY;
	ofParameter<ofColor> color;

	int Count = 0;


};
