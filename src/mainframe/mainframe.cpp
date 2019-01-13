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


