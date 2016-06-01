#include "stdafx.h"
#include "Library.h"
#include <stdio.h>

struct Hen : IHen2, IOfflineChicken
{
	unsigned int m_count;

	Hen() : m_count(0)
	{
		printf("Cheep\n");
	}

	~Hen()
	{
		printf("Chicken soup\n");
	}

#pragma region IObject
	void __stdcall AddRef()
	{
		++m_count;
	}

	void __stdcall Release()
	{
		if (0 == --m_count)
		{
			delete this;
		}
	}

	void * __stdcall As(char const * type)
	{
		if (0 == strcmp(type, "IHen") ||
			0 == strcmp(type, "IHen2") ||
			0 == strcmp(type, "IObject"))
		{
			AddRef();
			return static_cast<IHen2 *>(this);
		}
		else if (0 == strcmp(type, "IOfflineChicken"))
		{
			AddRef();
			return static_cast<IOfflineChicken *>(this);
		}
		else
		{
			return 0;
		}
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

IHen * __stdcall CreateHen()
{
	IHen * hen =  new Hen;
	hen->AddRef();
	return hen;
}