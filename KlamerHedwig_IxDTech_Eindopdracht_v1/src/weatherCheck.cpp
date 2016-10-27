#include "weatherCheck.h"

void weatherCheck::setup() {
		// Getting the weatherinfo from the internet
	std::string url = "http://api.openweathermap.org/data/2.5/weather?q=hilversum,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

		// printing the info we got from the link if we succeed
	bool parsingSuccessful = json.open(url);
	if (parsingSuccessful){
		ofLogNotice("weatherCheck::setup") << json.getRawString(true);
	}
	else {
		ofLogNotice("weatherCheck::setup") << "Failed to parse JSON.";
	}
}

void weatherCheck::draw(){
	//putting the online weather in variables
	temp = json["main"]["temp"].asInt();
	weather = json["weather"][0]["main"].asString();
	ofLog() << "temp MALLE MANNEN = " << temp;
}


void weatherCheck::tempCheck() {
	//checking how warm it is and deciding with color it should have
	if (temp >= 0 && temp < 10) {
		redFade = 20;
		greenFade = 50;
		blueFade = 100;
	}
	else if (temp >= 10 && temp < 20) {
		redFade = 255;
		greenFade = 50;
		blueFade = 0;
	}
	else if (temp >= 20 && temp < 30) {
		redFade = 255;
		greenFade = 30;
		blueFade = 0;
	} 
	else if (temp >= 30 && temp < 40) { 
		redFade = 255;
		greenFade = 0;
		blueFade = 0;
	}
}