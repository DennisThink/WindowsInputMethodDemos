#include "RegKeyFunction.hpp"
void InstallRegKeyValues()
{
    HKEY hKey;
    LONG result;

    // 1. 添加到 Keyboard Layouts
    const wchar_t* layoutsPath = L"SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\00000409";
    result = RegCreateKeyExW(HKEY_LOCAL_MACHINE, layoutsPath, 0, nullptr, 0, KEY_WRITE, nullptr, &hKey, nullptr);
    if (result != ERROR_SUCCESS) {
        std::wcerr << L"Failed to open Keyboard Layouts key, error: " << result << std::endl;
        return false;
    }

    // 写入 Layout File
    const wchar_t* dllName = L"MyInputMethod.dll";
    RegSetValueExW(hKey, L"Layout File", 0, REG_SZ, (const BYTE*)dllName, (DWORD)(wcslen(dllName) + 1) * sizeof(wchar_t));

    // 写入 Layout Text
    const wchar_t* layoutText = L"My Input Method";
    RegSetValueExW(hKey, L"Layout Text", 0, REG_SZ, (const BYTE*)layoutText, (DWORD)(wcslen(layoutText) + 1) * sizeof(wchar_t));

    RegCloseKey(hKey);

    // 2. 添加到 CTF\TIP
    const wchar_t* tipPath = L"SOFTWARE\\Microsoft\\CTF\\TIP\\{YourInputMethodGUID}";
    result = RegCreateKeyExW(HKEY_LOCAL_MACHINE, tipPath, 0, nullptr, 0, KEY_WRITE, nullptr, &hKey, nullptr);
    if (result != ERROR_SUCCESS) {
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
void UnInstallRegKeyValues()
{

}