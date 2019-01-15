#include <mainframe/mainframe.h>
#include <rtmppublisher/MemoryPool.h>
#include <mainframe/monitor.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

using namespace std;
using namespace boost::property_tree;
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
bool MainFrame::readConfig()
{

    ptree pt;
    //open xml and read information to pt
    read_xml(CONFIG_PATH, pt);
    //read value to val need a path
    name = pt.get<string>("Config.Name");
    desc = pt.get<string>("Config.Desc");
    id=pt.get<int>("Config.ID");
    m_median_srv_port = pt.get<int>("Config.MediaSrvPort");
    m_media_srv_ip=pt.get<string>("Config.MediaSrvIP");
    std::cout<<"id="<<this->id<<" name="<<this->name<<" Desc="<<desc<<"MediaSrvPort"<<m_median_srv_port<<"MediaSrvIP"<<m_media_srv_ip<<std::endl;
    ptree oRoot = pt.get_child("Config.cams");
    for(ptree::iterator it = oRoot.begin(); it != oRoot.end(); it++){
            string sTmp;
            sTmp.clear();
    }

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


