#include <mainframe/rtmppub.h>
using namespace rock;


RTMPPub::RTMPPub()
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
