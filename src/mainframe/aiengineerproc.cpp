#include <mainframe/aiengineerproc.h>
using namespace rock;
AIEngineerProc::AIEngineerProc():enable(true)
{
}
bool AIEngineerProc::proc(Mat im)
{
    m_lock.lock();

    m_lock.unlock();
}


bool AIEngineerProc::addTask()
{

     m_lock.lock();

     m_lock.unlock();
    return true;
}
