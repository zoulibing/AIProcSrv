#include <mainframe/monitor.h>
using namespace rock;

Monitor::Monitor(string &name,string &uri,string &desc)
{

}

void Monitor::on_thread(Monitor * monitor)
{
    if(monitor==0x00)
        return;
    Monitor * mo=(Monitor *)monitor;
    while(mo->enable)
    {

        mo->proc();
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    }

}

void Monitor::proc()
{

}
