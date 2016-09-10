#include "ofApp.h"

void ofApp::setup() {
	ofSetBackgroundColor(0, 0, 0);

	for (int i = 0; i < AmountBalls; i++) {
		x[i] = ofRandom(0, ofGetWidth());
		y[i] = ofRandom(0, ofGetHeight());

		speedX[i] = ofRandom(-10, 10);
		speedY[i] = ofRandom(-10, 10);

		radius[i] = ofRandom(3, 50);
		color[i] = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	}
}

void ofApp::update() {
	for (int i = 0; i < AmountBalls; i++) {
		if (x[i] <= 0) {
			x[i] = 0;
			speedX[i] = -speedX[i];
		}
		else if (x[i] >= ofGetWidth()) {
			x[i] = ofGetWidth();
			speedX[i] = -speedX[i];
		}

		if (y[i] <= 0) {
			y[i] = 0;
			speedY[i] = -speedY[i];
		}
		else if (y[i] >= ofGetHeight()) {
			y[i] = ofGetHeight();
			speedY[i] = -speedY[i];
		}


		x[i] += speedX[i];
		y[i] += speedY[i];
	}
}

void ofApp::draw() {
	for (int i = 0; i < AmountBalls; i++) {
		ofSetColor(color[i]);
		ofDrawCircle(x[i], y[i], ofRandom(3, 50));
	}
}

void ofApp::keyPressed(int key) {

}