#include "ofApp.h"
#include "breakOut.h"
#include "bullet.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("2D Brick Break Out Game 1");   //기본적인 실행창 설정
	ofSetWindowShape(1024, 768);
	ofSetFrameRate(40);
	ofBackground(ofColor::white);
	ofSetColor(ofColor::black);
	ofSetLineWidth(1);
	ofFill();

	initGame();
	//initBrick();
	initBullet();
}

//--------------------------------------------------------------
void ofApp::update(){
	moveBall();
	movePad();
	moveBullet();
}

//--------------------------------------------------------------
void ofApp::draw(){
	drawBrick();
	drawBall();
	drawPad();
	drawBullet();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	addBullet(mouseX, ofGetHeight() - 100);
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
