#pragma once
#include "ofMain.h"
class Planet
{
public:
	Planet();
	virtual ~Planet();
	void setup(string name);
	void update();
	void draw();

	ofParameterGroup planetParameterGroup;
	ofParameter<float> rotateSpeed;
	ofParameter<float> distance;
	ofParameter<ofColor> colour;

	float rotation;
};

