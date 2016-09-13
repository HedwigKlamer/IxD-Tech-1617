#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofxPanel gui;
		ofParameter <int> count;
		ofParameter <float>speedX;
		ofParameter <float>speedY;
};
