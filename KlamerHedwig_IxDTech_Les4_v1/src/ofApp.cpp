#include "ofApp.h"
#define PIN_BUTTON 11
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
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
	arduino.update();
}

void ofApp::draw() {
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
	gui.draw();
}

void ofApp::keyPressed(int key) {
	Ball newBall;
	newBall.setup(speedX, speedY, radius, colour);
	balls.push_back(newBall);
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
}

void ofApp::analogPinChanged(const int& pinNum) {
	/*
	if (pin == PIN_POTMETER) {
		radius = ofMap(value, 0, 1024, radius.getMin(), radius.getMax());
	}
	else if (pin = PIN_LDR) {
		ofLogVerbose() "hue" << colorHue << endl;
		ofColor newColour = ofColor(colour.get());
		newColour.setHue(colorHue);
		colour = newColour;
	}*/
	
	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}
