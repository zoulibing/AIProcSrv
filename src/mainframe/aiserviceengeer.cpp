#include <mainframe/aiserviceengeer.h>
using namespace rock;
AIServiceEngineer::AIServiceEngineer(int camid):enable(true)
{
    this->cameid=camid;
}
bool AIServiceEngineer::proc(Mat im)
{
    m_lock.lock();

    m_lock.unlock();
}

bool AIServiceEngineer::addServiceByXML(ptree pt)
{
    m_pt=pt;
    for(ptree::iterator it = m_pt.begin(); it != m_pt.end(); it++)
    {
        ptree service = it->second;
        string  name=service.get<string>("Name");
        int  id=service.get<int>("id");
        string ip=service.get<string>("IP");
        int  port=service.get<int>("Port");
        string desc=service.get<string>("Desc");
        int vis=service.get<int>("Visible");
        int stand_w=service.get<int>("Stand_w");
        int stand_h=service.get<int>("Stand_h");
        addService(this->cameid,id,name,ip,port,stand_w,stand_h,desc,(vis==1?true:false));

    }


    return true;
}

bool AIServiceEngineer::addService(int camid,int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible)
{

     m_lock.lock();
     AIService * ais=new AIService(camid,id,name,srv_ip,srv_port,stand_w,stand_h,desc,visible);
     ais->start();
     services.insert(std::make_pair(id,ais));
     m_lock.unlock();
    return true;
}

bool AIServiceEngineer::stopService(int seviceID)
{

    return true;
}

bool AIServiceEngineer::start()
{
     m_lock.lock();

     m_lock.unlock();
    return true;
}
bool AIServiceEngineer::release()
{

    return true;
}
