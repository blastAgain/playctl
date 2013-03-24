


#include "ofMain.h"
#include "ofThread.h"

    class testApp;

    class MyThread : public ofThread{

    public:
        void sendCmdAll(char *d);

        // Methods
        void start(testApp* p, bool bl, bool logging);
        void stop();
        void threadedFunction();

        // Parent application
        testApp* app;
        ofxUDPManager connection;

        vector <string> ctlcmd;

        int cpos=0;  //current cmd position
        int looppos=0;// loopback cmd position
        int loopcount=0;// loop count
        int epos;//cmd end position

        int w=0; //Wait cmd msec

        std::string d;

        int wait=2;

    };


