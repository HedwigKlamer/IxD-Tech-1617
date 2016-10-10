#include "ofApp.h"


void ofApp::setup(){
	for (int i = 0; i < VOICES; ++i) {
		voicePlayer[i].load("voice"+ofToString(i+1)+".wav");
		voicePlayer[i].setLoop(true);
		voicePlayer[i].setPaused(true);
		voicePlayer[i].play();
	}
	ofSoundSetVolume(0.2);
}


void ofApp::update(){
	ofSoundUpdate();
}


void ofApp::draw(){

}


void ofApp::keyPressed(int key){
	if (key == '1') {
		if (voicePlayer[0].isPlaying()) {
			voicePlayer[0].setPaused(true);
		}
		else {
			voicePlayer[0].setPaused(false);
			//voicePlayer[0].play();
		}
	}else if (key == '2') {
		if (voicePlayer[1].isPlaying()) {
			voicePlayer[1].setPaused(true);
		}
		else {
			voicePlayer[1].setPaused(false);
			//voicePlayer[1].play();
		}
	}else if (key == '3') {
		if (voicePlayer[2].isPlaying()) {
			voicePlayer[2].setPaused(true);
		}
		else {
			voicePlayer[2].setPaused(false);
			//voicePlayer[2].play();
		}
	}else if (key == '4') {
		if (voicePlayer[3].isPlaying()) {
			voicePlayer[3].setPaused(true);
		}
		else {
			voicePlayer[3].setPaused(false);
			//voicePlayer[3].play();
		}
	}else if (key == '5') {
		if (voicePlayer[4].isPlaying()) {
			voicePlayer[4].setPaused(true);
		}
		else {
			voicePlayer[4].setPaused(false);
			//voicePlayer[4].play();
		}
	}
	else if (key == '6') {
		if (voicePlayer[5].isPlaying()) {
			voicePlayer[5].setPaused(true);
		}
		else {
			voicePlayer[5].setPaused(false);
			//voicePlayer[5].play();
		}
	}
}

