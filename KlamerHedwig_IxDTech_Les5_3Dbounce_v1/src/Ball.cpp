#include "Ball.h"

Ball::Ball() {
}

void Ball::setup(int mySpeedX, int mySpeedY,int mySpeedZ, int myRadius, ofColor myColour) {
	zMax = -5000;
	
	x = ofRandom(0, ofGetWidth());        // give some random position
	y = ofRandom(0, ofGetHeight());
	z = ofRandom(zMax, 0);

	speedX = mySpeedX;           // and random speed and direction
	speedY = mySpeedY;
	speedZ = mySpeedZ;

	radius = myRadius;

	color = myColour;
}


void Ball::update() {
	//x as boundary check
	if (x < 0) {
		x = 0;
		speedX *= -1;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX *= -1;
	}
	//y as boundary check
	if (y < 0) {
		y = 0;
		speedY *= -1;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY *= -1;
	}
	//z as boundary check
	//ofLog(OF_LOG_NOTICE, "z is" + z);
	if (z > 0) {
		z = 0;
		speedZ *= -1;
	}
	else if (z < zMax) {
		z = zMax;
		speedZ *= -1;
	}

	x += speedX;
	y += speedY;
	z += speedZ;
}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, z, radius);
}