#include "Ball.h"

void Ball::setup() {
	for (int i = 0; i < Amount; i++) {
		x[i] = ofRandom(0, ofGetWidth());
		y[i] = ofRandom(0, ofGetHeight());

		speedX[i] = ofRandom(-10, 10);
		speedY[i] = ofRandom(-10, 10);

		radius[i] = ofRandom(3, 50);
		colour[i] = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		//a[i] = ofColor(ofRandom(0, 255)
		//b[i] = ofColor(ofRandom(0, 255)
		//c[i] = ofColor(ofRandom(0, 255)
		//colour[i] = ofColor(a[i], b[i], c[i]);

		//step[i] = 1;
	}

}
void Ball::update() {
	for (int i = 0; i < Amount; i++) {
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
		/*
		if (a[i] <= 0) {
			a[i] =0;
			a[i] += step[i];	
		}
		else if (a[i] >= 255) {
			a[i] = 255;
			a[i] -= step[i];
		}

		x[i] += speedX[i];
		y[i] += speedY[i];
		*/
	}
}
void Ball::draw() {
	for (int i = 0; i < Amount; i++) {
		ofSetColor(colour[i]);
		ofDrawCircle(x[i], y[i], radius[i]);
	}
}
