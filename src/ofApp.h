#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

class Line{
public:
    Line();
    void setup();
    void update();
    void draw();
    ofColor color;
    ofPoint loc;
    
private:
    float time;
    float a=0;
    float rX =0;
    float rY =0;
    float rZ =0;
    float dScaleX =1;
    float dScaleY =1;
    float dScaleZ =1;
    float vX;
    float vY;
    float vZ;
};
