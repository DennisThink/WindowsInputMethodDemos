#ifndef _WIN_INPUT_DEMO_GLOBAL_H_
#define _WIN_INPUT_DEMO_GLOBAL_H_
#include <windows.h>
#include <iostream>
namespace GlobalValue
{
	bool SetInstanceHandle(HINSTANCE hInstance);
	HINSTANCE GetInstanceHandle();
	CLSID GetInputMethod_CLSID();
	const wchar_t* GetInputMethodLayoutString();
	const wchar_t* GetInputMethodLayoutFileName();
	const wchar_t* GetInputMethodLayoutText();
	const wchar_t* GetInputMethodTipPath();
	BOOL CLSIDToString(REFGUID refGUID, _Out_writes_(39) WCHAR* pCLSIDString);

};
#endif