#ifndef I_AIAPPLICATION_H
#define I_AIAPPLICATION_H
#include <iostream>
using namespace std;
namespace rock {
class IAIApplicate
{
  virtual void onConfig(string configPath)=0;
  virtual void onInit(int cam_id)=0;
  virtual void drawImg()=0;
  virtual string getName()=0;
  virtual int  getUNIID()=0;


};
}


#endif 
