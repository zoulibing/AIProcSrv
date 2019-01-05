#include <mainframe/rtmppub.h>
#include <iostream>

using namespace std;
using namespace rock;



RTMPPub::RTMPPub(MemoryPool &m_Pool):mEncoder(640,480),mPool(m_Pool)
{

    mRTMP = RTMP_Alloc();
    RTMP_Init(mRTMP);

}

RTMPPub::~RTMPPub()
{
    if (mRTMP) {
        if (RTMP_IsConnected(mRTMP)) {
            RTMP_Close(mRTMP);
        }
        RTMP_Free(mRTMP);
    }
}

bool RTMPPub::init()
{
    std::chrono::milliseconds duration;
   // char *frame;
    //初始化x264encoder
    this->result = mEncoder.getMetadata();
    mMetadata = packager.metadata(mDataBuf, result.second, result.first);
    //mSource.getNextFrame(); // warm-up

}
bool RTMPPub::publish(cv::Mat im)
{

    //cv mat RGB->YUV I420
    //X264encoder
    Mat base;
    cv::resize(im,base,cv::Size(640,480));
    cv::Mat yuvMat;

    cv::cvtColor(base,yuvMat,CV_BGR2YUV_I420);

    //printf("im height=%d,width=%d ,size=%d, yuvMat size=%d \r",im.rows,im.cols,im.total(),yuvMat.total());
    //return true;


    if (!RTMP_IsConnected(mRTMP)) {
        std::cout << "can not connect to server" << std::endl;
        return false;
    }


    char *frame=(char*)yuvMat.data;
    //publish metadata
    result = mEncoder.encode(frame);
    if (H264RTMPPackager::isKeyFrame(result.second)) {
        //mQueue.push(mMetadata, true);
        if (!RTMP_SendPacket(mRTMP, &mMetadata, 1)) {
            std::cout << "fail to send packet" << std::endl;
            return false;
        }
    }



    char *buf = mPool.getChunk(packager.getBodyLength(result.first));
    RTMPPacket packet = packager.pack(buf, result.second, result.first);
    if (!RTMP_SendPacket(mRTMP, &packet, 1)) {
        std::cout << "fail to send packet" << std::endl;
        return false;
    }
//   // mQueue.push(packet);

//    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - last);

//    if (duration < mInterval) {
//        msleep((mInterval - duration).count());
//    }
//    last = std::chrono::system_clock::now();



    return true;
}

RTMPPacket RTMPPub::getRtmpPacket(char *buf)
{

}



bool RTMPPub::connect(char *url)
{
    if (!RTMP_SetupURL(mRTMP, url)) {
        return false;
    }

    RTMP_EnableWrite(mRTMP);

    if (!RTMP_Connect(mRTMP, NULL)) {
        return false;
    }

    if (!RTMP_ConnectStream(mRTMP, 0)) {
        RTMP_Close(mRTMP);
        return false;
    }

    return true;
}
