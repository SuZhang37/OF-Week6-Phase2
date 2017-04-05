#include "ofApp.h"

vector<Line> lines;
//Line line;
ofFbo fbo;

Line::Line(){
    
}

void Line::setup(){
    loc = ofPoint(0,0,0);
    a= ofRandom(0,5);

    ofBackground(30,30,30);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(30,30,30, 0);
    fbo.end();
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));

}

void Line::update(){
    time = ofGetElapsedTimef()*a;
    rX = ofSignedNoise(time * 0.1)*200.0;
    rY = ofSignedNoise(time * 0.15)*200.0;
    rZ = ofSignedNoise(time*0.2)*200.0;
    dScaleX = 1 - ofNoise(time*0.2);
    dScaleY = 1-ofNoise(time*0.3);
    dScaleZ = 1 -ofNoise(time*0.4);
    vX = ofSignedNoise(time * 0.2)*ofRandom(5,10);
    vY = ofSignedNoise(time * 0.4)*ofRandom(5,10);
    vZ = ofSignedNoise(time * 0.6)*ofRandom(5,10);
    loc += ofPoint (vX,vY,vZ);
    //cout<< loc<< endl;
   
  
}

void Line::draw(){
    fbo.begin();
    ofSetColor(30,30,30,10);
    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
    
    
    ofPushMatrix();
    ofTranslate(loc.x,loc.y,loc.z);
    //ofTranslate(500,500);
    ofScale(dScaleX,dScaleY,dScaleZ);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofFill();
    ofSetColor(color);
    ofDrawLine(-50,400,50,500);
    ofPopMatrix();
    
    fbo.end();
    
    
    ofSetColor(255,255,255);
    fbo.draw(0,0);
}



//--------------------------------------------------------------
void ofApp::setup(){
    //line.setup();
    for(int i=0;i<5;i++){
        Line newline;
        newline.setup();
        lines.push_back(newline);
    }
    cout<< lines.size()<< endl;

}

//--------------------------------------------------------------
void ofApp::update(){
    //line.update();
    for(int i=0;i<5;i++){
        lines[i].update();
        
        if(lines[i].loc.x<0||lines[i].loc.x>ofGetWidth()||lines[i].loc.y<0||lines[i].loc.y>ofGetHeight()){
            lines.erase(lines.begin()+i);
            Line newline;
            newline.setup();
            newline.loc= ofPoint(ofRandom(ofGetWindowWidth()), ofRandom(ofGetHeight()),0);
            lines.push_back(newline);
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //line.draw();
    for(int i=0;i<5;i++){
        lines[i].draw();
    }

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
