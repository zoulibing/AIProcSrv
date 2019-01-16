#include <mainframe/aiservice.h>
using namespace rock;

AIService::AIService(int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible)
{
    this->id=id;
    this->name=name;
    this->ip=srv_ip;
    this->port=srv_port;
    this->stand_height=stand_h;
    this->stand_width=stand_w;
    this->desc=desc;
    this->visible=visible;

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
