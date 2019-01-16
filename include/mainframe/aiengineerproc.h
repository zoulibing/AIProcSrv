#ifndef AIENGINEERPROC_H
#define AIENGINEERPROC_H
#include <plugins/i_aiengine.h>
#include <mainframe/aiservice.h>
#include <map>
#include <iostream>
#include <boost/thread.hpp>
using namespace std;

using namespace boost;
namespace rock {

class AIEngineerProc
{
public:
     AIEngineerProc();

     bool start();
     bool release();
     bool proc(Mat im);
     bool setStatus();
     bool stopService(int seviceID);
     bool addService();
     bool enable;
     map<int ,AIService> services;
     boost::mutex m_lock;

};

}


#endif // AIENGINEERPROC_H
