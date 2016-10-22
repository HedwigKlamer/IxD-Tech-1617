#include "ofApp.h"
#define PIN_RED 4
#define PIN_GREEN 3
#define PIN_BLUE 2
#define PIN_POTMETER 1

void ofApp::setup()
{
	/*ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();

	*/
	std::string url = "http://api.openweathermap.org/data/2.5/weather?q=hilversum,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";
	
	// Now parse the JSON
	bool parsingSuccessful = json.open(url);

	if (parsingSuccessful)
	{
		ofLogNotice("ofApp::setup") << json.getRawString(true);
	}
	else {
		ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
	}
}

void ofApp::update() {
	
}

void ofApp::draw()
{
	ofBackground(0);
	//ofSetColor(255);


	int temp = json["main"]["temp"].asInt();
	string weather = json["weather"][0]["main"].asString();

	
}

//void ofApp::setupArduino(const int& version) {
	
//}

//void ofApp::digitalPinChanged(const int& pinNum) {}
	

//void ofApp::analogPinChanged(const int& pinNum) {
//	ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
//
//}

/*void ofApp :: setColor(int red, int green, int blue){
	
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		arduino.disconnect();
	}
}*/