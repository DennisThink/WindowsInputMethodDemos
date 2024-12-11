#ifndef _WIN_INPUT_METHOD_DLL_SERVER_FUNCTION_H_
#define _WIN_INPUT_METHOD_DLL_SERVER_FUNCTION_H_
#include <windows.h>
#include <ole2.h>
#include <objbase.h>

#define DLL_EXPORT __declspec(dllexport)

extern "C"
{
	DLL_EXPORT HRESULT DllRegisterServer(void);
	DLL_EXPORT HRESULT DllUnRegisterServer(void);
}

#endif