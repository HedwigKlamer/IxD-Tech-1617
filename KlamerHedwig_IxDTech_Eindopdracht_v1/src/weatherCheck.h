#pragma once
#include "ofApp.h"
#include "ofxJSON.h"

class weatherCheck
{
public:
	void setup();
	void draw();
	void tempCheck();

	ofxJSONElement json;

	string weather;

	int temp;
	int redFade;
	int greenFade;
	int blueFade;
};

