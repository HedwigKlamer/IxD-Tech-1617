
#include "ofApp.h"



void ofApp::setup() {
	for (int i = 0; i < NumberBall; i++) {
		ballGroup[i].setup();
	}
	ballGroup[Count].setup();
	//parameterGroup.add(ballGroup.ballParameters);
	//gui.setup(parameterGroup);

	//ballParameters.setName("ballControls");

	//ballParameters.add(radius.set("Radius", 50, 0, 100));
	/*
	ballParameters.setup("Instellingen", "settings.xml");
	ballParameters.add(speedX.set("SpeedX", 2, 0, 20));
	ballParameters.add(speedY.set("SpeedY", 2, 0, 20));
	ballParameters.add(color.set("Color", ofColor::white));
	*/
	gui.setup("Instellingen", "settings.xml");
	gui.add(speedX.set("SpeedX", 2, 0, 20));
	gui.add(speedY.set("SpeedY", 2, 0, 20));
	gui.add(color.set("Color", ofColor::white));
}

void ofApp::update() {
	for (int i = 0; i < Count; i++) {
		ballGroup[i].update(speedX, speedY);
	}
}

void ofApp::draw() {
	for (int i = 0; i < Count; i++) {
		ballGroup[i].draw(color);
	}
	gui.draw();

}


void ofApp::keyPressed(int key) {
	if (key == ' ') {
		Count--;
	}
	//else if (key == OF_KEY_RETURN) {
	//
	//}
}

void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		Count++;
	}
}

