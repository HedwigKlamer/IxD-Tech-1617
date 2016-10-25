#include "ofApp.h"
#define PIN_RED 11
#define PIN_GREEN 10
#define PIN_BLUE 9


void ofApp::setup()
{
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3", 57600);
	arduino.sendFirmwareVersionRequest(); \
	bSetupArduino = false;	// flag so we setup arduino when its ready

	/*
	//JSON
	std::string url = "http://api.openweathermap.org/data/2.5/weather?q=hilversum,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";
	
	// Now parse the JSON
	bool parsingSuccessful = json.open(url);

	if (parsingSuccessful)
	{
		ofLogNotice("ofApp::setup") << json.getRawString(true);
	}
	else {
		ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
	}*/
	red = 0;
	green = 0;
	blue = 0;

}

void ofApp::update() {
	arduino.update();
	check.tempCheck();
	//if (temp >= 10 && temp <= 20 &&){}
	//check.redFade = 255;
	//check.greenFade = 50;
	//check.blueFade = 0;

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
	//ofSetColor(255);
	//temp = json["main"]["temp"].asInt();
	//weather = json["weather"][0]["main"].asString();
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

void ofApp::keyPressed(int key) {
	
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