#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofSoundStream soundStream;
		void audioOut(float* output, int bufferSize, int nChannels);

		float phase;

};