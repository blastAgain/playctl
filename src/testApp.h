#pragma once

#include "ofMain.h"
//#include "ofxBezierWarp.h"

#include "ofxNetwork.h"
#include "ofxNetworkUtils.h"
//#include "ofxUDPManager.h"

#define TARGET_WIN32

// this h file has the definition for an object that uses the threaded addon:
#include "MyThread.h"


class testApp : public ofBaseApp{

	public:
	    testApp( char *fn);
		void setup();
//		void update();
//		void draw();

		void udpsetup();
		void sendCmdAll(char * dString);
        void closeUDP();

//		void keyPressed  (int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
		void exit();

		void keyPressed  (int key, bool inner);


//	ofxBezierWarp bz;
//	ofVideoPlayer myMovie;
//	int grid;
	char playctlfilename[255];
//	int endframe;
//	bool fullscreen=true;
//	bool memo=false;
//	ofxUDPManager udpconnection;
	ofxUDPManager udpconnection_s;
    Byte buf[100];

    vector <string> ctlcmd;

    MyThread ctlthread;

};
