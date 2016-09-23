// OpenGlCppCode.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <exception>
#include <map>
#include <memory>

#include "D3DRender.h"

#pragma comment(lib, "D3d11.lib")
#pragma comment(lib, "D2d1.lib")
#pragma comment(lib, "Dwrite.lib")

#define CPP_EXPORTS_API
#ifdef CPP_EXPORTS_API
#define CPP_API extern "C" __declspec(dllexport)
#else
#define CPP_API __declspec(dllimport)
#endif
using namespace std; 
extern map<HWND, shared_ptr<DX::Directx11>>* device = NULL;
CPP_API void InitDirectX(int handle)
{
	(*device)[(HWND) handle] = make_shared<DX::Directx11>((HWND)handle);
}

CPP_API void PrepareScene(int handle,int w,int h)
{
	auto finded = device->find((HWND) handle);
	if (finded != device->end())
	{
		//finded->second->ClearAll2();
		finded->second->CreateTarget(w, h);
		finded->second->ClearAll();
		vector<array<array<int, 3>, 2>> triangles;

		array<array<int, 3>, 2> triangle;
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		vector<array<double, 3>> xyz;
		xyz.resize(3);
		xyz[0] = { 0, 0, 0 };
		xyz[1] = { 1, 0, 0 };
		xyz[2] = { 0, 1, 0 };

		vector<array<double, 3>> normals;
		normals.resize(3);
		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		auto unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		//------------------------

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 1, 0 };
		xyz[1] = { 0, 1, 0 };
		xyz[2] = { 1, 0, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		//rect
		//------------------------
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 0, 1 };
		xyz[1] = { 1, 0, 1 };
		xyz[2] = { 0, 1, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		////------------------------

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 1, 1 };
		xyz[1] = { 0, 1, 1 };
		xyz[2] = { 1, 0, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		//rect
		////////////
		//---------------
		////////////
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 1, 0 };
		xyz[1] = { 0, 1, 1 };
		xyz[2] = { 1, 1, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		////------------------------

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 1, 1 };
		xyz[1] = { 0, 1, 1 };
		xyz[2] = { 1, 1, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 1, 0 };
		xyz[1] = { 0, 1, 1 };
		xyz[2] = { 1, 1, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		//rect
		////------------------------

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 1, 0 };
		xyz[1] = { 0, 1, 1 };
		xyz[2] = { 1, 1, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		////------------------------

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 0, 1 };
		xyz[1] = { 0, 0, 1 };
		xyz[2] = { 1, 0, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 0, 0 };
		xyz[1] = { 0, 0, 1 };
		xyz[2] = { 1, 0, 0 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		///------
		//rect

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 0, 0 };
		xyz[1] = { 1, 0, 1 };
		xyz[2] = { 1, 1, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		//-----------


		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 1, 0, 0 };
		xyz[1] = { 1, 1, 0 };
		xyz[2] = { 1, 1, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		///------
		//rect

		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 0, 0 };
		xyz[1] = { 0, 0, 1 };
		xyz[2] = { 0, 1, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);
		//-----------


		triangle[0] = { 0, 2, 1 };
		triangle[1] = { 128, 0, 128 };
		triangles.push_back(triangle);

		xyz[0] = { 0, 0, 0 };
		xyz[1] = { 0, 1, 0 };
		xyz[2] = { 0, 1, 1 };

		normals[0] = { 0, 0, 1 };
		normals[1] = { 0, 0, 1 };
		normals[2] = { 0, 0, 1 };

		finded->second->RenderStart();

		unit = finded->second->CreateTriangleColorUnit(triangles, xyz, normals);
		finded->second->AddToSaved(unit);

		finded->second->RenderSavedData();
		finded->second->EndRender();
	}
}
CPP_API void RenderScene(int handle, double angle)
{
	auto finded = device->find((HWND) handle);
	if (finded != device->end())
	{
		DirectX::XMStoreFloat4x4(&(finded->second->ModelViewMatrix), DirectX::XMMatrixRotationX(angle));
		DirectX::XMStoreFloat4x4(&(finded->second->ProjectionMatrix), /*DirectX::XMMatrixIdentity()*/
			DirectX::XMMatrixRotationY(angle));

		finded->second->RenderSavedData();
		finded->second->EndRender();
	}
}
