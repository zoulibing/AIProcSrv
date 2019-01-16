#include <iostream>
#include <mainframe/mainframe.h>
#include <mainframe/monitor.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <X11/Xlib.h>

using namespace std;
using namespace cv;
using namespace std;
using namespace rock;
using namespace boost;


int testMonitor();
int main()
{
 XInitThreads();

    // Create sgd optimizer
 std::cout<<"xxx"<<std::endl;
 MainFrame mf;
 //mf.test();

 mf.init();
 mf.start();
 while(getchar()!='e')
 {
     usleep(1 * 1000);
 }
 std::cout<<"exit..++++++++++++.."<<std::endl;


 //testMonitor();


 return 0;
}

int testMonitor()
{


    //读取视频或摄像头
    VideoCapture capture;
    capture.open("rtmp://live.hkstv.hk.lxdns.com/live/hks1");

    while (true)
    {
        Mat frame;
        capture >> frame;

        imshow("读取视频", frame);
        waitKey(30);	//延时30
    }

}
