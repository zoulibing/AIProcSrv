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


bool AIEngineerProc::addService()
{

     m_lock.lock();

     m_lock.unlock();
    return true;
}

bool AIEngineerProc::stopService(int seviceID)
{

    return true;
}

bool AIEngineerProc::start()
{
    return true;
}
bool AIEngineerProc::release()
{

    return true;
}
