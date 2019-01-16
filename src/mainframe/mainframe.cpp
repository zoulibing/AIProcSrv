#include <mainframe/mainframe.h>
#include <rtmppublisher/MemoryPool.h>
#include <mainframe/monitor.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>

using namespace std;

using namespace rock;
using namespace cv;

MainFrame::MainFrame():tp(20)
{
    //Optimizer* opt = OptimizerRegistry::Find("sgd");
    //MemoryPool pool;
    //load config
    //init config
    //

}
bool MainFrame::init()
{
    return readConfig();
}
bool MainFrame::start()
{
      map<int,ptree>::iterator it;
      for(it=cams_config.begin();it!=cams_config.end();++it)
      {
          int id=(int)it->first;
          ptree cam = it->second;
          string name=cam.get<string>("name");
          string cam_url=cam.get<string>("url");
          string desc=cam.get<string>("dscript");
          string publish_url=cam.get<string>("publish");
          int isshow=cam.get<int>("isshow");
          bool show=(isshow==1?true:false);
          int fps=cam.get<int>("fps");
          Monitor *mo=new Monitor(tp,name,cam_url,desc,publish_url,show,fps);

          if(mo->init() && mo->start())
          {

              m_lock.lock();
              monitors.insert(std::make_pair(id,mo));
              m_lock.unlock();
              std::cout<<"MainFrame::start"<<std::endl;
          }
          else
              mo->stop();
          sleep(1);

      }

    return true;
}
bool MainFrame::stop()
{

    return true;
}

bool MainFrame::saveConfig()
{

    return true;
}
bool MainFrame::readConfig()
{
    ptree pt;
    //open xml and read information to pt
    read_xml(CONFIG_PATH, pt);
    //read value to val need a path
    name = pt.get<string>("Config.Name");
    desc = pt.get<string>("Config.Desc");
    id=pt.get<int>("Config.ID");
    m_main_srv_port = pt.get<int>("Config.MainSrvPort");
    m_main_srv_ip=pt.get<string>("Config.MainSrvIP");
    //std::cout<<"id="<<this->id<<" name="<<this->name<<" Desc="<<desc<<"MediaSrvPort"<<m_median_srv_port<<"MediaSrvIP"<<m_media_srv_ip<<std::endl;
    ptree oRoot = pt.get_child("Config.cams");
    for(ptree::iterator it = oRoot.begin(); it != oRoot.end(); it++)
    {
        ptree cam = it->second;
        int cam_id=cam.get<int>("id");

        cams_config.insert(std::make_pair(cam_id,cam));
    }

    //
    //https://blog.csdn.net/dgyanyong/article/details/45242243
    return true;
}
bool MainFrame::test()
{
    readConfig();

    Monitor tt1(tp,"BTV1","rtmp://live.hkstv.hk.lxdns.com/live/hks1","","",false,25);
    tt1.init();
    tt1.start();
    Monitor tt(tp,"cc","rtmp://live.hkstv.hk.lxdns.com/live/hks2","","",false,20);
    tt.init();
    tt.start();
    Monitor tt2(tp,"cc2","rtmp://live.hkstv.hk.lxdns.com/live/hks2","","",false,30);
    tt2.init();
    tt2.start();
    Monitor tt3(tp,"cc3","rtmp://live.hkstv.hk.lxdns.com/live/hks1","","",false,20);
    tt3.init();
    tt3.start();
    while(getchar()!='e')
    {
        usleep(1 * 1000);
    }
    std::cout<<"exit...."<<std::endl;



}


