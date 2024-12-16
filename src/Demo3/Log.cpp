#include "Log.hpp"
#include <iostream>
#include <fstream>
namespace LogUtil
{
    static std::ofstream g_logFile;

    void OpenLogFile()
    {
        std::cout<<"Open Log File"<<std::endl;
        g_logFile.open("./Demo3_log.txt",std::ios_base::out|std::ios_base::app);
    }
    void LogInfo(const std::string& strMsg)
    {
        std::cout<<"LOG_INFO STRING "<<strMsg<<std::endl;
        g_logFile.write(strMsg.c_str(), strMsg.length());
        g_logFile.write("\r\n", 2);
    }
    void LogInfo(const char * pStrMsg)
    {
        std::cout<<"LOG_INFO CHAR * "<< pStrMsg <<std::endl;
        g_logFile.write(pStrMsg,std::strlen(pStrMsg));
        g_logFile.write("\r\n", 2);
    }

    void LogTrace(const char* pFileName, const int line)
    {
        char buff[128] = { 0 };
        memset(buff, 0, 128);
        sprintf(buff, "%s %d\n", pFileName, line);
        g_logFile.write(buff, std::strlen(buff));
    }
    void CloseLogFile()
    {
        std::cout<<"Close Log File"<<std::endl;
        g_logFile.close();
    }
}
  