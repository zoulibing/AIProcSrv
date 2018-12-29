#ifndef MONITOR_H
#define MONITOR_H
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <threads/threadpool.hpp>
using namespace std;
using namespace boost;


namespace rock {
    class Monitor
    {
    public:
        Monitor(string &name,string &uri,string &desc);
        bool init();
        bool start(boost::threadpool::pool *_tpp);
        bool stop();
        bool destroy();

    private:
        string _name;
        string _uri;
        string _desc;
        void on_thread(Monitor * monitor);
        void proc();

        int no;
        int max_waiting_ai_result_time;//
        int enable;
        boost::threadpool::pool *_tpp;




    };

}


#endif // MONITOR_H
