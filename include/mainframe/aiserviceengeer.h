#ifndef AIENGINEERPROC_H
#define AIENGINEERPROC_H
#include <plugins/i_aiengine.h>
#include <mainframe/aiservice.h>
#include <map>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
using namespace boost::property_tree;
using namespace std;

using namespace boost;
namespace rock {

class AIServiceEngineer
{
public:
     AIServiceEngineer(int camid);

     bool start();
     bool release();
     bool proc(Mat im);
     bool setStatus();
     bool stopService(int seviceID);
     bool addServiceByXML(ptree pt);
     bool addService(int camid,int id,string name,string srv_ip,int srv_port,int stand_w,int stand_h,string desc,bool visible);
     bool enable;
     map<int ,AIService*> services;
     boost::mutex m_lock;
     boost::mutex m_app_lock;
     ptree m_pt;
     int cameid;

};

}


#endif // AIENGINEERPROC_H
