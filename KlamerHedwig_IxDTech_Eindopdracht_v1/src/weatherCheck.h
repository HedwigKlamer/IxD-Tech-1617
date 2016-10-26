#pragma once
#include "ofxJSON.h"

class weatherCheck
{
public:
	void setup();
	void draw();
	void tempCheck();

	ofxJSONElement json;
	bool parsingSuccessful;
	string weather;

	int temp;
	int redFade;
	int greenFade;
	int blueFade;
};

