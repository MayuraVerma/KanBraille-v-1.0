
#include <vector>
#include <windows.h>
//#include "..\headers\flags.h"

std::vector<int> g_keystoadd;

HWND GetActiveWindowHandel();

void AddKey(int ch)
{
          g_keystoadd.push_back(ch);
		  
}


void PushSpaces()
{
          HWND hWnd;
          hWnd =  GetActiveWindowHandel();
          do
          {
                    if((g_keystoadd.size()>0) && (g_keystoadd[0]==32))
                    {
                              ::PostMessage(hWnd,WM_KEYDOWN,(WPARAM)VK_SPACE,(LPARAM)((0x0e<<16)|1));
                              ::PostMessage(hWnd,WM_KEYUP,(WPARAM)VK_SPACE,(LPARAM)((0x0e<<16)|1|(1<<31)));
                              g_keystoadd.erase(g_keystoadd.begin());
					}
                    else
                    break;
		  } 
		  while (g_keystoadd.size()>0);
}

void PushBackspaces()
{
          HWND hWnd;
          hWnd =  GetActiveWindowHandel();
          do
          {
                    if((g_keystoadd.size()>0) && (g_keystoadd[0]==8))
                    {
                              ::PostMessage(hWnd,WM_KEYDOWN,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1));
                              ::PostMessage(hWnd,WM_KEYUP,(WPARAM)VK_BACK,(LPARAM)((0x0e<<16)|1|(1<<31)));
                              g_keystoadd.erase(g_keystoadd.begin());
					}
                    else
                    break;
		  } 
		  while (g_keystoadd.size()>0);
}


void PushKeys()
{
          if(g_keystoadd.size()==0)
          return;
          HWND hWnd;
          hWnd =  GetActiveWindowHandel();
          while(g_keystoadd.size()>0)
          {
                    //::PostMessageA(hWnd,WM_CHAR,(WPARAM)g_keystoadd[0],(LPARAM)1);
						//	  ::PostMessage(hWnd,WM_KEYDOWN,NULL,(LPARAM)1);
							  ::PostMessageA(hWnd,WM_CHAR,(WPARAM)g_keystoadd[0],(LPARAM)1);
                         //     ::PostMessage(hWnd,WM_KEYUP,NULL,(LPARAM)1);
                    g_keystoadd.erase(g_keystoadd.begin());
		  }
}



void DisplaySingleCharacter(int fval) 
{
AddKey(fval);
}


void DisplayDoubleCharacter(int fval,int sval) 
{
AddKey(fval);
AddKey(sval);
}


void DisplayTripleCharacter(int fval,int sval,int tval) 
{
AddKey(fval);
AddKey(sval);
AddKey(tval);
}


void DisplayFourCharacter(int fval,int sval,int tval,int fhval) 
{
AddKey(fval);
AddKey(sval);
AddKey(tval);
AddKey(fhval);
}



void SendBackSpace(int back)
{
		while(back>=1)
		{
          AddKey(VK_BACK);
          back--;
		}
}


HWND GetActiveWindowHandel()
{
	HWND  hWnd;  //---------Window Handel---//
	hWnd  = GetFocus ();
	
	if (hWnd == NULL)
	
	hWnd = GetForegroundWindow ();
	return hWnd;
}

void SendSpace(int s)
{
while(s-->=1)
	{
          AddKey((WPARAM)246);
    }
}


HWND GetActiveForegroundWindow()
{
	HWND m_FrgWindow;

	m_FrgWindow = GetFocus();

	if(m_FrgWindow == NULL)
		m_FrgWindow = (HWND)GetForegroundWindow();

	return m_FrgWindow;
}