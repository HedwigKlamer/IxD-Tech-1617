#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("Instellingen", "setting.xml");
	gui.add(count.set("Count", 50, 0, 200));
	gui.add(speedX.set("SpeedX", 20, 0, 200));
	gui.add(speedY.set("SpeedY", 20, 0, 200));

}

//--------------------------------------------------------------
void ofApp::update(){
	//ball = Ball(speedX, speedY);  voorbeeld hoe je deze parameter zou uitspreken
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


