#include "DllServerFunction.hpp"
#include "Log.hpp"
extern "C"
{
    DLL_EXPORT HRESULT DllUnregisterServer(void)
    {
        LogUtil::LogInfo("DllUnregisterServer");
        return S_OK;
    }

    DLL_EXPORT HRESULT DllRegisterServer(void)
    {
        LogUtil::LogInfo("DllRegisterServer");
        return S_OK;
    }
}

