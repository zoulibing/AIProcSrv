#include <mainframe/monitor.h>

using namespace rock;

Monitor::Monitor(string name,string cam_uri,string desc,string publish_uri,bool cv_show)
    :_cvshow(false),max_waiting_ai_result_time(100),no(-1),enable(false),_tpp(0x00),
      open_cam_retry_times(3),executor(10),rtmpPublisher(pool)
{
 this->_camera_uri=cam_uri;
 this->_name=name;
 this->_cvshow=cv_show;
 this->rtmpPublisher.init();
}

bool Monitor::init()
{

}

bool Monitor::start(threadpool::pool *_tpp)
{

    int idx=0;
    if(this->_cvshow)
    namedWindow(this->_name);

    while(!this->vcap.isOpened() && idx<open_cam_retry_times)
    {
        this->vcap.open(this->_camera_uri);
        std::chrono::seconds timespan(1);
        std::this_thread::sleep_for(timespan);
        idx+=1;

    }
    if(!this->vcap.isOpened())
        return false;
    this->enable=true;
    std::string rtmp_url="rtmp://127.0.0.1/live/"+this->_name;
    this->rtmpPublisher.connect((char*)rtmp_url.data());


    //begin thread of tpp
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
         if(mo->proc()==false)
            break;
        std::chrono::milliseconds timespan(10);
        std::this_thread::sleep_for(timespan);
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
         return false;
     }
     this->rtmpPublisher.publish(frame);
     //显示当前视频
     if(this->_cvshow)
     {
         imshow(this->_name,frame);
         //延时30ms
         waitKey(30);
     }



     //this->vcap.read()


    //1.get a frame from cap

    //2.check tasks status,if all tasks finished in time

    //3.if outoftime and other+

    //4.

     return true;


}
