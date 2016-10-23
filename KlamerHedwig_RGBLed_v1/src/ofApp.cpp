#include "ofApp.h"
#define PIN_RED 11
#define PIN_GREEN 10
#define PIN_BLUE 9

void ofApp::setup()
{
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3", 57600);
	arduino.sendFirmwareVersionRequest();\
	bSetupArduino = false;	// flag so we setup arduino when its ready
}


void ofApp::update() {
	arduino.update();
	
	//arduino.sendDigital(PIN_RED, 255);
	//arduino.sendDigital(PIN_GREEN, 255);
	//arduino.sendDigital(PIN_BLUE, 0);

}

void ofApp::draw(){
	ofBackground(0);
}

void ofApp::setupArduino(const int& version) {
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	// it is now safe to send commands to the Arduino
	bSetupArduino = true;

	arduino.sendDigitalPinMode(PIN_RED, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_GREEN, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BLUE, ARD_PWM);


	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

void ofApp::updateArduino() {
	// do not send anything until the arduino has been set up
	if (bSetupArduino) {
		arduino.sendPwm(PIN_RED, 255);
		arduino.sendPwm(PIN_BLUE, 0);
		arduino.sendPwm(PIN_GREEN,255);
	}
}

void ofApp::digitalPinChanged(const int& pinNum) {
	ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;

}

