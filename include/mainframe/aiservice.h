#ifndef AISERVICE_H
#define AISERVICE_H
#include <iostream>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thirft-gen/AIProReq.h>
#include <opencv2/opencv.hpp>
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace cv;


using namespace std;

namespace rock {

   struct Point{int x;int y;};

   struct Result{
     std::vector<Point> points;
     int color;
     string label;
     int points_num;
   };


    class AIService
    {
        public:
            AIService(int camid,int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible);
           std::vector<Result> Proc(int serialID,Mat im);
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
            int cur_img_id;
            int m_camID;
            string desc;
            TSocket * socket;
            TBufferedTransport* transport;
            TBinaryProtocol *protocol;
            AIProReqClient *client;
            std::vector<Result> cur_result;

    };

}

#endif // AISERVICE_H
