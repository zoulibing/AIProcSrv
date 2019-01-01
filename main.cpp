#include <iostream>
#include <mainframe/mainframe.h>
#include <mainframe/monitor.h>
#include <unistd.h>

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
using namespace std;
using namespace rock;
using namespace boost;


int testMonitor();
int main()
{
    // Create sgd optimizer
 cout<<""<<endl;
 //MainFrame mf;
 //mf.test();
 testMonitor();


 return 0;
}

int testMonitor()
{


    //读取视频或摄像头
    VideoCapture capture(0);

    while (true)
    {
        Mat frame;
        capture >> frame;

        imshow("读取视频", frame);
        waitKey(30);	//延时30
    }

}
