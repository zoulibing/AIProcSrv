#include <mainframe/aiservice.h>
#include <opencv2/opencv.hpp>
using namespace rock;
using namespace cv;
int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
   struct timeval tv;
   gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
};

AIService::AIService(int camid,int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible)
{
    this->id=id;
    this->name=name;
    this->ip=srv_ip;
    this->port=srv_port;
    this->stand_height=stand_h;
    this->stand_width=stand_w;
    this->desc=desc;
    this->visible=visible;
    this->m_camID=camid;

}
 std::vector<Result> AIService::Proc(int serialID,Mat im)
 {

     if(transport->isOpen())
     {
         Request resq;
         resq.buff=std::string((char*)im.data,im.total()*im.elemSize());
         resq.camID=m_camID;
         resq.height=stand_height;
         resq.width=stand_width;
         resq.pic_nums=1;
         resq.serialID=serialID;
         Respone rps;
         int64_t start=getCurrentTime();
         client->sendImage(rps,m_camID,serialID,resq);
//         int64_t end=getCurrentTime();
//         std::cout<<end-start<<std::endl;
//         std::cout<<rps.cameID<<std::endl;
//         std::cout<<rps.serialID<<std::endl;
//         std::cout<<rps.ritems.at(0).x0<<std::endl;

     }
    return cur_result;
 }

bool AIService::start()
{
      socket=new TSocket(ip,port);
      transport=new TBufferedTransport(boost::shared_ptr<TSocket> (socket));
      protocol=new TBinaryProtocol(boost::shared_ptr<TTransport>(transport));
      client=new AIProReqClient(boost::shared_ptr<TProtocol>(protocol));
      int time=0;
      while(!transport->isOpen() && time <60)
      {
               transport->open();
               sleep(1);
               time ++;
      }
      if(!transport->isOpen())
          return false;

    return true;
}
bool AIService::stop()
{
    transport->close();
    if(transport->isOpen())
        return false;
    return true;
}
bool AIService::release()
{
   if(stop())
       return false;
   delete socket;
   delete transport;
   delete protocol;
   delete client;
    return true;
}
