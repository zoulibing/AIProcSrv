#ifndef RTMPPUB_H
#define RTMPPUB_H
#include <librtmp/rtmp.h>
#include <chrono>
#include <rtmppublisher/H264Encoder.h>
#include <rtmppublisher/H264RTMPPackager.h>
#include <rtmppublisher/AACEncoder.h>
#include <rtmppublisher/AACRTMPPackager.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <mp/MemoryPool.h>
#include <rtmppublisher/MemoryPool.h>
using namespace cv;
using namespace std;

namespace rock {
class RTMPPub
{
public:
    RTMPPub(MemoryPool &m_Pool,string rtmpur);
    ~RTMPPub();
    bool init();
    bool publish(cv::Mat im);
    bool connect(char *url);
private:
    RTMP *mRTMP;
    H264Encoder mEncoder;
    AACEncoder aac_mEncoder;
    RTMPPacket mMetadata;
    H264RTMPPackager packager;
    AACRTMPPackager  aac_packager;
    RTMPPacket getRtmpPacket(char *buf);
    char mDataBuf[256];
    std::pair<int, char*> result;
    std::pair<int, char*> aac_result;
    //MemoryPool mPool;
    string rtl;
    int metaDataSize;
    char * metaDataPlayload;
    MemoryPool &mPool;
    IMemoryPool* pool;



};

}


#endif // RTMPPUB_H
