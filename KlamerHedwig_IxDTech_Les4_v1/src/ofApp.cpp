#include "ofApp.h"
#define PIN_RED 11
#define PIN_GREEN 12
#define PIN_BLUE 13
#define PIN_POTMETER 1

void ofApp::setup() {
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	
	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();

	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 10, 200));
	gui.add(speedX.set("SpeedX", 5, 5, 30));
	gui.add(speedY.set("SpeedY", 5, 5, 30));
	gui.add(colour.set("Colour", ofColor::blue));
}

void ofApp::update() {
	arduino.update();
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
	
}

void ofApp::draw() {
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
	gui.draw();
}

void ofApp::keyPressed(int key) {
	//Ball newBall;
	//newBall.setup(speedX, speedY, radius, colour);
	//balls.push_back(newBall);
}

void ofApp::mousePressed(int x, int y, int button) {
	if (balls.size() > 0) {
		balls.pop_back();
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
	if (arduino.getDigital(pinNum) == 1) {
		Ball newBall;
		newBall.setup(speedX, speedY, radius, colour);
		balls.push_back(newBall);
	}
}

void ofApp::analogPinChanged(const int& pinNum) {
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
	radius = arduino.getAnalog(pinNum) / 2;
}
