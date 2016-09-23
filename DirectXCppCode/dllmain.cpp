// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <map>
#include <memory>
#include "D3DRender.h"

using namespace std;
extern map<HWND, shared_ptr<DX::Directx11>>* device;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	if (device == nullptr)device = new map<HWND, shared_ptr<DX::Directx11>>();
	return TRUE;
}

