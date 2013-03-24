#include "testApp.h"




//--------------------------------------------------------------
testApp::testApp(char fname[]){

    if(fname[0]!=NULL)strncpy(playctlfilename,fname,250);
    else strncpy(playctlfilename,"playctl.txt",11);

    udpsetup();

    ctlthread.app = this;
    ctlthread.ctlcmd = ctlcmd;


}
void testApp::udpsetup(){

    //sending socket
    if(!udpconnection_s.Create()){
        ofLog(OF_LOG_ERROR,"Socket create failed");
        exit();
    }
    ofLog(OF_LOG_ERROR,"Socket create success");

    if(!udpconnection_s.ConnectMcast("230.0.0.1",4446)){
        ofLog(OF_LOG_ERROR,"Socket ConnectMcast failed");
        udpconnection_s.Close();
        exit();
    }
    ofLog(OF_LOG_ERROR,"Socket ConnectMcast success");

    ctlthread.connection= udpconnection_s;
}




void testApp::closeUDP(){

    if(udpconnection_s.Close())
        ofLog(OF_LOG_ERROR,"Sending Socket closed");
    else
        ofLog(OF_LOG_ERROR,"Sending Socket close fail");


}void testApp::exit(){

    ctlthread.stopThread();

}
//--------------------------------------------------------------


//--------------------------------------------------------------
void testApp::setup(){
    ofBuffer buffer = ofBufferFromFile(playctlfilename, false);

    if(buffer.size()) {

        // we now keep grabbing the next line
        // until we reach the end of the file
        while(buffer.isLastLine() == false) {

            // move on to the next line
            string line = buffer.getNextLine();

            // copy the line to draw later
            // make sure its not a empty line
            if(line.empty() == false) {
                ctlcmd.push_back(line);
            }

            // print out the line
            cout << line << endl;

        }

        ctlthread.epos=(int)ctlcmd.size();
        ctlthread.ctlcmd = ctlcmd;

    }
    else {
        ofLog(OF_LOG_ERROR,"control play file read error");
        exit();
    }

    ctlthread.startThread(false,false);

}
/*
//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){


}


//--------------------------------------------------------------

void testApp::keyPressed(int key){


}




//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
*/
