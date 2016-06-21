// Win32App.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Library.h"
#include <crtdbg.h>

#define ASSERT _ASSERT

template<typename T>
class RemoveAddRefRelease : public T
{
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
};

template<typename T>
class ComPtr
{
	T *m_ptr;

public:
	ComPtr() : m_ptr(0) {}

	~ComPtr()
	{
		if (m_ptr)
		{
			m_ptr->Release();
		}
	}

	RemoveAddRefRelease<T> *operator ->() const
	{
		ASSERT(m_ptr);
		return static_cast<RemoveAddRefRelease<T> *>(m_ptr);
	}

	T ** GetAddressOf()
	{
		ASSERT(!m_ptr);
		return &m_ptr;
	}
};

int main()
{
	//IHen *hen;
	ComPtr<IHen> hen;
	//if (S_OK != CreateHen(&hen))
	if (S_OK != CreateHen(hen.GetAddressOf()))
	{
		return 0;
	}
	hen->Cluck();

	//IHen2 * hen2;
	ComPtr<IHen2> hen2;
	//if (S_OK == hen->QueryInterface(&hen2))
	if (S_OK == hen->QueryInterface(hen2.GetAddressOf()))
	{
		hen2->Forage();
	}

	//IOfflineChicken * offline;
	ComPtr<IOfflineChicken> offline;
	//if (S_OK == hen->QueryInterface(&offline))
	if (S_OK == hen->QueryInterface(offline.GetAddressOf()))
	{
		offline->Save("filename");
	}
}

