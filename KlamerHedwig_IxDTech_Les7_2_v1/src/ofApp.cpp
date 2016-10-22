#include "ofApp.h"


void ofApp::setup(){
	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
	grabber.setDesiredFrameRate(30);

	ofSetBackgroundColor(ofColor::magenta);

	workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}


void ofApp::update(){
	grabber.update();
	//rotate += 40;

	if (grabber.isFrameNew()) {
		ofPixels pixels = grabber.getPixels();
		for (int y = 0; y < pixels.getHeight(); y++) {
			for (int x = 0; x < pixels.getWidth()/2; x++) {
			//for (int x = 0; x < pixels.getWidth(); x++) {
				ofColor col = pixels.getColor(x, y);
				//col.r = 255 - (col.r);
				//col.g = 255 - (col.g);
				//col.b = 255 - (col.b);

				workspace.setColor(x, y, col);
				workspace.setColor(pixels.getWidth() - x, y, col);
			}
		}
		image.setFromPixels(workspace);
		image.mirror(false, true);
	}
}


void ofApp::draw(){
	//ofSetColor(ofColor::red);
	//ofRotateX(rotate);
	grabber.draw(0, 0);
	image.draw(400, 0);
}


void ofApp::keyPressed(int key){

}
