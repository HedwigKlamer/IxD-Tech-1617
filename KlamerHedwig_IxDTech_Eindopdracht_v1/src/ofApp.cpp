#include "ofApp.h"


void ofApp::setup()
{
	std::string url = "http://api.openweathermap.org/data/2.5/weather?q=hilversum,nl&appid=37f584c9d170b496e7abe382b2237a5a";

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


void ofApp::draw()
{
	ofBackground(0);
	ofSetColor(255);

	for (Json::ArrayIndex i = 0; i < json.size(); ++i)
	{
		std::string weather = json["coord"][i]["weather"]["main"].asString();
		std::string author = json["base"]["stations"]["main"][i]["temp"].asString();
		//std::string date = json["response"]["docs"][i]["pub_date"].asString();
		//std::string text = title + " - " + author + " (" + date + ")";
		//ofDrawBitmapString(text, 20, i * 24 + 40);
	}
}
