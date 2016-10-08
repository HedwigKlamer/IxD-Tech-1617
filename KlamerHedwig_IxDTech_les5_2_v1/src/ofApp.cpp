#include "ofApp.h"
#define PIN_BUTTON 11
#define PIN_POTMETER 1

void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
	
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
	arduino.update();
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

void ofApp::setupArduino(const int& version) {
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}
void ofApp::digitalPinChanged(const int& pinNum) {
	ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
	
}

void ofApp::analogPinChanged(const int& pinNum) {
	int value = arduino.getAnalog(pinNum);
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
	if (pinNum == PIN_POTMETER) {
		planet01.rotateSpeed = ofMap(value, 0, 1024, planet01.rotateSpeed.getMin(), planet01.rotateSpeed.getMax());
		//arduino.getAnalog(pinNum) / 10;
	}
}


