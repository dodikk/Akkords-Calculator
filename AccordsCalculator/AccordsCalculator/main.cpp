#include "stdafx.h"


using namespace Wt;
using namespace WebUi;



WApplication *CreateApplication(const WEnvironment& env)
{
    return new AccordsCalculatorApp(env);
}


int main(int argc, char **argv)
{
    try
    {
        return WRun(argc, argv, &CreateApplication);
    }
    catch(const std::exception& ex)
    {
        std::cout << "std::exception caught" << std::endl;
        std::cout << ex.what()               << std::endl;
        return 2;
    }
    catch (...)
    {
        std::cout << "Unknown error occured" << std::endl;
        return 1;
    }

}


