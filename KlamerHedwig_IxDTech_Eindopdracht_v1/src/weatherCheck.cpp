#include "weatherCheck.h"

/*I made a weatherclass to organize my code aso not everthing 
is on one page. This how I can find functions and variables 
easily*/


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
	weather = json["weather"][0]["main"].asString();//variable is now not used but is ready for future use
	//ofLog() << "temp = " << temp;
	//temp =13; //manually chance the temp var to check the light
}


void weatherCheck::tempCheck() {
	//checking how warm it is and deciding with color it should have
	if ( temp < 0) {   //setting the leds in bright blue if the temperature is less then zero degrees
		redFade = 200;
		greenFade = 255;
		blueFade = 255;
	}
	else if (temp >= 0 && temp < 10) {  // setting the leds in light blue if the temperature is between zero and ten degrees
		redFade = 20;
		greenFade = 50;
		blueFade = 100;
	}
	else if (temp >= 10 && temp < 15) {  // setting the leds in light green/yellow if the temperature is between ten and fifteen degrees
		redFade = 255;
		greenFade = 100;
		blueFade = 0;
	}
	else if (temp >= 15 && temp < 20) {  // setting the leds in warm yellow if the temperature is between fifteen and twenty degrees
		redFade = 200;
		greenFade = 50;
		blueFade = 0;
	}
	else if (temp >= 20 && temp < 30) {  // setting the leds in orange if the temperature is between twenty and twentyfive degrees
		redFade = 255;
		greenFade = 30;
		blueFade = 0;
	} 
	else if (temp >= 30 && temp < 40) { // setting the leds in red if the temperature is between twentyfive and thirty degrees
		redFade = 255;
		greenFade = 0;
		blueFade = 0;
	}
}