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

    rock:Monitor tt("11","","","");
    tt.init();
    tt.start(&tp);
}


