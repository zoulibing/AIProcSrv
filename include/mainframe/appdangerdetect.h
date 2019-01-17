#ifndef APPDANGERDETECT_H
#define APPDANGERDETECT_H
#include <mainframe/i_aiapplication.h>
namespace rock
{

    class AppDangerDetect : public IAIApplicate
    {
    public:
        AppDangerDetect();
         void onConfig(string configPath);
         void onInit(int cam_id);
         void drawImg();
         string getName();
         int  getUNIID();
    };


}

#endif // APPDANGERDETECT_H
