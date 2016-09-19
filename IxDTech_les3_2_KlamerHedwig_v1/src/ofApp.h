#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGUI.h"

#define MAXBALLS 15

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	Ball ball;
	void keyPressed(int key);

	ofxPanel gui;
	ofParameter<int>radius;
	ofParameter<int>speedX;
	ofParameter<int>speedY;

};