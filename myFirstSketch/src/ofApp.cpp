#include "ofApp.h"

void ofApp::setup() {
	x1 = ofRandom(0, ofGetWidth());
	y1 = ofRandom(0, ofGetHeight());
	x2 = ofRandom(0, ofGetWidth());
	y2 = ofRandom(0, ofGetHeight());
	x3 = ofRandom(0, ofGetWidth());
	y3 = ofRandom(0, ofGetHeight());

	speedX1 = ofRandom(-10, 10);
	speedY1 = ofRandom(-10, 10);
	speedX2 = ofRandom(-10, 10);
	speedY2 = ofRandom(-10, 10);
	speedX3 = ofRandom(-10, 10);
	speedY3 = ofRandom(-10, 10);

	radius1 = ofRandom(5, 90);;
	radius2 = ofRandom(5, 90);;
	radius3 = ofRandom(5, 90);;

	color1 = ofColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
	color2 = ofColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
	color3 = ofColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
}

void ofApp::update() {
	//Border check circle 1
	if (x1 <= 0) {
		x1 = 0;
		speedX1 = -speedX1;
	}
	else if (x1 >= ofGetWidth()) {
		x1 = ofGetWidth();
		speedX1 = -speedX1;
	}

	if (y1 <= 0) {
		y1 = 0;
		speedY1 = -speedY1;
	}
	else if (y1 >= ofGetHeight()) {
		y1 = ofGetHeight();
		speedY1 = -speedY1;
	}
	//Border check circle 2
	if (x2 + radius1 <= 0) {
		x2 = 0;
		speedX2 = -speedX2;
	}
	else if (x2 >= ofGetWidth()) {
		x2 = ofGetWidth();
		speedX2 = -speedX2;
	}

	if (y2 <= 0) {
		y2 = 0;
		speedY2 = -speedY2;
	}
	else if (y2 >= ofGetHeight()) {
		y2 = ofGetHeight();
		speedY2 = -speedY2;
	}

	//Border check circle 3
	if (x3 + radius1 <= 0) {
		x3 = 0;
		speedX3 = -speedX3;
	}
	else if (x3 >= ofGetWidth()) {
		x3 = ofGetWidth();
		speedX3 = -speedX3;
	}

	if (y3 <= 0) {
		y3 = 0;
		speedY3 = -speedY3;
	}
	else if (y3 >= ofGetHeight()) {
		y3 = ofGetHeight();
		speedY3 = -speedY3;
	}


	x1 += speedX1;
	y1 += speedY1;
	x2 += speedX2;
	y2 += speedY2;
	x3 += speedX3;
	y3 += speedY3;
}

void ofApp::draw() {
	ofSetColor(color1);
	ofDrawCircle(x1, y1, radius1);
	ofSetColor(color2);
	ofDrawCircle(x2, y2, radius2);
	ofSetColor(color3);
	ofDrawCircle(x3, y3, radius3);
}

void ofApp::keyPressed(int key) {

}