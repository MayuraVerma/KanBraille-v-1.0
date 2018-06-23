//KanBrail.cpp implemaentation file

#include "stdafx.h"
#include <mmsystem.h>
#include "KanBrail.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "string.h"
#include <io.h>
#include "..\headers\flags.h"
#include "..\headers\keyfuncts.h"
#include "SpeechLib.h"
#include "KeyComb.h"

#include <ctype.h>
#include <windows.h>
#include "vfw.h"
#include <direct.h>
#include "afx.h"

#include <fcntl.h>      /* Needed only for _O_RDWR definition */
#include <stdlib.h>
#include <stdio.h>
#include <share.h>

using namespace std;

#define BUFSIZE MAX_PATH
#define ANUSWARA 0
#define VOWELS 1
#define CONSONANTS 2

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma data_seg(".SHARDAT")
static HWND ghWndMain = 0 ;
static HHOOK ghKeyHook = NULL ;
#pragma data_seg()

static HHOOK ghCallWndProcRetHook = NULL;
int VOICE = 1;

HINSTANCE ghInstance = 0;
HOOKPROC glpfnHookProc = 0;

HWND m_hwnd ;
FILE *fp_log = fopen("log.txt","w");

int iVottaksharas[10] ={ -1 };

void vFind_Kannada_Characters(char ch);
int isPrevious_F(char ch);
void DisplayChar(char ch);
void ClearQueue();
void DisplayCharacters(int nval,int indicator,int j);
void fclose_reopen()
{
	//fclose(fp_log);
	//fp_log = fopen("log.txt","a");
}

void set_voice(int v)
{
	int i=0;
    char Buffer[256];
	char* fullPath ;

	strncpy(Buffer,"c:\\kanBrail",strlen("c:\\kanBrail"));
	Buffer[strlen("c:\\kanBrail")] = '\0';
    fullPath = strncat(Buffer,"\\VoiceConfig.txt",strlen("\\VoiceConfig.txt"));
    

CFile cfile;
CFileException ex;
cfile.Open(fullPath,CFile::modeRead | CFile::shareDenyWrite, &ex);
char pbuf[127];
UINT nBytesRead = cfile.Read( pbuf, 127);
if(pbuf[0] == '0')
			{
					VOICE = 2;
			}
			else
			{
				   VOICE = 1;
			}
}

int get_voice()
{
	return VOICE;
}
BEGIN_MESSAGE_MAP(CKanBrailApp, CWinApp)
//{{AFX_MSG_MAP(CKanBrailApp)
                    // NOTE - the ClassWizard will add and remove mapping macros here.
                    //    DO NOT EDIT what you see in these blocks of generated code!
                    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_KanBrail_v1(int nCode,WPARAM wParam,LPARAM lParam)
{
          set_voice(1);
		  if(nCode<0)												//---Do not process further if a system key is pressed---//
          { 
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam);   //---Call the next hook procedure in the hook chain---//
          }
          
		  if(nCode==HC_NOREMOVE)
          {
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
          }
          
		  char ch;
          BYTE ks[256];                                //---a byte for getting the keyboard ststus---//
          WORD w;										 //---a word for holding the character value of the key---// 
         						 //pressed used by the ToAsccii where the value is set into this---//	
          UINT scan=0; 
		//  ::MessageBox(NULL,"Space","fdvfqq",MB_OK);
		  if(wParam != VK_SHIFT)
		  {
          ::GetKeyboardState(ks);         
          ::ToAscii(wParam,scan,ks,&w,0);
		  ch = char(w);
		  }
		 // if((GetKeyState(VK_SCROLL ) & 0x0001))
         // {
	 //  MessageBox(NULL,"Space","fdvfqq",MB_OK);
			if (((DWORD)lParam & 0x80000000)==0x000000000)  //---If key is pressed and is not a control key---//
			{
				switch (wParam)
				{
				case VK_BACK:
							delete_char(); 
							return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
					break;
				case VK_SPACE:
						if(!spacedchar())
							read_word();
							addKey(32);
						//	PushKeys();
							return TRUE;
					break;
				case VK_SHIFT:
 					return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
					break;
				case VK_RETURN:
					return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
					break;
				default:
							vFind_Kannada_Characters(ch);									//---Find the glyph code--//
							PushBackspaces();
							return TRUE;
				}
			}
			else
			{
			PushKeys();
			return TRUE;
			}
		  //}		
		 // else
       //   return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
}
//------------This-function-is-repeatedly-called-this-executes-when-a-key-is-pressed-on-the-keyboard---/
LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_KanBrail(int nCode,WPARAM wParam,LPARAM lParam)
{
          
	set_voice(1);
		  if(nCode<0)												//---Do not process further if a system key is pressed---//
          { 
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam);   //---Call the next hook procedure in the hook chain---//
          }
          
		  if(nCode==HC_NOREMOVE)
          {
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
          }
          
          UINT scan=0; 
 

		 // short
	
	if (((DWORD)lParam & 0xC0000000)==0x000000000)  //---If key is pressed and is not a control key---//
		{
			//MessageBox(NULL,"fdvbf","gbgf",MB_OK);
			if(wParam == VK_SPACE)
					{
			
							if(!spacedchar())
							read_word();
						//	:://MessageBox(NULL,"Space","fdvfqq",MB_OK);
							addKey(32);
						//	PushKeys();

						//	return TRUE;
					}

			else  if(wParam == VK_BACK)
					{
						// read_word();
						//	:://MessageBox(NULL,"Space","fdvfqq",MB_OK);
						//	AddKey(32);
						//	PushKeys();
					
						delete_char();
							return 0;
						}
			else if(wParam == VK_RETURN)
			{
				return 0;
			}
		}
							if (((DWORD)lParam & 0xC0000000) == 0x000000000)  //---If key is pressed and is not a control key---//
							{
							//			vFind_Kannada_Characters(ch);									//---Find the glyph code--//
                              //          PushBackspaces();
								if(GetAsyncKeyState('F') && 0x8000) 
								{
									f_key = 1;
								}
								if(GetAsyncKeyState('D') && 0x8000 )
								{
									d_key = 1;
								}
								if(GetAsyncKeyState('S') && 0x8000 )
								{
									s_key = 1;
								}
								if(GetAsyncKeyState('J') && 0x8000 )
								{
									j_key = 1;
								}
								if(GetAsyncKeyState('K') && 0x8000 )
								{
									k_key = 1;
								}
								if(GetAsyncKeyState('L') && 0x8000 )
								{
									l_key = 1;
								}

								return TRUE;
							}
							//if (((DWORD)lParam & 0x40000000))
							else
							{
                                setChars(f_key,d_key,s_key,j_key,k_key,l_key);
							//	PushKeys();
								f_key = s_key = d_key = j_key = k_key = l_key= 0;
								return TRUE;
							}
				
      //    return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
}

LRESULT EXPORTED_DLL_FUNCTION callWndRetProc(int nCode,WPARAM wParam,LPARAM lParam)
{
          if(nCode<0)												//---Do not process further if a system key is pressed---//
          { 
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam);   //---Call the next hook procedure in the hook chain---//
          }
          
		  if(nCode==HC_NOREMOVE)
          {
                    return CallNextHookEx (ghKeyHook,nCode,wParam,lParam); 
          }
          
		  char ch;
		  int static l = 0;
          BYTE ks[256];                                //---a byte for getting the keyboard ststus---//
          WORD w;										 //---a word for holding the character value of the key---// 
         						 //pressed used by the ToAsccii where the value is set into this---//	
          UINT scan=0; 
		 
          ::GetKeyboardState(ks);         
          ::ToAscii(wParam,scan,ks,&w,0);
          ch = char(w);

                    CWPRETSTRUCT *p=(CWPRETSTRUCT*)lParam;
       
	if(p->message==WM_KEYDOWN || p->message == WM_CHAR)
	{
		//::MessageBox(NULL,"vfvf","fvbfgbgfv",MB_OK);
		if(p->wParam==VK_SPACE)
		{
			//::MessageBox(NULL,"vfvf","fvfv",MB_OK);
		}
	}
	   

         // }
          LRESULT ret=CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
          return ret;
}


//---------------Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanBrail(HWND hWnd) 
{

		m_hwnd = hWnd;

          BOOL bSuccess = FALSE;
          if( !ghKeyHook) 
          {
                    ghWndMain = hWnd;
                    glpfnHookProc = (HOOKPROC) lSet_KeyBoard_KanBrail;
                    bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
                    bSuccess = TRUE;
                    ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
          }

		return TRUE;
}

//---------------Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanBrail_v1 (HWND hWnd) 
{
          BOOL bSuccess = FALSE;
          if( !ghKeyHook) 
          {
                    ghWndMain = hWnd;
                    glpfnHookProc = (HOOKPROC) lSet_KeyBoard_KanBrail_v1;
                    bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
                    bSuccess = TRUE;
                    ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
          }
          return bSuccess;
}

//---------------Un-Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanBrail()
{
          if(ghKeyHook) 
          {
                    if( TRUE == (0 != ::UnhookWindowsHookEx (ghKeyHook)))
                    {
                              ghKeyHook = NULL;
                    }
          }
          if(ghCallWndProcRetHook) 
          {
                    if( TRUE == (0 != ::UnhookWindowsHookEx (ghCallWndProcRetHook)))
                    {
					ghCallWndProcRetHook = NULL;
          		  }
          }

	//	  :://MessageBox(NULL,"fvdfv","fdv",MB_OK);
          return (NULL == ghKeyHook);
}

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanBrail_v1()
{

	fclose(fp_log);
          if(ghKeyHook) 
          {
                    if( TRUE == (0 != ::UnhookWindowsHookEx (ghKeyHook)))
                    {
                              ghKeyHook = NULL;
                    }
          }
          if(ghCallWndProcRetHook) 
          {
                    if( TRUE == (0 != ::UnhookWindowsHookEx (ghCallWndProcRetHook)))
                    {
					ghCallWndProcRetHook = NULL;
          		  }
          }
	//	  :://MessageBox(NULL,"fvdfv","fdv",MB_OK);
          return (NULL == ghKeyHook);
}


CKanBrailApp::CKanBrailApp()
{
          // TODO: add construction code here,
          // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKanBrailApp object

CKanBrailApp theApp;

BOOL CKanBrailApp::InitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
          AFX_MANAGE_STATE(AfxGetStaticModuleState());
          ghInstance = AfxGetInstanceHandle();
          return TRUE;
}

int CKanBrailApp::ExitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
                    DeInstallKeyboardHook_KanBrail();
                    return CWinApp::ExitInstance();
}

BOOL CKanBrailApp::PreTranslateMessage(MSG* pMsg) 
{
          // TODO: Add your specialized code here and/or call the base class
          return CWinApp::PreTranslateMessage(pMsg);
}

void addKey(int c)
{
	
	::PostMessage(GetActiveWindowHandel(),WM_CHAR,c,1);
//	AddKey(c);
	text_to_read[read_index++] = getBig(c);
	return ;
}

void addKey_v2(int c)
{
	
	//::PostMessage(GetActiveWindowHandel(),WM_CHAR,c,1);
	AddKey(c);
	text_to_read[read_index++] = getBig(c);
	if(c != '@')
	kFlag.previous_0 = (char)c;	

	return ;
}

int get_string_length(char str[127])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{

	}
		return i;
}
void read_word()
{
	int i=0;
    int j = -1;
	int k=0;
	int len = 0;
	char tempVfilePath[255];

	text_to_read[read_index] = '\0';

	len = get_string_length(text_to_read);

  
	FILE *fp2;


	char Buffer[256];
	char* fullPath ;

	strncpy(Buffer,"c:\\kanBrail",strlen("c:\\kanBrail"));
	Buffer[strlen("c:\\kanBrail")] = '\0';
    fullPath = strncat(Buffer,"\\KBTLog.txt",strlen("\\KBTLog.txt"));
 
    fp2 = fopen(fullPath,"a");

 	setVoiceFolder();

 	while(k < len)
			{
                  j = -1;
                  j = compstr(text_to_read,k);
                  if(j>=0 && j<NO_OF_KEY_COMP)
                   {    
					   k = k+ get_string_length(data[j].disp_chars); //if( get_string_length(data[j].disp_chars)>=1 ?get_string_length(data[j].disp_chars):0 ); //change the k to point to current buffer 
				
					if(VOICE == 1)
					{
 								strcpy(tempVfilePath,"");
 								strcpy(tempVfilePath,voiceFilePath);
								strcat(tempVfilePath,"\\");
 								::PlaySound(strcat(tempVfilePath,data[j].m_v_file),NULL,SND_SYNC);
 								fprintf(fp2,"%d  %s\n",j,tempVfilePath);
					}
					else
					if(VOICE == 2)
					{
 							strcpy(tempVfilePath,"");
							strcpy(tempVfilePath,voiceFilePath);
							strcat(tempVfilePath,"\\");
 							::PlaySound(strcat(tempVfilePath,data[j].f_v_file),NULL,SND_SYNC);
							fprintf(fp2,"%d  %s\n",j,tempVfilePath);
					}
					  j = -1;
                   }
                   else
                   {
                       k++;
                   }
            }
	
	fclose(fp2);

    int txtLen = get_string_length(text_to_read);

	for(i =0;i<=txtLen;i++)
	{
		text_to_read[i] = '\0';
	}

 read_index = 0;
}

void delete_char()
{
	text_to_read[--read_index] = '\0';
}

int compsubstr(char var[11],char buffer[127],int len,int k)
{
    int i;
	int no_chars_substr = 0;
     for (i=0;i<len;i++)
     {
                    if(var[i]!=buffer[k+i])
                    return 0;
					counter++;
					++no_chars_substr;
     }
	 if(get_string_length(var) != no_chars_substr)
		 return -1;

     return 1;
}


int compstr(char buffer[127],int k)
{
    int i;
    for (i= 0;i<NO_OF_KEY_COMP;i++)
    { 
        int j = 0;
        j = compsubstr(data[i].disp_chars,buffer,get_string_length(data[i].disp_chars),k);
        if(j == 1)
        {
			//fprintf(fp_log,"d");
			//fclose_reopen();
			return i;
        }
    }
    return -1;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setChars(int f,int d,int s,int j,int k,int l)
{
if (f == 1 && d == 1 && s == 1 && j ==1 && k == 1 && l == 1)
{
addKey(61);
//::PlaySound("D:\\Braillie1\\output\\61.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j ==1 && k == 1 && l == 1)
{
addKey(41);
//::PlaySound("D:\\Braillie1\\output\\41.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j ==1 && k == 1 && l == 1)
{
addKey(89);
//::PlaySound("D:\\Braillie1\\output\\89.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 1 && j ==1 && k == 0 && l == 1)////changes sha
{
addKey(38);
//::PlaySound("D:\\Braillie1\\output\\38.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 1 && j == 1 &&  k == 1 && l == 0)
{
addKey(81);
//::PlaySound("D:\\Braillie1\\output\\81.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 0 &&  k == 1 && l == 1)
{
addKey(124);///124
//::PlaySound("D:\\Braillie1\\output\\124.WAV", NULL, SND_ASYNC);
}
else
/*if (f == 1 && d == 1 && s == 0 && j == 1 &&  k == 0 && l == 1)
{
addKey(36);///124
}
else*/
if (f == 1 && d == 0 && s == 1 && j == 1 &&  k == 0 && l == 1)
{
addKey(88);
//::PlaySound("D:\\Braillie1\\output\\88.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 1 &&  k == 1 && l == 0)
{
addKey(71);
//::PlaySound("D:\\Braillie1\\output\\71.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 1 &&  k == 1 && l == 1)
{
addKey(87);
//::PlaySound("D:\\Braillie1\\output\\87.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 1 &&  k == 0 && l == 1)
{
addKey(36);
//::PlaySound("D:\\Braillie1\\output\\36.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 1 &&  k == 1 && l == 1)
{
addKey(35);
//::PlaySound("D:\\Braillie1\\output\\35.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 1 &&  k == 1 && l == 0)
{
addKey(84);
//::PlaySound("D:\\Braillie1\\output\\84.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 1 &&  k == 1 && l == 1)
{
addKey(63);
//::PlaySound("D:\\Braillie1\\output\\63.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 1 &&  k == 0 && l == 1)
{
addKey(33);
//::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 0 &&  k == 1 && l == 1)
{
addKey(55);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j == 1 &&  k == 1 && l == 0)
{
addKey(78);
//::PlaySound("D:\\Braillie1\\output\\78.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 1 && j ==1 && k == 0 && l == 0)
{
addKey(80);
//::PlaySound("D:\\Braillie1\\output\\80.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1&& s == 1 && j == 0 && k == 1 && l == 0) 
{
addKey(82);
if(raw == TRUE)
{
	raw = 0;
//::PlaySound("D:\\Braillie1\\output\\34+82.WAV", NULL, SND_ASYNC);
}
//else
//::PlaySound("D:\\Braillie1\\output\\82.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 1 && j == 0 &&  k == 0 && l == 1)
{
addKey(86);
//::PlaySound("D:\\Braillie1\\output\\86.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 1 &&  k == 1 && l == 0)
{
addKey(62);
//::PlaySound("D:\\Braillie1\\output\\62.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j == 0 &&  k == 0 && l == 1)
{
addKey(85);
//::PlaySound("D:\\Braillie1\\output\\85.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j == 0 &&  k == 1 && l == 0)
{
addKey(79);
//::PlaySound("D:\\Braillie1\\output\\79.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 1 &&  k == 0 && l == 1)
{
addKey(91);
//::PlaySound("D:\\Braillie1\\output\\91.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 0 &&  k == 0 && l == 1)
{
addKey(60);
//::PlaySound("D:\\Braillie1\\output\\60.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 1 &&  k == 0 && l == 1)
{
addKey(43);
//::PlaySound("D:\\Braillie1\\output\\43.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 1 &&  k == 1 && l == 0)
{
addKey(74);
//::PlaySound("D:\\Braillie1\\output\\74.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 0 &&  k == 1 && l == 1)
{
addKey(48);
//::PlaySound("D:\\Braillie1\\output\\48.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 1 &&  k == 1 && l == 0)
{
addKey(68);
//::PlaySound("D:\\Braillie1\\output\\68.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 0 &&  k == 1 && l == 0)
{
addKey(54);
//::PlaySound("D:\\Braillie1\\output\\54.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 0 &&  k == 1 && l == 1)
{
addKey(52);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 0 &&  k == 0 && l == 1)
{
addKey(56);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 1 &&  k == 0 && l == 0)
{
addKey(70);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j == 1 &&  k == 0 && l == 0)
{
addKey(77);
//::PlaySound("D:\\Braillie1\\output\\77.WAV", NULL, SND_ASYNC);
}
else

if (f == 1 && d == 1 && s == 1 && j == 0 &&  k == 0 && l == 0)
{
addKey(76);
//::PlaySound("D:\\Braillie1\\output\\76.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 1 &&  k == 0 && l == 1)
{
addKey(37);
//::PlaySound("D:\\Braillie1\\output\\37.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 1 &&  k == 0 && l == 0)
{
addKey(83);
//::PlaySound("D:\\Braillie1\\output\\83.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 0 &&  k == 1 && l == 0)
{
addKey(72);
//::PlaySound("D:\\Braillie1\\output\\72.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 1 &&  k == 1 && l == 1)
{
addKey(95);
//::PlaySound("D:\\Braillie1\\output\\95.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 0 &&  k == 1 && l == 1)
{
addKey(58);
//::PlaySound("D:\\Braillie1\\output\\58.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 0 &&  k == 1 && l == 1)
{
addKey(59);
//::PlaySound("D:\\Braillie1\\output\\59.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 1 &&  k == 0 && l == 0)
{
addKey(73);
//::PlaySound("D:\\Braillie1\\output\\73.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 0 &&  k == 0 && l == 1)
{
addKey(45);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 1 && j == 0 &&  k == 0 && l == 0)
{
addKey(50);
////::PlaySound("D:\\Braillie1\\output\\33.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 0 &&  k == 1 && l == 0)
{
addKey(57);
//::PlaySound("D:\\Braillie1\\output\\57.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 0 &&  k == 0 && l == 1)
{
addKey(53);
//::PlaySound("D:\\Braillie1\\output\\53.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 0 &&  k == 1 && l == 0)
{
addKey(69);
//::PlaySound("D:\\Braillie1\\output\\69.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 1 &&  k == 0 && l == 0)
{
addKey(47);
//::PlaySound("D:\\Braillie1\\output\\47.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 1 && j == 0 &&  k == 0 && l == 0)
{
addKey(75);
//::PlaySound("D:\\Braillie1\\output\\75.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 1 &&  k == 0 && l == 1)
{
addKey(46);
//::PlaySound("D:\\Braillie1\\output\\46.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 1 &&  k == 0 && l == 0)
{
addKey(67);
//::PlaySound("D:\\Braillie1\\output\\67.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 0 &&  k == 0 && l == 1)
{
addKey(42);
//::PlaySound("D:\\Braillie1\\output\\42.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 0 &&  k == 1 && l == 0)
{
addKey(51);
//::PlaySound("D:\\Braillie1\\output\\51.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 1 && s == 0 && j == 0 &&  k == 0 && l == 0)
{
addKey(66);
//::PlaySound("D:\\Braillie1\\output\\66.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 1 &&  k == 1 && l == 0)
{
addKey(94);
//::PlaySound("D:\\Braillie1\\output\\94.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 0 &&  k == 0 && l == 1)
{
addKey(44);
//::PlaySound("D:\\Braillie1\\output\\44.WAV", NULL, SND_ASYNC);
}
else
if (f == 1 && d == 0 && s == 0 && j == 0 &&  k == 0 && l == 0)
{
addKey(65);
//::PlaySound("D:\\Braillie1\\output\\65.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 1 && s == 0 && j == 0 &&  k == 0 && l == 0)
{
addKey(49);
//::PlaySound("D:\\Braillie1\\output\\Dot-2.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 1 && j == 0 &&  k == 0 && l == 0)
{
addKey(39);
//::PlaySound("D:\\Braillie1\\output\\Dot-3.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 1 &&  k == 0 && l == 0)
{
addKey(64);
//::PlaySound("D:\\Braillie1\\output\\Dot-4.WAV", NULL, SND_ASYNC);
}
else
if (f == 0 && d == 0 && s == 0 && j == 0 &&  k == 1 && l == 0)
{
addKey(34);
//::PlaySound("D:\\Braillie1\\output\\Dot-5.WAV", NULL, SND_ASYNC);
//PlayResource("58.WAV");
raw = 1;
}
return ;

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// This Function Post the message for the ACTIVE window of the Specified Character  in "ch"  ////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--- ch ===>character ---//

void CopyPrevious(char ch)
{   
	kFlag.previous_1 = kFlag.previous_0;
	kFlag.previous_0 = ch;
}



void DisplayQueue()
{
	int i = 0;
	while(iVottaksharas[i]!=-1)
	{
			  AddKey(iVottaksharas[i]);
			  i++;
	}
}


void ClearQueue()
{
	for (int i=0;i<=10;i++)
	iVottaksharas[i] = -1;
	kFlag.o_count = 0;
	kFlag.o_bit  = 1;
	kFlag.so_bit = 1;
}


void DisplayChar(char ch)
{
	for(int i=0;i<=34;i++)
	if(ch == consonants[i].key)
	AddKey((WPARAM)consonants[i].k_val);
}

int isPrevious_F(char ch)
{
	f2 = f1;
	f1 = ch;
	if(ch == 'f' && f2 == 'f')
	{
		kFlag.c_bit = 0;
		return 1;
	}
	else
		return 0;
}


int spacedchar()
{
	int i = 0;

    int retval = 0;

	for(i =0;i<SPACED_CHARS;i++)
	{
		retval = compsubstr(before_space[i].l_w_space,text_to_read,get_string_length(before_space[i].l_w_space));
		if(retval)
		{
		//	::MessageBox(NULL,"FV","fdvf",MB_OK);
			return 1;
		}
	}

	for(i =0;i<1;i++)
	{
		retval = compsubstr(after_space[i].l_w_space,text_to_read,get_string_length(after_space[i].l_w_space));
		if(retval)
			return 1;
	}

	for(i =0;i<1;i++)
	{
		retval = compsubstr(space_on_either[i].l_w_space,text_to_read,get_string_length(space_on_either[i].l_w_space));
		if(retval)
			return 1;
	}

return retval;

}


int compsubstr(char var[11],char buffer[127],int len)
{
    int i;
	int j = 0;
	for(i=len-1;i>=0;i--)
	{
		if(var[i]!=buffer[read_index-1-j])
		return 0;

		j++;
		}
     return 1;
}


void vFind_Kannada_Characters(char ch) 
{       
          //	HWND  myWnd;  //---------Window Handel---//
          
          int no_bs = kFlag.o_count;//-------number of back spae--------//
          int glp_pos = 0; //---Glyph position ----//
		  int i = 0;
          kFlag.found = FALSE;
                    
		  switch(ch)
          {
                case 'f':
					  	kFlag.f_bit = 1;
						kFlag.found  = 1;
						delete_char();					
						AddKey(8);
						addKey_v2('@');
						addKey_v2((int)kFlag.previous_0);
					/*for(i=0;i<=34;i++)
                    if(kFlag.previous_0==consonants[i].key)		// ---search the structure for the key pressed
                    {         
						      kFlag.found = 1;
							  DisplayCharacters(i,CONSONANTS,0) ;	
					}
					*/
				break;
		  }
          for(i=0;i<=4;i++)
		  {
		    if(ch==anuswaranvisarga[i].key)
			  {   
						kFlag.found = TRUE;							//----if found then set the bit 
						DisplayCharacters(i,ANUSWARA,0);		//---Display --Glyphs from 0-----
																//---if previos is consonant then reset the bit;
			  }
		  }
        
          	 			  
		  if(!kFlag.found)	
			{
                  
			  for(i=0;i<=14;i++)
			  if(ch == vowels[i].key)		// ---search the structure for the key pressed
			   { 
                              kFlag.found = 1;
							DisplayCharacters(i,VOWELS,0) ;
			  }

                      
			 }//----------------------End Of vowels ------------------//
          //------if found == 0 for vowels-----end------------//
          if(kFlag.found==0)
          {
                    for(i=0;i<=34;i++)
                    if(ch==consonants[i].key)		// ---search the structure for the key pressed
                    {         
						      kFlag.found = 1;
							  DisplayCharacters(i,CONSONANTS,0) ;	
					}
          kFlag.n_back = -1;
		  }

		  if(isspace(ch))
		  kFlag.c_bit = 0 ;
		  
		  if(!(isalpha(ch))&&!(GetKeyState(VK_SHIFT))||isspace(ch))
		  {
          ClearQueue();
          kFlag.f_bit = 0;
	//	  kFlag.f_pressed_Once = 0;
		  }

//if(isalpha(ch)&&(ch!='f')&&(ch!='X')&&!(kFlag.o_bit))
//CopyPrevious(ch);
return ;
}


void DisplayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    

int k = j ;   // --------index for glyph codes---// 

	if(indicator==0)	
	{
          
			  addKey_v2(anuswaranvisarga[nval].k_val[0]);
			  kFlag.n_back = -1;
	}
	else
	if(indicator==1)	
	{
			  while(vowels[nval].k_val[k]!=-1)
			  {
						addKey_v2(vowels[nval].k_val[k]);
						k++;
			  }
	}
	else
	if(indicator == 2)
	{
			  while(consonants[nval].k_val[k]!=-1)
			  {
					    addKey_v2(consonants[nval].k_val[k]);
						k++;
			  }
	}
}

char getBig(char c)
{
	int i = 0;

	for(i=0;i<11;i++)
	{
		if(c == all_chars[i].key)
			return all_chars[i].value;
	}
	return c;
}


void setVoiceFolder()
{

 /*   char Buffer[256];
	char* fullPath ;

	strncpy(Buffer,"c:\\kanBrail",strlen("c:\\kanBrail"));
	Buffer[strlen("c:\\kanBrail")] = '\0';
    fullPath = strncat(Buffer,"\\VoiceFolder.txt",strlen("\\VoiceFolder.txt"));


CFile cfile;
CFileException ex;
cfile.Open(fullPath,CFile::modeRead | CFile::shareDenyWrite, &ex);
char pbuf[127] = {" "};
UINT nBytesRead = cfile.Read(pbuf,127);
*/
//strncpy(voiceFilePath,(const char *)pbuf,get_string_length(pbuf));

strncpy(voiceFilePath,"c:\\kanBrail",strlen("c:\\kanBrail"));

voiceFilePath[get_string_length(voiceFilePath)] = '\0';
}


char* getVoiceFolder()
{
	return voiceFilePath;
}



BOOL EXPORTED_DLL_FUNCTION setVoiceFilePath(char *path)
{

//	::MessageBox(NULL,"rtgtg","thrh",MB_OK);

   FILE *fp;
  // TCHAR Buffer[BUFSIZE];
  


   //GetSystemDirectory(Buffer,BUFSIZE);
   //strcat(Buffer,"\\VoiceFolder.txt");

    char Buffer[256];
	char* fullPath ;

	strncpy(Buffer,"c:\\kanBrail",strlen("c:\\kanBrail"));
	Buffer[strlen("c:\\kanBrail")] = '\0';
    fullPath = strncat(Buffer,"\\VoiceFolder.txt",strlen("\\VoiceFolder.txt"));


   
   fp = fopen(fullPath,"w");
 
strncpy(voiceFilePath,"c:\\kanbrail\\",get_string_length(path));

voiceFilePath[get_string_length(voiceFilePath)] = '\0';
fprintf(fp,"%s",voiceFilePath);

fclose(fp);
 return TRUE;
}