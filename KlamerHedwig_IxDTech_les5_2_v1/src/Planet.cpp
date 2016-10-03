#include "Planet.h"
Planet::Planet() {
	rotation = 0.0;
}
Planet::~Planet() {

}

void Planet::setup(string name) {
	planetParameterGroup.setName(name);
	planetParameterGroup.add(rotateSpeed.set("speed", 0.0, 0.0, 9.0));
	planetParameterGroup.add(distance.set("distance", 0, 0, 600));
	planetParameterGroup.add(colour.set("colour", ofColor::grey));

}

void Planet::update() {
	rotation++;
}

void Planet::draw() {
	ofSetColor(colour);
	ofRotate(rotation*rotateSpeed);
	ofDrawSphere(distance, 0, 0, 30);
}