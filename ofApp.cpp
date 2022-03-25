#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetCircleResolution(100);

	this->resolution = 100;
	int size = 20;

	for (int i = 0; i <= this->resolution * size; i += this->resolution) {
		for (int j = 0; j <= this->resolution * size; j += this->resolution) {
			positions_vector.push_back(glm::vec3(i, j, 0) - glm::vec3(this->resolution * size/2, this->resolution * size/2, 0));
			float x = (float)i;
			float y = (float)j;
			floats_vector.push_back(glm::vec3(x, y, 0));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();

	ofRotateZ(ofGetFrameNum()*.2 );

	for (int i = 0; i < positions_vector.size(); i++) {
		
		auto noise = ofNoise(floats_vector[i].x/1000, floats_vector[i].y/1000, ofGetFrameNum() * .009);

		auto color = ofColor();
		color.setHsb(ofMap(i,0,positions_vector.size(),160,230), 180, 220);
		ofSetColor(color);
		
		if (noise > .3) {
			ofDrawRectangle(positions_vector[i], resolution * .75, resolution * .75);
		}
		else {
			color.setHsb(ofMap(i, 0, positions_vector.size(), 100, 150), 180, 220);
			ofSetColor(color);
			ofDrawRectangle((positions_vector[i] + glm::vec3(0, 0, ofMap(noise, 0, 1, 0, 300))) , resolution * .75, resolution * .75);
		}
	}
	cam.end();

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
