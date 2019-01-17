#ifndef MONITOR_H
#define MONITOR_H
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <threads/threadpool.hpp>
#include <mainframe/threadpool.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <mainframe/rtmppub.h>
#include <rtmppublisher/MemoryPool.h>
#include <mainframe/aiengineerproc.h>
using namespace std;
using namespace boost;
using namespace cv;


namespace rock {
    class Monitor
    {
    public:
        Monitor(std::threadpool &tp,string name,string cam_uri,string desc,string publish_uri,bool cv_show,int fps,int videoType);
        bool init();
        bool start();
        bool stop();
        bool destroy();
        AIEngineerProc m_aiproc;

    private:
        string _name;
        string _camera_uri;
        string _publish_uri;
        string _desc;
        void static on_thread(Monitor * monitor);
        bool proc();
        bool _cvshow;
        void publish();

        int no;
        int max_waiting_ai_result_time;//
        int enable;
        int open_cam_retry_times;
        cv::VideoCapture vcap;
        int videoType;
        std::threadpool &executor;
        RTMPPub rtmpPublisher;
        MemoryPool pool;
        std::chrono::milliseconds mInterval;
        bool isFirstFrame;






    };

}


#endif // MONITOR_H
