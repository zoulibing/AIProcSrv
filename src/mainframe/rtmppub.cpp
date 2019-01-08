#include <mainframe/rtmppub.h>
#include <iostream>
#include <boost/pool/pool.hpp>


using namespace std;
using namespace rock;



RTMPPub::RTMPPub(MemoryPool &m_Pool,string rtmpurl):rtl(rtmpurl),
    mEncoder(640,480),metaDataSize(0),metaDataPlayload(NULL)
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
    result = mEncoder.getMetadata();
    mMetadata = packager.metadata(mDataBuf, result.second, result.first);
    //mSource.getNextFrame(); // warm-up

}
bool RTMPPub::publish(cv::Mat im)
{

    //std::cout << "rtmp="<<rtl<< std::endl;
    if (!RTMP_IsConnected(mRTMP)) {
        std::cout << "can not connect to server===" <<rtl<< std::endl;
        return false;
    }
    //std::cout << "rtmpxxxx"<< std::endl;

    //return true;
    Mat base,yuvMat;
    cv::resize(im,base,cv::Size(640,480));
    cv::cvtColor(base,yuvMat,CV_BGR2YUV_I420);
    if(yuvMat.empty())
        return false;
    char *frame=(char*)yuvMat.data;
    //std::cout << "rtmpxxxx"<< std::endl;

    //publish metadata
    result = mEncoder.encode(frame);

    if (H264RTMPPackager::isKeyFrame(result.second)) {
        //mQueue.push(mMetadata, true);
        mMetadata.m_nInfoField2 = mRTMP->m_stream_id;
        mMetadata.m_nTimeStamp = RTMP_GetTime();
        if (!RTMP_SendPacket(mRTMP, &mMetadata, 1)) {
            std::cout << "fail to send packet" << std::endl;
            return false;
        }
    }




    char *buf = mPool.getChunk(packager.getBodyLength(result.first));
    RTMPPacket packet = packager.pack(buf, result.second, result.first);
    packet.m_nInfoField2 = mRTMP->m_stream_id;
    packet.m_nTimeStamp = RTMP_GetTime();
    if (!RTMP_SendPacket(mRTMP, &packet, 1)) {
        std::cout << "fail to send packet" << std::endl;
        return false;
    }

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
    if (!RTMP_IsConnected(mRTMP))
        return false;

    return true;
}
