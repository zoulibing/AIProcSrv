#ifndef AIAPPLICATEENGINEER_H
#define AIAPPLICATEENGINEER_H
#include <mainframe/i_aiapplication.h>
#include <vector>
using namespace std;
namespace rock {

    class AIApplicateEngineer
    {
    public:
        AIApplicateEngineer();

    private:
        std::vector<IAIApplicate> m_applications;
        std::vector<string> m_app_urls;
        void loadApp(const std::string app_str);

    };
}


#endif // AIAPPLICATEENGINEER_H
