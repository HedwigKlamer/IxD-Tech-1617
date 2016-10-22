#include "ofApp.h"


void ofApp::setup(){
	ofBackground(ofColor::magenta);
	
	video.load("bendershort.mp4");
	video.play();
	video.setLoopState(OF_LOOP_PALINDROME);
}


void ofApp::update(){
	video.update();
	rotate++;

}


void ofApp::draw(){
	ofSetColor(ofColor::red);
	ofRotateX(rotate);
	ofRotateY(rotate);
	video.draw(0, 0);

	ofSetColor(ofColor::blue);
	video.draw(400, 200);
}


void ofApp::keyPressed(int key){

}

