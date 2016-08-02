#include "ofApp.h"

using namespace ofxCv;

void ofApp::setup() {
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    cam.initGrabber(640, 480);
    frameCounter = 0;
    tracker.setup();
}


void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        if(frameCounter >= 15){
            tracker.update(toCv(cam));
            position = tracker.getPosition();
            scale = tracker.getScale();
            orientation = tracker.getOrientation();
            rotationMatrix = tracker.getRotationMatrix();
            send();
            frameCounter = 0;
        }
        frameCounter++;
    }
}


void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    ofDrawBitmapString(ofToString(orientation), 10, 20);
    if(tracker.getFound()) {
        ofSetLineWidth(1);
        tracker.draw();
    }
}



void ofApp::send() {
    
    std::ostringstream stringStream;
    stringStream << "http://pubsub.pubnub.com/publish/pub-c-b4a094ce-8ccb-4948-857a-14c36e779268/sub-c-feaea18a-4ce2-11e6-9236-02ee2ddab7fe/0/bizmo-2/0/";
    stringStream << "%22";
    stringStream << ofToString(orientation.x, 3, 4, '0');
    stringStream << "%20";
    stringStream << ofToString(orientation.y, 3, 4, '0');
    stringStream << "%20";
    stringStream << ofToString(orientation.z, 3, 4, '0');
    stringStream << "%22";
    
    std::string url = stringStream.str();
    
    ofx::HTTP::DefaultClient client;
    ofx::HTTP::Context context;
    
    ofx::HTTP::BaseResponse response;
    ofx::HTTP::GetRequest request(url, Poco::Net::HTTPMessage::HTTP_1_1);
    
    try
    {
        // Execute the request and get the response stream.
        std::istream& responseStream = client.execute(request,
                                                      response,
                                                      context);
        
        // Request and response headers can be examined here.
        
        // Copy the output to the terminal.
        Poco::StreamCopier::copyStream(responseStream, std::cout);
        
        // Flush the input stream.
        std::cout << std::endl;
        
    }
    catch (const Poco::Exception& exc)
    {
        ofLogError("ofApp::setup") << "Got Exception " << exc.displayText() << " " << exc.code();
    }
    catch (...)
    {
        ofLogError("ofApp::setup") << "Got unknown exception.";
    }
}

void ofApp::keyPressed(int key) {
    if(key == 'r') {
        tracker.reset();
    }
}