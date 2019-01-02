#include <mainframe/monitor.h>
using namespace rock;

Monitor::Monitor(string name,string cam_uri,string desc,string publish_uri)
    :max_waiting_ai_result_time(100),no(-1),enable(false),_tpp(0x00),open_cam_retry_times(3),executor(10)
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
        this->_camera_uri="rtmp://202.69.69.180:443/webcast/bshdlive-pc";
        this->vcap.open(0);
        boost::this_thread::sleep(boost::posix_time::seconds(1));
        idx+=1;

    }
    if(!this->vcap.isOpened())
        return false;
    this->enable=true;


    //begin thread of tpp
    //_tpp->schedule(boost::bind(on_thread, this));
      std::future<void> ff = executor.commit(on_thread,this);

}


void Monitor::on_thread(Monitor * monitor)
{
    //boost::this_thread
    if(monitor==0x00)
        return;
    Monitor * mo=(Monitor *)monitor;
    while(mo->enable)
    {
        //std::cout<<"nn"<<std::endl;
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
     Mat frame;
     //读取当前帧
     vcap >> frame;
     //播放完退出
     if (frame.empty()) {
         printf("播放完成\n");

     }
     //显示当前视频
     imshow("读取视频",frame);
     //延时30ms
     waitKey(10);


     //this->vcap.read()


    //1.get a frame from cap

    //2.check tasks status,if all tasks finished in time

    //3.if outoftime and other+

    //4.

     return true;


}
