#ifndef AISERVICE_H
#define AISERVICE_H
#include <iostream>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thirft-gen/AIProReq.h>
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


using namespace std;

namespace rock {
    class AIService
    {
        public:
            AIService(int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible);
            bool start();
            bool stop();
            bool release();


        private:
            int stand_width;
            int stand_height;
            float scalar_w;
            float scalar_h;
            string name;
            string ip;
            int id;
            int port;
            int visible;
            string desc;
            TSocket * socket;
            TBufferedTransport* transport;
            TBinaryProtocol *protocol;
            AIProReqClient *client;

    };

}

#endif // AISERVICE_H
