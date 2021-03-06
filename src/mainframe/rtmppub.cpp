#include <mainframe/rtmppub.h>
#include <iostream>
#include <boost/pool/pool.hpp>
//#include <mp/MemoryPool.h>


using namespace std;
using namespace rock;



RTMPPub::RTMPPub(MemoryPool &m_Pool,string rtmpurl):rtl(rtmpurl),mPool(m_Pool),
    mEncoder(640,480),metaDataSize(0),metaDataPlayload(NULL),pool(NULL),
    aac_mEncoder(44100, 16, 48000)
{
    pool=new IMemoryPool();
    pool->report();

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
    if(pool)
       delete pool;
}

bool RTMPPub::init()
{

   // char *frame;
    //初始化x264encoder
    result = mEncoder.getMetadata();
    memset(mDataBuf,0,sizeof(mDataBuf));
    mMetadata = packager.metadata(mDataBuf, result.second, result.first);
    //mSource.getNextFrame(); // warm-up

}
bool RTMPPub::publish(cv::Mat im)
{

     if (!RTMP_IsConnected(mRTMP)) {
        std::cout << "can not connect to server===" <<rtl<< std::endl;
        return false;
    }

    Mat base,yuvMat;
    cv::resize(im,base,cv::Size(640,480));
    cv::cvtColor(base,yuvMat,CV_BGR2YUV_I420);
    if(yuvMat.empty())
        return false;
    char *frame=(char*)yuvMat.data;


    //publish metadata
    result = mEncoder.encode(frame);

    if (H264RTMPPackager::isKeyFrame(result.second)) {
        mMetadata.m_nInfoField2 = mRTMP->m_stream_id;
        mMetadata.m_nTimeStamp = RTMP_GetTime();
        if (!RTMP_SendPacket(mRTMP, &mMetadata, 1)) {
            std::cout << "fail to send packet" << std::endl;
            return false;
        }
    }



    char *buf=(char *)pool->malloc(packager.getBodyLength(result.first));
    //char *buf = mPool(packager.getBodyLength(result.first));
    RTMPPacket packet = packager.pack(buf, result.second, result.first);
    packet.m_nInfoField2 = mRTMP->m_stream_id;
    packet.m_nTimeStamp = RTMP_GetTime();
    if (!RTMP_SendPacket(mRTMP, &packet, 1)) {
        pool->free(buf);
        std::cout << "fail to send packet" << std::endl;
        return false;
    }
    pool->free(buf);
    return true;
}

RTMPPacket RTMPPub::getRtmpPacket(char *buf)
{
//    aac_result = aac_mEncoder.getMetadata();
//    char *buf=(char *)pool->malloc(256);
//    RTMPPacket packet = aac_packager.metadata(buf, aac_result.second, aac_result.first);
//    if (!RTMP_SendPacket(mRTMP, &packet, 1)) {
//    }
}



bool RTMPPub::connect(char *url)
{
    if (!RTMP_SetupURL(mRTMP, url)) {
        return false;
    }
    //mRTMP->Link.lFlags|=RTMP_LF_LIVE;
    //RTMP_SetBufferMS(mRTMP, 3600);
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
