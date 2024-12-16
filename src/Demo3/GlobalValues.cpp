#include "GlobalValues.hpp"
namespace GlobalValue
{
    static HINSTANCE g_dllInstanceHandle=0;
    //0b2b6f3b-edd4-dd16-d726-2befa061c0ee
    static CLSID InputMethod_CLSID = {
    0x0b2b6f3b,
    0xedd4,
    0xdd16,
    { 0xd7, 0x26, 0x2b, 0xef, 0xa0, 0x61, 0xc0, 0xee }
    };

    const static wchar_t g_dllName[] = L"MyInputMethod.dll";;
#define CLSID_STRLEN    (38)  // strlen("{xxxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxx}")
	
    CLSID GetInputMethod_CLSID()
    {
        return InputMethod_CLSID;
    }
    bool SetInstanceHandle(HINSTANCE hInstance)
    {
        g_dllInstanceHandle = hInstance;
        return true;
    }

    HINSTANCE GetInstanceHandle()
    {
        return g_dllInstanceHandle;
    }


    const wchar_t* GetInputMethodLayoutFileName()
	{	
		return g_dllName;
	}

	const wchar_t* GetInputMethodLayoutText()
	{
		const static wchar_t g_layoutText[] = L"WinInputDemoThree.dll";;
		return g_layoutText;
	}

	const wchar_t* GetInputMethodTipPath()
	{

		const static wchar_t g_tipPath[] = L"SOFTWARE\\Microsoft\\CTF\\TIP\\{YourInputMethodGUID}";
		return g_tipPath;
	}


    const BYTE GuidSymbols[] = {
        3, 2, 1, 0, '-', 5, 4, '-', 7, 6, '-', 8, 9, '-', 10, 11, 12, 13, 14, 15
    };

    const WCHAR HexDigits[] = L"0123456789ABCDEF";

    BOOL CLSIDToString(REFGUID refGUID, _Out_writes_(39) WCHAR* pCLSIDString)
    {
        WCHAR* pTemp = pCLSIDString;
        const BYTE* pBytes = (const BYTE*)&refGUID;

        DWORD j = 0;
        pTemp[j++] = L'{';
        for (int i = 0; i < sizeof(GuidSymbols) && j < (CLSID_STRLEN - 2); i++)
        {
            if (GuidSymbols[i] == '-')
            {
                pTemp[j++] = L'-';
            }
            else
            {
                pTemp[j++] = HexDigits[(pBytes[GuidSymbols[i]] & 0xF0) >> 4];
                pTemp[j++] = HexDigits[(pBytes[GuidSymbols[i]] & 0x0F)];
            }
        }

        pTemp[j++] = L'}';
        pTemp[j] = L'\0';

        return TRUE;
    }
}