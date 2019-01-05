#include <mainframe/mainframe.h>
//#include "mxnet/"
#include <mxnet-cpp/MxNetCpp.h>
//#include <mxnet-cpp/MxNetCpp.h>
using namespace rock;
using namespace mxnet::cpp;
#include <rtmppublisher/MemoryPool.h>
#include <mainframe/monitor.h>

MainFrame::MainFrame():tp(10)
{
    Optimizer* opt = OptimizerRegistry::Find("sgd");
    MemoryPool pool;

}
bool MainFrame::test()
{

    Monitor tt("BTV2","rtmp://live.hkstv.hk.lxdns.com/live/hks2","","",false);
    tt.init();
    tt.start(&tp);

    Monitor tt1("BTV1","rtmp://live.hkstv.hk.lxdns.com/live/hks1","","",false);
    tt1.init();
    tt1.start(&tp);
}


