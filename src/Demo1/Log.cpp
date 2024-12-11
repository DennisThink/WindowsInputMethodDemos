#include "Log.hpp"
#include <iostream>
namespace LogUtil
{
    void OpenLogFile()
    {
        std::cout<<"Open Log File"<<std::endl;
    }
    void LogInfo(const std::string& strMsg)
    {
        std::cout<<"LOG_INFO STRING "<<strMsg<<std::endl;
    }
    void LogInfo(const char * pStrMsg)
    {
        std::cout<<"LOG_INFO CHAR * "<< pStrMsg <<std::endl;
    }
    void CloseLogFile()
    {
        std::cout<<"Close Log File"<<std::endl;
    }
}
  