#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxHTTP.h"

using namespace ofxCv;
using namespace cv;


#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void send();
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    ofVec2f position;
    float scale;
    ofVec3f orientation;
    ofMatrix4x4 rotationMatrix;
    Mat translation, rotation;
    ofMatrix4x4 pose;
    
    int frameCounter;
    
    
    
};
