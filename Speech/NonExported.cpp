#include "stdafx.h"
#include "NonExported.h"


int Validate()
{
	return TRUE;
}


int Play(HWND hwnd,long time)
{
	if(Validate())
	{
		MCIWndPlay(hwnd);
	    Sleep(MCIWndGetLength(hwnd));
		return TRUE;
	}
	else
		return FALSE;
}