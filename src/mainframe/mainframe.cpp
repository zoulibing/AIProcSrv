#include <mainframe/mainframe.h>
//#include "mxnet/"
#include <mxnet-cpp/MxNetCpp.h>
//#include <mxnet-cpp/MxNetCpp.h>
using namespace rock;
using namespace mxnet::cpp;
#include <rtmppublisher/MemoryPool.h>
#include <mainframe/monitor.h>
#include <unistd.h>

MainFrame::MainFrame():tp(10)
{
    Optimizer* opt = OptimizerRegistry::Find("sgd");
    MemoryPool pool;

}
bool MainFrame::test()
{


    Monitor tt1("BTV1","rtmp://live.hkstv.hk.lxdns.com/live/hks1","","",false,25);
    tt1.init();
    tt1.start(&tp);
    Monitor tt("cc","rtmp://live.hkstv.hk.lxdns.com/live/hks2","","",false,20);
    tt.init();
    tt.start(&tp);
    Monitor tt2("cc2","rtmp://live.hkstv.hk.lxdns.com/live/hks2","","",false,30);
    tt2.init();
    tt2.start(&tp);
    Monitor tt3("cc3","rtmp://live.hkstv.hk.lxdns.com/live/hks1","","",false,20);
    tt3.init();
    tt3.start(&tp);
    while(getchar()!='e')
    {
        usleep(1 * 1000);
    }
    std::cout<<"exit...."<<std::endl;



}


