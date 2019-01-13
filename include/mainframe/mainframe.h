#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include <threads/threadpool.hpp>
#include <threads/threadpool.hpp>
#include <mainframe/threadpool.h>




using namespace boost;
using namespace std;

namespace rock {

    class MainFrame
    {
    public:
        MainFrame();
        bool init();
        bool test();


    private:
        //boost::threadpool::pool tp;
        std::threadpool tp;

    };


}


#endif // MAINFRAME_H
