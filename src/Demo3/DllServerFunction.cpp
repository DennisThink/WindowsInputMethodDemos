#include "DllServerFunction.hpp"
#include "Log.hpp"
#include "RegKeyFunction.hpp"
extern "C"
{

    DLL_EXPORT HRESULT DllRegisterServer(void)
    {
        LogUtil::LogInfo("DllRegisterServer");
        InstallRegKeyValues();
        return S_OK;
    }


    DLL_EXPORT HRESULT DllUnregisterServer(void)
    {
        LogUtil::LogInfo("DllUnregisterServer");
        UnInstallRegKeyValues();
        return S_OK;
    }

}

