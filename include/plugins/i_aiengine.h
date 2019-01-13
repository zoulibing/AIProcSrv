#ifndef I_AIENGINE
#define I_AIENGINE
#include <opencv2/opencv.hpp>
using namespace cv;
class IAIEngine
{
    virtual bool init()=0;
    virtual bool proc(Mat im)=0;
    virtual bool close()=0;
    virtual bool setStatus()=0;
    virtual bool setTask()=0;

}

#endif // I_AIENGINE

