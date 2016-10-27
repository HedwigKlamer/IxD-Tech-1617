#include "ofApp.h"
#define PIN_RED 11
#define PIN_GREEN 10
#define PIN_BLUE 9


void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3", 57600);
	arduino.sendFirmwareVersionRequest(); \
	bSetupArduino = false;	// flag so we setup arduino when its ready
	
	check.setup();
	check.draw();
		red = 0;
		green = 0;
		blue = 0;
}

void ofApp::update() {
	arduino.update();
	check.tempCheck();
	//making the light fade in
	if (!(red >= 255) || red == check.redFade){
		if (red < check.redFade ) {
			red += 0.05;
			//ofLog() << "red  = " << red;
		}
	} 

	if (!(green >= 255) || green == check.greenFade) {
		if (green < check.greenFade) {
			green += 0.05;
			//ofLog() << "green  = " << green;
		} 
	}
	
	if (!(blue >= 255)||blue == check.blueFade ) {
		if (blue < check.blueFade) {
			blue += 0.05;
			//ofLog() << "blue = " << blue;
		}
	}	

	arduino.sendPwm(PIN_RED, red); //eerste parameter is de pin waar je waarde naartoe stuurt, tweede parameter is de waarde zelf
	arduino.sendPwm(PIN_GREEN, green);
	arduino.sendPwm(PIN_BLUE, blue);

}

void ofApp::draw(){
	ofBackground(0);
}

void ofApp::setupArduino(const int& version) {
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	// it is now safe to send commands to the Arduino
	bSetupArduino = true;
	// say what kind of output/input each pin has
	arduino.sendDigitalPinMode(PIN_RED, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_GREEN, ARD_PWM);
	arduino.sendDigitalPinMode(PIN_BLUE, ARD_PWM);


	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

void ofApp::keyPressed(int key) {
	//reset light to see the glow again
	if (key == 'r') {
		red = 0;
		green = 0;
		blue = 0;
	}
}


void ofApp::digitalPinChanged(const int& pinNum) {
	ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}
