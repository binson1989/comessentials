#include "stdafx.h"
#include "Library.h"
#include <stdio.h>
#include <crtdbg.h>

#define ASSERT _ASSERT

struct Hen : IHen2, IOfflineChicken
{
	ULONG m_count;

	Hen() : m_count(0)
	{
		printf("Cheep\n");
	}

	~Hen()
	{
		printf("Chicken soup\n");
	}

#pragma region IUnknown
	ULONG __stdcall AddRef()
	{
		return InterlockedIncrement(&m_count);
	}

	ULONG __stdcall Release()
	{
		ULONG result = InterlockedDecrement(&m_count);
		if (0 == result)
		{
			delete this;
		}
		return result;
	}

	HRESULT __stdcall QueryInterface(IID const &id, void **result)
	{
		ASSERT(result);

		if (id == __uuidof(IHen2) ||
			id == __uuidof(IHen) ||
			id == __uuidof(IUnknown))
		{
			*result = static_cast<IHen2 *>(this);
		}
		else if (id == __uuidof(IOfflineChicken))
		{
			*result = static_cast<IOfflineChicken *>(this);
		}
		else
		{
			*result = 0;
			return E_NOINTERFACE;
		}
		static_cast<IUnknown *>(*result)->AddRef();
		return S_OK;
	}
#pragma endregion

#pragma region IHen
	void __stdcall Cluck()
	{
		printf("Cluck\n");
	}

	void __stdcall Roost()
	{
		printf("Zzzzz\n");
	}
#pragma endregion

#pragma region IHen2
	void __stdcall Forage()
	{
		printf("Forage\n");
	}
#pragma endregion

#pragma region IOfflineChicken
	void __stdcall Load(char const * file)
	{

	}

	void __stdcall Save(char const * file)
	{

	}
#pragma endregion
};

HRESULT __stdcall CreateHen(IHen **result)
{
	ASSERT(result);

	*result = new (std::nothrow) Hen;
	if (0 == *result)
	{
		return E_OUTOFMEMORY;
	}
	(*result)->AddRef();
	return S_OK;
}