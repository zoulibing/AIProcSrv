#ifndef RTMPPUB_H
#define RTMPPUB_H
#include <librtmp/rtmp.h>
#include <chrono>
#include <rtmppublisher/H264Encoder.h>
#include <rtmppublisher/H264RTMPPackager.h>

namespace rock {
class RTMPPub
{
public:
    RTMPPub();
    ~RTMPPub();
    bool init();
    bool publish();
    bool connect(char *url);
private:
    RTMP *mRTMP;
    H264Encoder mEncoder;
    RTMPPacket mMetadata;
};

}


#endif // RTMPPUB_H
