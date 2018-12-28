#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include <threads/threadpool.hpp>



using namespace boost;
using namespace std;

namespace rock {

    class MainFrame
    {
    public:
        MainFrame();
        bool init();


    private:
        boost::threadpool::pool tp;

    };


}


#endif // MAINFRAME_H
