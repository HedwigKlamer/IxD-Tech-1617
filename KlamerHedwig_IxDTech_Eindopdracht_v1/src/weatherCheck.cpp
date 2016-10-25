#include "weatherCheck.h"

void weatherCheck::setup() {
									//JSON
	std::string url = "http://api.openweathermap.org/data/2.5/weather?q=hilversum,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

		// Now parse the JSON
	bool parsingSuccessful = json.open(url);

	if (parsingSuccessful){
		ofLogNotice("ofApp::setup") << json.getRawString(true);
	}
	else {
		ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
	}
}

void weatherCheck::draw(){
	temp = json["main"]["temp"].asInt();
	weather = json["weather"][0]["main"].asString();
}

void weatherCheck::tempCheck() {
	if (temp >= 0 && temp < 10) {
		redFade = 20;
		greenFade = 50;
		blueFade = 100;
	}
	
	if (temp >= 10 && temp < 20 ) {
		redFade = 255;
		greenFade = 50;
		blueFade = 0;
	}
}