#include "stdafx.h"
#include "netravathi.h"
#include "..\headers\flags.h"
#include "..\headers\keyfuncts.h"
#include <ctype.h>
#include <windows.h>

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

HINSTANCE ghInstance = 0;
HOOKPROC glpfnHookProc = 0;

int iVottaksharas[10] ={ -1 };

void vFind_Kannada_Characters(char ch);
int isPrevious_F(char ch);
void DisplayChar(char ch);
void ClearQueue();
void DisplayCharacters(int nval,int indicator,int j);

//---Structure of anuswara and visarga----//
struct anv_tab
{
          char key;								//----holds the character 
          int k_val[3];							//---holds the glyph codes of the corresponding above character eg; 
          //---for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}anuswaranvisarga[5] = { 
						  '\\', {-1,-1}, 	
						  'M', {59,-1, } ,
						  'H', {44,-1, } ,
						  'F', {240,-1,} ,
						  ' ', {32 , -1}
						};


//---Structure of vowles ----//
struct val_tab
{
          char key;								//----holds the character 
          int k_val[11];							//---holds the glyph codes of the corresponding above character eg;  
          //---for a 67 (first 1 values)for vowel and consonants (last value)
}vowels[16] =   { 'a', { 65, -1,} ,
				  'A', { 62, -1,} ,
				  'i', { 73, -1,} ,
				  'I', { 57, -1,} ,
				  'u', { 85, -1,} ,
				  'U', { 124, -1,} ,
				  'e', { 53, -1,} ,
				  'E', { 69, -1,} ,
				  'Y', { 47, -1,} ,
				  'o', { 88, -1,} ,
				  'O', { 79, -1,} ,
				  'V', { 91, -1,} ,
                };

//---Structure of consonants ----//
struct con_tab
{
          char key;								//----holds the character 
          int k_val[7];							//---holds the glyph codes of the corresponding above character eg; 
          //---- for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}consonants[35] = {	'k', { 75, -1,} ,	//---Kannada Character kA---//
					'K', { 46, -1,} ,	//---Kannada Character Kha---//
					'g', { 71, -1,} ,	//---Kannada Character ga---//
					'G', { 60, -1,} ,	//---Kannada Character Gha---//
					'Z', { 43, -1,} ,	//---Kannada Character IJNA---//
					'c', { 67, -1,} ,	//---Kannada Character cA---//
					'C', { 42, -1,} ,	//---Kannada Character Cha---//
					'j', { 74, -1,} ,	//---Kannada Character ja---//
					'J', { 48, -1,} ,	//---Kannada Character Jha---//
					'z', { 51, -1,} ,	//---Kannada Character INYA---//
					'q', { 41, -1,} ,	//---Kannada Character tA---//
					'Q', { 87, -1,} ,	//---Kannada Character TA---//
					'w', { 36, -1,} ,	//---Kannada Character da---//
					'W', { 61, -1,} ,	//---Kannada Character Dha---//
					'N', { 35, -1,} ,	//---Kannada Character Na---//
					't', { 84, -1,} ,	//---Kannada Character tha---//
					'T', { 63, -1,} ,	//---Kannada Character Tha---//
					'd', { 68, -1,} ,	//---Kannada Character da---//
					'D', { 33, -1,} ,	//---Kannada Character Da---//
					'n', { 78, -1,} ,	//---Kannada Character na---//
					'p', { 80, -1,} ,	//---Kannada Character pa---//
					'P', { 54, -1,} ,	//---Kannada Character Pa---//
					'b', { 66, -1,} ,	//---Kannada Character ba---//
					'B', { 94, -1,} ,	//---Kannada Character Bha---//
					'm', { 77, -1,} ,	//---Kannada Character ma---//
					'y', { 89, -1,} ,	//---Kannada Character ya---//
					'r', { 82, -1,} ,	//---Kannada Character ra---//
					'l', { 76, -1,} ,	//---Kannada Character la---//
					'v', { 86, -1,} ,	//---Kannada Character va---//
					'S', { 37, -1,} ,	//---Kannada Character sha---//
					'x', { 38, -1,} ,	//---Kannada Character Sha---//
					's', { 83, -1,} ,	//---Kannada Character sa---//
					'h', { 72, -1,} ,	//---Kannada Character ha---//
					'L', { 95, -1,} ,	//---Kannada Character la---//
				};  


BEGIN_MESSAGE_MAP(CNetravathiApp, CWinApp)
//{{AFX_MSG_MAP(CNetravathiApp)
                    // NOTE - the ClassWizard will add and remove mapping macros here.
                    //    DO NOT EDIT what you see in these blocks of generated code!
                    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------This-function-is-repeatedly-called-this-executes-when-a-key-is-pressed-on-the-keyboard---/
LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_Netravathi1(int nCode,WPARAM wParam,LPARAM lParam)
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
          BYTE ks[256];                                //---a byte for getting the keyboard ststus---//
          WORD w;										 //---a word for holding the character value of the key---// 
         						 //pressed used by the ToAsccii where the value is set into this---//	
          UINT scan=0; 
		 
          ::GetKeyboardState(ks);         
          ::ToAscii(wParam,scan,ks,&w,0);
          ch = char(w);
         
		  
		  if((GetKeyState(VK_SCROLL ) & 0x0001))
          {
                if(ispunct(ch) || isdigit(ch) || (wParam == VK_SPACE) || (wParam == VK_BACK ))
                {
					vClear_All_Flags();
					//Sleep(5000);
	      		}
                 
			    if( isalpha(ch)||wParam == VK_SPACE)   //---If key is pressed and is not a control key---//
					{                        
							if (((DWORD)lParam & 0x80000000)==0x000000000)  //---If key is pressed and is not a control key---//
							{
										vFind_Kannada_Characters(ch);									//---Find the glyph code--//
                                        PushBackspaces();
							}
							else 
							{
                                        PushKeys();
                                        return TRUE;
							}
					}
                else
                    {
							  if(wParam != VK_SHIFT)
							  vClear_All_Flags();

                              return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
					}
                    
			 	if((isalpha(ch)||wParam == VK_SPACE)&&!(GetKeyState(VK_MENU) & 0x80))    //---If the key pressed is a alpha key and when not
				{                                                  //---- Alt is down posts only the the promted message--//
                              return TRUE;
                }
				else
                return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
                              //---Call the next hook procedure in the hook chain---//
		
		  }	
		  else
          return CallNextHookEx(ghKeyHook,nCode,wParam,lParam); 
}




LRESULT EXPORTED_DLL_FUNCTION callWndRetProc(int nCode,WPARAM wParam,LPARAM lParam)
{
          if(nCode<0)
          {
                    return CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
          }
                    CWPRETSTRUCT *p=(CWPRETSTRUCT*)lParam;
          if(p->message==WM_KEYDOWN)
          {
                    if(p->wParam==VK_BACK)
                    {
                              PushKeys();
                    }
          }
          LRESULT ret=CallNextHookEx(ghCallWndProcRetHook,nCode,wParam,lParam);
          return ret;
}


//---------------Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_Netravathi (HWND hWnd) 
{
          BOOL bSuccess = FALSE;
          if( !ghKeyHook) 
          {
                    ghWndMain = hWnd;
                    glpfnHookProc = (HOOKPROC) lSet_KeyBoard_Netravathi1;
                    bSuccess = (NULL != ( ghKeyHook = ::SetWindowsHookEx (WH_KEYBOARD, glpfnHookProc,ghInstance, NULL)));
                    bSuccess = TRUE;
                    ghCallWndProcRetHook = ::SetWindowsHookEx (WH_CALLWNDPROCRET, (HOOKPROC)callWndRetProc,ghInstance, NULL);
          }
          return bSuccess;
}


//---------------Un-Insatalls-the-Hook---//---This-is -called-by-the-.exe---//
BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_Netravathi()
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
          return (NULL == ghKeyHook);
}


CNetravathiApp::CNetravathiApp()
{
          // TODO: add construction code here,
          // Place all significant initialization in InitInstance
}


/////////////////////////////////////////////////////////////////////////////
// The one and only CNetravathiApp object

CNetravathiApp theApp;

BOOL CNetravathiApp::InitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
          AFX_MANAGE_STATE(AfxGetStaticModuleState());
          ghInstance = AfxGetInstanceHandle();
          return TRUE;
          }
int CNetravathiApp::ExitInstance() 
{
          // TODO: Add your specialized code here and/or call the base class
                    DeInstallKeyboardHook_Netravathi();
                    return CWinApp::ExitInstance();
}


BOOL CNetravathiApp::PreTranslateMessage(MSG* pMsg) 
{
          // TODO: Add your specialized code here and/or call the base class
          return CWinApp::PreTranslateMessage(pMsg);
}

void DisplayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    

int k = j ;   // --------index for glyph codes---// 

	if(indicator==0)	
	{
          
			  AddKey(anuswaranvisarga[nval].k_val[0]);
			  kFlag.n_back = -1;
	}
	else
	if(indicator==1)	
	{
			  while(vowels[nval].k_val[k]!=-1)
			  {
						AddKey(vowels[nval].k_val[k]);
						k++;
			  }
	}
	else
	if(indicator == 2)
	{
			  while(consonants[nval].k_val[k]!=-1)
			  {
						AddKey(consonants[nval].k_val[k]);
						k++;
			  }
	}
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
						DisplaySingleCharacter(8);
						DisplaySingleCharacter('@');
					for(i=0;i<=34;i++)
                    if(kFlag.previous_0==consonants[i].key)		// ---search the structure for the key pressed
                    {         
						      kFlag.found = 1;
							  DisplayCharacters(i,CONSONANTS,0) ;	
					}

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

if(isalpha(ch)&&(ch!='f')&&(ch!='X')&&!(kFlag.o_bit))
CopyPrevious(ch);
return ;
}