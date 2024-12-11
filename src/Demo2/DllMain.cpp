// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "Log.hpp"
#include <windows.h>
//+---------------------------------------------------------------------------
//
// DllMain
//
//----------------------------------------------------------------------------

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pvReserved)
{
	pvReserved;

    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        LogUtil::OpenLogFile();
        LogUtil::LogInfo("DLL_PROCESS_ATTACH");
        break;

    case DLL_PROCESS_DETACH:
        LogUtil::LogInfo("DLL_PROCESS_DETACH");
        LogUtil::CloseLogFile();
        break;

    case DLL_THREAD_ATTACH:
        LogUtil::LogInfo("DLL_THREAD_ATTACH");
        break;

    case DLL_THREAD_DETACH:
        LogUtil::LogInfo("DLL_THREAD_DETACH");
        break;
    }

    return TRUE;
}
