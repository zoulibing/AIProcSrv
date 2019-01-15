#ifndef AIENGINEERPROC_H
#define AIENGINEERPROC_H
#include <plugins/i_aiengine.h>
namespace rock {

class AIEngineerProc
{
public:
     AIEngineerProc();

     bool init();
     bool proc(Mat im);
     bool close();
     bool setStatus();
     bool setTask();
};

}


#endif // AIENGINEERPROC_H
