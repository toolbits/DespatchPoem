#include "ofApp.h"

#define lengthof(param)     (sizeof(param) / sizeof(param[0]))
#define MULTIPLY            (10.0)

struct TableRec {
    char type;
    char const* content[2];
    int font[2];
    int box[2];
};

static TableRec const g_table[] = {
    {'d', "####", "ROSE", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE4007F},
    {'r', "LENG", "BIMN"},
    {'d', "####", "BLCK", 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000},
    {'r', "IOLA", "ITAL"},
    {'n', "ARTSAT2", ""},
    {'n', "DESPATCH", ""},
    {'c', "JQ1ZNN", ""},
    {'d', "####", "BLCK", 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000},
    {'d', "####", "ROSE", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE4007F},
    {'r', "LITA", "LENG"},
    {'r', "HOGE", "KATA"},
    {'c', "JQ1ZNN", ""},
    {'c', "JQ1ZNN", ""},
    {'d', "####", "ROSE", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE4007F},
    {'r', "LAUL", "LAUL"},
    {'d', "####", "BLCK", 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000},
    {'r', "IMBA", "LOOO"},
    {'r', "OAOL", "AHN_"},
    {'n', "ARTSAT2", ""},
    {'n', "DESPATCH", ""},
    {'n', "ARTSAT2", ""},
    {'n', "DESPATCH", ""},
    {'c', "JQ1ZNN", ""},
    {'s', "********", ""},
    {'d', "####", "BLCK", 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000},
    {'d', "####", "ROSE", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE4007F},
    {'s', "********", ""},
    {'d', "____", "####", 0x000000, 0x000000, 0xFFFFFF, 0xFFFFFF},
    {'d', "####", "CERS", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE5004F},
    {'r', "LITA", "LONG"},
    {'r', "MBAL", "BERI"},
    {'n', "ARTSAT2", ""},
    {'n', "DESPATCH", ""},
    {'c', "JQ1ZNN", ""},
    {'s', "********", ""},
    {'d', "####", "BLCK", 0x000000, 0xFFFFFF, 0xFFFFFF, 0x000000},
    {'d', "__AA", "ROSE", 0x000000, 0xFFFFFF, 0xFFFFFF, 0xE4007F},
    {'r', "HOPS", "IOLA"},
    {'r', "LOMI", "BERI"},
    {'n', "ARTSA__", ""},
    {'d', "####", "####", 0x000000, 0x000000, 0xFFFFFF, 0xFFFFFF},
    {'d', "####", "___E", 0x000000, 0x000000, 0xFFFFFF, 0xFFFFFF},
    {'r', "ITAL", "____"},
    {'r', "__N_", "B__B"},
    {'n', "A___A__", ""}
};

static char const* const g_rhythm[] = {
    "ABIM",
    "ADJI",
    "AFFA",
    "ALLA",
    "AMAI",
    "AMEN",
    "AMMA",
    "ASSA",
    "AULA",
    "AULI",
    "BALA",
    "BALO",
    "BAND",
    "BANG",
    "BANN",
    "BERI",
    "BIMB",
    "BIMM",
    "BINB",
    "BINN",
    "BLAS",
    "BLAU",
    "BLON",
    "BLUK",
    "BLUN",
    "BRUS",
    "BULO",
    "BUMB",
    "CADO",
    "DIBL",
    "DIBU",
    "DIDI",
    "DIGA",
    "DORI",
    "DRID",
    "ELIF",
    "FALO",
    "FANT",
    "GADJ",
    "GADO",
    "GAGA",
    "GALA",
    "GLAN",
    "GLAS",
    "GLIG",
    "GOOO",
    "GRAM",
    "HOGE",
    "HOOO",
    "HOPS",
    "IBAR",
    "IGLA",
    "IMAI",
    "IMBA",
    "IMZI",
    "INAI",
    "IOLA",
    "ITAL",
    "IZIM",
    "JAMA",
    "JAME",
    "KATA",
    "LALA",
    "LAUL",
    "LAXA",
    "LENG",
    "LIMA",
    "LING",
    "LITA",
    "LLAL",
    "LOMI",
    "LONG",
    "LONN",
    "LOOO",
    "LOPI",
    "LUJI",
    "LUKU",
    "LUNG",
    "MALO",
    "MBAL",
    "MBRA",
    "MINI",
    "MZIM",
    "NBAN",
    "NDRI",
    "NEGR",
    "NOZE",
    "OGRO",
    "OLIM",
    "OMEN",
    "OMIN",
    "ONNI",
    "OOOO",
    "ORSU",
    "OSSO",
    "OZER",
    "PALO",
    "PALU",
    "PIMP",
    "PINX",
    "PIYO",
    "PURZ",
    "RABI",
    "RHIN",
    "RIDA",
    "RIDI",
    "ROSS",
    "SALA",
    "SASS",
    "SOLA",
    "SSAS",
    "TATA",
    "TERU",
    "TORR",
    "TROM",
    "TUFF",
    "UFFM",
    "URUL",
    "VELO",
    "VIOL",
    "WOWO",
    "XATO",
    "ZALL",
    "ZAMM",
    "ZANZ",
    "ZIMB",
    "ZIMZ",
    "ZING"
};

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofBackground(0, 0, 0);
    
    _fbo.allocate(ofGetWidth() * MULTIPLY, ofGetHeight() * MULTIPLY, GL_RGBA, 4);
    _font.loadFont("Menlo.ttc", 9 * MULTIPLY, true, true, true, 0);
    _gui.setup();
    _gui.add(_mh.setup("H margin", 82, 0, 500));
    _gui.add(_mv.setup("V margin", 51, 0, 100));
    _gui.add(_inflate.setup("Inflation", 21.5, 0.0, 100.0));
    _gui.add(_frame.setup("Frame", 8, 0, 20));
    _gui.add(_offset.setup("Offset", 127, 0, 500));
    _gui.add(_rotate.setup("Rotation", -140.4, -180.0, 180.0));
    _gui.add(_step.setup("Step", -9.45, -45.0, 45.0));
    _gui.add(_alpha.setup("Alpha", 235, 0, 255));
    _gui.add(_flip.setup("Flip", false));
    _gui.add(_save.setup("Save"));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofRectangle box;
    ofImage image;
    int i;
    
    _fbo.begin();
    ofClear(0, 0, 0, 0);
    ofPushMatrix();
    if (_flip) {
        ofTranslate(_fbo.getWidth() / 2, _fbo.getHeight() / 2);
        ofRotateZ(180);
        ofTranslate(-_fbo.getWidth() / 2, -_fbo.getHeight() / 2);
    }
    ofTranslate(_fbo.getWidth() / 2, _font.getLineHeight() + _offset);
    ofRotateY(_rotate);
    for (i = lengthof(g_table) - 1; i >= 0; --i) {
        box = _font.getStringBoundingBox(replaceHolder(g_table[i].content[0]), 0, 0);
        switch (g_table[i].type) {
            case 'd':
                ofPushMatrix();
                ofTranslate(-(box.width + _mh), 0);
                ofSetHexColor(g_table[i].box[0]);
                ofRect(inflateBox(box, _inflate));
                if (g_table[i].box[0] == 0x000000) {
                    ofPushStyle();
                    ofSetHexColor(g_table[i].font[0]);
                    ofNoFill();
                    ofSetLineWidth(_frame);
                    ofRect(inflateBox(box, _inflate));
                    ofPopStyle();
                }
                ofSetHexColor(g_table[i].font[0]);
                _font.drawStringAsShapes(g_table[i].content[0], 0, 0);
                ofPopMatrix();
                box = _font.getStringBoundingBox(replaceHolder(g_table[i].content[1]), 0, 0);
                ofPushMatrix();
                ofTranslate(_mh, 0);
                ofSetHexColor(g_table[i].box[1]);
                ofRect(inflateBox(box, _inflate));
                if (g_table[i].box[1] == 0x000000) {
                    ofPushStyle();
                    ofSetHexColor(g_table[i].font[1]);
                    ofNoFill();
                    ofSetLineWidth(_frame);
                    ofRect(inflateBox(box, _inflate));
                    ofPopStyle();
                }
                ofSetHexColor(g_table[i].font[1]);
                _font.drawStringAsShapes(g_table[i].content[1], 0, 0);
                ofPopMatrix();
                break;
            case 'r':
                ofPushMatrix();
                ofTranslate(-(box.width + _mh), 0);
                ofSetColor(rhythmToColor(g_table[i].content[0]));
                _font.drawStringAsShapes(g_table[i].content[0], 0, 0);
                ofPopMatrix();
                ofPushMatrix();
                ofTranslate(_mh, 0);
                ofSetColor(rhythmToColor(g_table[i].content[1]));
                _font.drawStringAsShapes(g_table[i].content[1], 0, 0);
                ofPopMatrix();
                break;
            case 'n':
            case 'c':
            case 's':
                ofSetColor(255, 255, 255, _alpha);
                _font.drawStringAsShapes(g_table[i].content[0], -box.width / 2, 0);
                break;
        }
        ofTranslate(0, _font.getLineHeight() + _mv);
        ofRotateY(_step);
    }
    ofPopMatrix();
    _fbo.end();
    if (_save) {
        image.allocate(_fbo.getWidth(), _fbo.getHeight(), OF_IMAGE_COLOR_ALPHA);
        _fbo.readToPixels(image.getPixelsRef());
        image.saveImage("screen.png");
    }
    ofSetColor(255, 255, 255);
    _fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    _gui.draw();
}

string ofApp::replaceHolder(string const& param)
{
    int i;
    string result(param);
    
    for (i = 0; i < result.size(); ++i) {
        result[i] = '/';
    }
    return result;
}

ofRectangle ofApp::inflateBox(ofRectangle const& param, float inflate)
{
    ofRectangle result(param);
    
    result.x -= inflate;
    result.width += inflate * 2;
    result.y -= inflate;
    result.height += inflate * 2;
    return result;
}

ofColor ofApp::rhythmToColor(char const* rhythm)
{
    int i;
    ofColor result(ofColor::white);
    
    for (i = 0; i < lengthof(g_rhythm); ++i) {
        if (strcmp(g_rhythm[i], rhythm) == 0) {
            result.setHsb(ofMap(i, 0, lengthof(g_rhythm) - 1, 0.75, 0.0) * ofColor::limit(), 0.8 * ofColor::limit(), ofColor::limit());
            break;
        }
    }
    return result;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
