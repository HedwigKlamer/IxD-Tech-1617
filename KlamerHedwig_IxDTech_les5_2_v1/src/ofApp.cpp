#include "ofApp.h"


void ofApp::setup(){
	ofSetBackgroundColor(ofColor::black);

	planet01.setup("planet 1");
	params.add(planet01.planetParameterGroup);
	planet02.setup("planet 2");
	params.add(planet02.planetParameterGroup);
	

	gui.setup(params);

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::pink);
	light.enable();
}


void ofApp::update(){
	planet01.update();
	planet02.update();
}

void ofApp::draw(){
	gui.draw();
	ofEnableDepthTest();
	cam.begin();

	if (drawLight)light.draw();
	if (drawGrid) ofDrawGrid();

	planet01.draw();
	planet02.draw();

	cam.end();
	ofDisableDepthTest();
}

void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrid = !drawGrid;
	}else if (key == 'l') {
		drawLight = !drawLight;
	}else if (key == 'k') {
	
	}
}


