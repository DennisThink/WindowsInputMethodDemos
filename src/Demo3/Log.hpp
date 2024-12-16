#ifndef _WIN_INPUT_DEMO_LOG_H_
#define _WIN_INPUT_DEMO_LOG_H_
#include <string>
namespace LogUtil
{
    void OpenLogFile();
    void LogInfo(const std::string& strMsg);
    void LogInfo(const char * pStrMsg);
    void LogTrace(const char* pFileName, const int line);
    void CloseLogFile();
};
#endif