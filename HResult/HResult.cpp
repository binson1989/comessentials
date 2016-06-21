// HResult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>

struct ComException
{
	HRESULT error;

	ComException(HRESULT const hr) : error(hr){}
};

inline void HR(HRESULT hr)
{
	if (S_OK != hr)
	{
		throw ComException(hr);
	}
}

int main()
{
	HRESULT hr = S_OK;

	if (S_OK == hr)
	{
		printf("Success\n");
	}
	else
	{
		printf("Failure\n");
	}
	return 0;
}

