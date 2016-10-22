#pragma once

#include "ofMain.h"

#define CAM_WIDTH 640
#define CAM_HEIGHT 480

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofVideoGrabber grabber;
		ofImage image;
		ofPixels workspace;

		//int rotate;
		
};
