#pragma once

#include <Unknwn.h>

struct __declspec(uuid("e03ac9b2-ccf6-40a8-b122-e6ab51cace3b")) 
IHen : IUnknown
{
	virtual void __stdcall Cluck() = 0;
	virtual void __stdcall Roost() = 0;
};

struct __declspec(uuid("0480272e-713e-422b-ae48-2f31e10ef8d7")) 
IHen2 : IHen
{
	virtual void __stdcall Forage() = 0;
};

struct __declspec(uuid("231f3bfe-b771-47ae-8619-b6c8a032fa43")) 
IOfflineChicken : IUnknown
{
	virtual void __stdcall Load(char const * file) = 0;
	virtual void __stdcall Save(char const * file) = 0;
};

HRESULT __stdcall CreateHen(IHen **hen);