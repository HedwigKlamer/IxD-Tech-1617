#include "ofApp.h"
#define PIN_RED 11
#define PIN_GREEN 10
#define PIN_BLUE 9

void ofApp::setup()
{
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
}


void ofApp::update() {
	arduino.update();
	
	arduino.sendDigital(PIN_RED, 255);
	arduino.sendDigital(PIN_GREEN, 255);
	arduino.sendDigital(PIN_BLUE, 0);

}

void ofApp::draw()
{
	ofBackground(0);
}

void ofApp::setupArduino(const int& version) {
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_RED, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_GREEN, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BLUE, ARD_PWM);


	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

void ofApp::digitalPinChanged(const int& pinNum) {
	ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;

}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		arduino.disconnect();
	}
}

