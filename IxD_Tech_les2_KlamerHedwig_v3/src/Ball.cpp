#include "ball.h"

void ball::setup() {

	radius = ofRandom(20, 5);
	//position = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	position = ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	//color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void ball::update(int SpeedX, int SpeedY) {
	speed = ofVec2f(SpeedX, SpeedY);
	if (position.x <= 0) {
		position.x = 0;
		speed.x = -speed.x;
	}
	else if (position.x >= ofGetWidth()) {
		position.x = ofGetWidth();
		speed.x = -speed.x;
	}

	if (position.y <= 0) {
		position.y = 0;
		speed.y = -speed.y;
	}
	else if (position.y >= ofGetHeight()) {
		position.y = ofGetHeight();
		speed.y = -speed.y;
	}

	position.x += speed.x;
	position.y += speed.y;

}

void ball::draw(ofColor Color) {
	ofSetColor(Color);
	ofDrawCircle(position, radius);
	//for (int i = 0; i < NumberBall; i++) {
	//	ofDrawCircle(x[i], y[i], radius);
	//}
}
