#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
private:
    ofFbo _fbo;
    ofTrueTypeFont _font;
    ofxPanel _gui;
    ofxIntSlider _mh;
    ofxIntSlider _mv;
    ofxFloatSlider _inflate;
    ofxIntSlider _frame;
    ofxIntSlider _offset;
    ofxFloatSlider _rotate;
    ofxFloatSlider _step;
    ofxIntSlider _alpha;
    ofxToggle _flip;
    ofxButton _save;
    
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
private:
    static string replaceHolder(string const& param);
    static ofRectangle inflateBox(ofRectangle const& param, float inflate);
    static ofColor rhythmToColor(char const* rhythm);
};
