#include <mainframe/mainframe.h>
//#include "mxnet/"
#include <mxnet-cpp/MxNetCpp.h>
using namespace rock;
using namespace mxnet::cpp;
#include <rtmppublisher/MemoryPool.h>

MainFrame::MainFrame():tp(10)
{
    Optimizer* opt = OptimizerRegistry::Find("sgd");
    MemoryPool pool;

}
