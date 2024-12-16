#include "RegKeyFunction.hpp"
#include "GlobalValues.hpp"
#include <windows.h>
#include <iostream>
#include <winnt.h>
#include "Log.hpp"
#define CLSID_STRLEN    (38)  // strlen("{xxxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxx}")

bool InstallRegKeyValuesNew();
bool InstallRegKeyValues()
{
    DWORD copiedStringLen = 0;
    HKEY regKeyHandle = nullptr;
    HKEY regSubkeyHandle = nullptr;
    BOOL ret = FALSE;
    const std::size_t KeyLength = 128;
    WCHAR* achIMEKey = new WCHAR[KeyLength];
    memset(achIMEKey, 0, sizeof(WCHAR) * KeyLength);
    WCHAR achFileName[MAX_PATH] = { '\0' };

    static const WCHAR RegInfo_Prefix_CLSID[] = L"CLSID\\";
    static const WCHAR RegInfo_Key_InProSvr32[] = L"InProcServer32";
    static const WCHAR RegInfo_Key_ThreadModel[] = L"ThreadingModel";

    static const WCHAR TEXTSERVICE_DESC[] = L"DT Input Demo";
#define TEXTSERVICE_MODEL        L"Apartment"

    if (!GlobalValue::CLSIDToString(GlobalValue::GetInputMethod_CLSID(), achIMEKey + ARRAYSIZE(RegInfo_Prefix_CLSID) - 1))
    {
        LogUtil::LogInfo("GlobalValue::CLSIDToString Failed");
        LogUtil::LogTrace(__FILE__, __LINE__);
        return FALSE;
    }

    memcpy(achIMEKey, RegInfo_Prefix_CLSID, sizeof(RegInfo_Prefix_CLSID) - sizeof(WCHAR));

    if (RegCreateKeyExW(HKEY_CLASSES_ROOT, achIMEKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &regKeyHandle, &copiedStringLen) == ERROR_SUCCESS)
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        if (RegSetValueExW(regKeyHandle, NULL, 0, REG_SZ, (const BYTE*)TEXTSERVICE_DESC, (_countof(TEXTSERVICE_DESC)) * sizeof(WCHAR)) != ERROR_SUCCESS)
        {
            LogUtil::LogTrace(__FILE__, __LINE__);
            goto Exit;
        }

        if (RegCreateKeyExW(regKeyHandle, RegInfo_Key_InProSvr32, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &regSubkeyHandle, &copiedStringLen) == ERROR_SUCCESS)
        {
            LogUtil::LogTrace(__FILE__, __LINE__);
            copiedStringLen = GetModuleFileNameW(GlobalValue::GetInstanceHandle(), achFileName, ARRAYSIZE(achFileName));
            copiedStringLen = (copiedStringLen >= (MAX_PATH - 1)) ? MAX_PATH : (++copiedStringLen);
            if (RegSetValueEx(regSubkeyHandle, NULL, 0, REG_SZ, (const BYTE*)achFileName, (copiedStringLen) * sizeof(WCHAR)) != ERROR_SUCCESS)
            {
                LogUtil::LogTrace(__FILE__, __LINE__);
                goto Exit;
            }
            if (RegSetValueExW(regSubkeyHandle, RegInfo_Key_ThreadModel, 0, REG_SZ, (const BYTE*)TEXTSERVICE_MODEL, (_countof(TEXTSERVICE_MODEL)) * sizeof(WCHAR)) != ERROR_SUCCESS)
            {
                LogUtil::LogTrace(__FILE__, __LINE__);
                goto Exit;
            }

            ret = TRUE;
        }
    }

Exit:
    if (regSubkeyHandle)
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        RegCloseKey(regSubkeyHandle);
        regSubkeyHandle = nullptr;
    }
    if (regKeyHandle)
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        RegCloseKey(regKeyHandle);
        regKeyHandle = nullptr;
    }

    InstallRegKeyValuesNew();
    return ret;

}

bool InstallRegKeyValuesNew()
{
    bool bLastResult = false;
    HKEY hKey;
    LONG result;

    // 1. 添加到 Keyboard Layouts
    const wchar_t* layoutsPath = L"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\00000409";
    result = RegCreateKeyExW(HKEY_LOCAL_MACHINE, layoutsPath, 0, nullptr, 0, KEY_WRITE, nullptr, &hKey, nullptr);
    if (result != ERROR_SUCCESS) {
        LogUtil::LogTrace(__FILE__, __LINE__);
        std::wcerr << L"Failed to open Keyboard Layouts key, error: " << result << std::endl;
        return false;
    }

    // 写入 Layout File
    const wchar_t* dllName = GlobalValue::GetInputMethodLayoutFileName(); //L"MyInputMethod.dll";
    RegSetValueExW(hKey, L"Layout File", 0, REG_SZ, (const BYTE*)dllName, (DWORD)(wcslen(dllName) + 1) * sizeof(wchar_t));

    // 写入 Layout Text
    const wchar_t* layoutText = GlobalValue::GetInputMethodLayoutText();
    RegSetValueExW(hKey, L"Layout Text", 0, REG_SZ, (const BYTE*)layoutText, (DWORD)(wcslen(layoutText) + 1) * sizeof(wchar_t));

    RegCloseKey(hKey);

    // 2. 添加到 CTF\TIP
    const wchar_t* tipPath = GlobalValue::GetInputMethodTipPath();
    result = RegCreateKeyExW(HKEY_LOCAL_MACHINE, tipPath, 0, nullptr, 0, KEY_WRITE, nullptr, &hKey, nullptr);
    if (result != ERROR_SUCCESS) {
        LogUtil::LogTrace(__FILE__, __LINE__);
        std::wcerr << L"Failed to open TIP key, error: " << result << std::endl;
        return false;
    }

    // 写入 Description
    const wchar_t* description = L"My Input Method";
    RegSetValueExW(hKey, L"Description", 0, REG_SZ, (const BYTE*)description, (DWORD)(wcslen(description) + 1) * sizeof(wchar_t));

    RegCloseKey(hKey);

    std::wcout << L"Input method registered successfully." << std::endl;
    return true;
}

LONG RecurseDeleteKey(_In_ HKEY hParentKey, _In_ WCHAR* lpszKey)
{
    //Global::LogInfo(TEXT("RecurseDeleteKey"));
    HKEY regKeyHandle = nullptr;
    LONG res = 0;
    FILETIME time;
    WCHAR stringBuffer[256] = { '\0' };
    DWORD size = ARRAYSIZE(stringBuffer);

    if (RegOpenKeyW(hParentKey, lpszKey, &regKeyHandle) != ERROR_SUCCESS)
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        return ERROR_SUCCESS;
    }

    res = ERROR_SUCCESS;
    while (RegEnumKeyExW(regKeyHandle, 0, stringBuffer, &size, NULL, NULL, NULL, &time) == ERROR_SUCCESS)
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        stringBuffer[ARRAYSIZE(stringBuffer) - 1] = '\0';
        res = RecurseDeleteKey(regKeyHandle, stringBuffer);
        if (res != ERROR_SUCCESS)
        {
            LogUtil::LogTrace(__FILE__, __LINE__);
            break;
        }
        size = ARRAYSIZE(stringBuffer);
    }
    RegCloseKey(regKeyHandle);

    return res == ERROR_SUCCESS ? RegDeleteKeyW(hParentKey, lpszKey) : res;
}


bool UnInstallRegKeyValues()
{
    const std::size_t KeyLength = 128;
    WCHAR* achIMEKey = new WCHAR[KeyLength];
    memset(achIMEKey, 0, sizeof(WCHAR) * KeyLength);
    WCHAR achFileName[MAX_PATH] = { '\0' };

    static const WCHAR RegInfo_Prefix_CLSID[] = L"CLSID\\";
    static const WCHAR RegInfo_Key_InProSvr32[] = L"InProcServer32";
    static const WCHAR RegInfo_Key_ThreadModel[] = L"ThreadingModel";

    static const WCHAR TEXTSERVICE_DESC[] = L"DT Input Demo";
#define TEXTSERVICE_MODEL        L"Apartment"

    if (!GlobalValue::CLSIDToString(GlobalValue::GetInputMethod_CLSID(), achIMEKey + ARRAYSIZE(RegInfo_Prefix_CLSID) - 1))
    {
        LogUtil::LogTrace(__FILE__, __LINE__);
        return FALSE;
    }

    memcpy(achIMEKey, RegInfo_Prefix_CLSID, sizeof(RegInfo_Prefix_CLSID) - sizeof(WCHAR));

    RecurseDeleteKey(HKEY_CLASSES_ROOT, achIMEKey);
    return false;
}