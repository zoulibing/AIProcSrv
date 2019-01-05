#ifndef RTMPPUB_H
#define RTMPPUB_H
#include <librtmp/rtmp.h>
#include <chrono>
#include <rtmppublisher/H264Encoder.h>
#include <rtmppublisher/H264RTMPPackager.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <rtmppublisher/MemoryPool.h>
using namespace cv;
using namespace std;

namespace rock {
class RTMPPub
{
public:
    RTMPPub(MemoryPool &m_Pool);
    ~RTMPPub();
    bool init();
    bool publish(cv::Mat im);
    bool connect(char *url);
private:
    RTMP *mRTMP;
    H264Encoder mEncoder;
    RTMPPacket mMetadata;
    H264RTMPPackager packager;
    RTMPPacket getRtmpPacket(char *buf);
    char mDataBuf[256];
    std::pair<int, char*> result;
    MemoryPool &mPool;


};

}


#endif // RTMPPUB_H
