#include <mainframe/monitor.h>
using namespace rock;

Monitor::Monitor(string &name,string &cam_uri,string &desc,string publish_uri)
    :max_waiting_ai_result_time(100),no(-1),enable(false),_tpp(0x00),open_cam_retry_times(3)
{

}

bool Monitor::init()
{

}

bool Monitor::start(threadpool::pool *_tpp)
{

    int idx=0;
    while(!this->vcap.isOpened() && idx<open_cam_retry_times)
    {
        this->vcap.open(this->_camera_uri);
        boost::this_thread::sleep(boost::posix_time::seconds(1));
        idx+=1;

    }
    if(!this->vcap.isOpened())
        return false;


    //begin thread of tpp
    _tpp->schedule(boost::bind(on_thread, this));

}


void Monitor::on_thread(Monitor * monitor)
{
    if(monitor==0x00)
        return;
    Monitor * mo=(Monitor *)monitor;
    while(mo->enable)
    {

        if(mo->proc()==false)
            break;
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    }
     mo->enable=false;

}

bool Monitor::proc()
{

     if(!this->vcap.isOpened())
       return false;
     //this->vcap.read()


    //1.get a frame from cap

    //2.check tasks status,if all tasks finished in time

    //3.if outoftime and other+

    //4.


}
