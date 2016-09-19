#include "ofApp.h"
#include "Ball.h"

Ball ball;

void ofApp::setup() {
	gui.setup("instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(speedX.set("SnelheidX", 5, 0, 20));
	gui.add(speedY.set("SnelheidY", 5, 0, 20));
}

void ofApp::update() {
	ball.update();
	if (ball.radius != radius) {
		ball.radius = radius;
	}
	/*if (ball.speedX != speedX) {
		ball.speedX = speedX;
	}*/
}

void ofApp::draw() {
	ball.draw();
	gui.draw();
}
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		ball.setup(ofRandom(ofGetWidth()),
			ofRandom(ofGetHeight()),
			radius, speedX, speedY);
	}
}