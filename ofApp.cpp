#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("20170611");

	ofColor c;
	for (int i = 0; i < 4098; i++) {
		this->points.push_back(ofVec3f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-256, 256)));
		c.setHsb(ofRandom(255), 255, 255);
		this->colors.push_back(c);
	}

	ofSetLineWidth(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	this->cam.begin();

	vector<ofVec3f> target_points;

	Leap::Frame frame = leap.frame();
	for (Leap::Hand hand : frame.hands()) {
		for (Leap::Finger finger : hand.fingers()) {
			//target_points.push_back(ofVec3f(finger.tipPosition().x, finger.tipPosition().y - ofGetHeight() / 2, finger.tipPosition(). z));
			target_points.push_back(ofVec3f(finger.tipPosition().x + finger.direction().x * finger.length(),
				(finger.tipPosition().y - ofGetHeight() / 2) + finger.direction().y * finger.length() * 4,
				finger.tipPosition().z + finger.direction().z * finger.length() * 4));
		}
	}

	for (int i = 0; i < this->points.size(); i++) {
		ofSetColor(this->colors[i]);
		ofEllipse(this->points[i], 2, 2);

		for (int j = 0; j < target_points.size(); j++) {
			float dist = target_points[j].distance(this->points[i]);
			if (dist < 255) {
				ofSetColor(this->colors[i], 255 - dist);
				ofLine(this->points[i], target_points[j]);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
