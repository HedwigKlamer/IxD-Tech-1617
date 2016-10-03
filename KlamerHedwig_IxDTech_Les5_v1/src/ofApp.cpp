#include "ofApp.h"

void ofApp::setup(){
	gui.setup();
	gui.add(rotateSpeedX.set("X", 0, 0, 9.0));
	gui.add(rotateSpeedY.set("Y", 0, 0, 9.0));
	gui.add(rotateSpeedZ.set("Z", 0, 0, 9.0));
}

void ofApp::update(){
	rotationX += rotateSpeedX;
	rotationY += rotateSpeedY;
	rotationZ += rotateSpeedZ;
}

void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);
	gui.draw();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofPushMatrix();
	ofRotateX(rotationX);
	//ofScale(rotationX, -300, 0);
	ofSetColor(ofColor::red);
	ofDrawRectangle(-430, -130, 260,260);
	ofPopMatrix();
	
	ofPushMatrix();
	ofRotateY(rotationY);
	ofSetColor(ofColor::blue);
	ofDrawCircle(0, 0, 130);
	ofPopMatrix();

	ofPushMatrix();
	ofRotateZ(rotationZ);
	ofSetColor(ofColor::yellow);
	ofDrawTriangle(195, 130, 455, 130, 325, -130);
	//ofDrawCircle(300, 0, 130);
	ofPopMatrix();

	ofDrawGrid(200);
}

void ofApp::keyPressed(int key){

}

