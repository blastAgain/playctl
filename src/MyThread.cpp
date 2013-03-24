//
    #include "testApp.h"

    //--------------------------------------------------------------
    void MyThread::start(testApp* p, bool bl, bool logging)
    {

        // Get parent app
        app = p;

        // Start thread -- blocking, venbose
        startThread(bl, logging);

    }

    //--------------------------------------------------------------
    void MyThread::stop()
    {

        // Stop thread
        stopThread();

    }

    //--------------------------------------------------------------
    void MyThread::threadedFunction()
    {
        // Thread is running
        while (isThreadRunning() != 0){

            while(cpos<epos){


                d = ctlcmd[cpos];
                char c = d.at(0);
                ofLog(OF_LOG_ERROR,"current cmd " + ofToString(cpos) + ": "+d);

                switch(c){
                    case 'I'://Loop in point
                        looppos =cpos;
                        loopcount = ofToInt(d.substr(5));
                        ofLog(OF_LOG_ERROR,"current cmd position: " + ofToString(cpos) + " loop count: "+ ofToString(loopcount));
                        break;

                    case 'O'://Loop out point
                        loopcount--;
                        if(loopcount > 0){
                            cpos=looppos;
                        }
                        else looppos=0;

                        ofLog(OF_LOG_ERROR,"current cmd position: " + ofToString(cpos) + " outloop count: "+ ofToString(loopcount));

                        break;

                    case 'W'://Wait for msec

                        w = ofToInt(d.substr(5));
                        ofLog(OF_LOG_ERROR,"Wait time: "+ ofToString(w));
                        sleep(w);

                        break;

                    case 'F'://forward play

                    case 'p'://PAUSE

                    case 'A'://Pause at frame

                    case 'E':

                    case 'S'://start frame

                    case 'L'://Fullscreen

                        sendCmdAll((char *)d.c_str());
                        break;

                }
                cpos++;
                sleep(100);

            }
            app->closeUDP();
            exit(0);

        }

    }


//--------------------------------------------------------------

    void MyThread::sendCmdAll( char* ds ){

    if(!connection.SendAll( ds, (int)strlen(ds)))
        ofLog(OF_LOG_ERROR,"sendCmdAll: "+ ofToString(ds)+" failed");
    else
        ofLog(OF_LOG_ERROR,"sendCmdAll: "+ ofToString(ds)+" success");


}

