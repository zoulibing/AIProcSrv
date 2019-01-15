#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include <threads/threadpool.hpp>
#include <threads/threadpool.hpp>
#include <mainframe/threadpool.h>
#include <map>
#include <mainframe/monitor.h>
#define CONFIG_PATH "/home/li/zoulb/AIProcSrv/build/config.xml"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
using namespace boost::property_tree;



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
        bool readConfig();
        bool addNewMonitor(int id,string name,int type,string cam_url,string desc);
        bool removeMonitor(int id);
        bool stopMonitor(int id);
        bool saveConfig();
        std::threadpool tp;
        int id;
        map<int,Monitor> monitors;
        std::string m_media_srv_ip;
        int m_median_srv_port;
        std::string name;
        std::string desc;
        bool enable;
        map<int,ptree> cams_config;



    };


}


#endif // MAINFRAME_H
