#include <vector>
//#include <windows.h>
//#include "..\headers\flags.h"

#define ANUSWARA 0
#define VOWELS 1
#define CONSONANTS 2


void DisplaySingleCharacter(int sval) ;
void DisplayDoubleCharacter(int fval,int sval);
void DisplayTripleCharacter(int fval,int sval,int tval) ;
void DisplayFourCharacter(int fval,int sval,int tval,int fhval) ;
void DisplayQueue();
void SendSpace(int);
void ClearQueue();
//HWND GetActiveWindowHandel();
void SendBackSpace(int back);
void DisplayCharacter_phi(char ch,int i);
void DisplayCharacters_jPwX(char ch,int i);
void DisplayChar(char ch);
void Set_for_fbit(char ch,int i);
void Last_Glyph(WPARAM last_glyph);
void Copy_Char(char ch);
void vSetGlyphs_for_jmy(char ch,int i);
void vSetGlyphs_Ka_Ja_Ba(char ch , int gval,int i);
void DisplayCharacters(int nval,int v_bit,int j) ;
void DisplayCharacters_f(char ch) ;
void DisplayGunisu(char ch) ;
void DisplayCharacters_a(int nval,int v_bit,int j) ;
void vFind_Kannada_Characters (char ch) ;
void CopyPrevious(char ch);
void CopyOnePrevious1(char ch);
void ClearOnePrevious1();
void ClearPrevious();
void MyCopyPrevious(char ch);
void MyClearPrevious();
void OurCopyPrevious(char ch);
void OurClearPrevious();
void CopyOne(char ch);
void ClearOne();
int isPrevious_F(char ch);
char get_kan(char ch);
char copy_f(char ch);
int isSecondf(char ch);

char f1,f2;

char f_1,f_2;


char get_kan(char ch)
{
	switch(ch)
	{

case 'A':	return 'a'; break;
case '>':	return 'A'; break;
case 'I':	return 'i'; break;
case '9':	return 'I'; break;
case 'U':	return 'u'; break;
case '|':	return 'U'; break;
//case 'R':	return 'R'; break;
case '5':	return 'e'; break;
case 'E':	return 'E'; break;
case '/':	return 'Y'; break;
case 'X':	return 'o'; break;
case 'O':	return 'O'; break;
case '[':	return 'V'; break;
case ';':	return 'M'; break;
case ',':	return 'H'; break;
case 'K':	return 'k'; break;
case '.':	return 'K'; break;
case 'G':	return 'g'; break;
case '<':	return 'G'; break;
case '+':	return 'x'; break;
case 'C':	return 'c'; break;
case '*':	return 'C'; break;
case 'J':	return 'j'; break;
case '0':	return 'J'; break;
case '3':	return 'Z'; break;
case ')':	return 'q'; break;
case 'W':	return 'Q'; break;
case '$':	return 'w'; break;
case '=':	return 'W'; break;
case '#':	return 'N'; break;
case 'T':	return 't'; break;
case '?':	return 'T'; break;
case 'D':	return 'd'; break;
case '!':	return 'D'; break;
case 'N':	return 'n'; break;
case 'P':	return 'p'; break;
case '6':	return 'P'; break;
case 'B':	return 'b'; break;
case '^':	return 'B'; break;
case 'M':	return 'm'; break;
case 'Y':	return 'y'; break;
case 'R':	return 'r'; break;
case 'L':	return 'l'; break;
case 'V':	return 'v'; break;
case '%':	return 'S'; break;
case '&':	return 'x'; break;
case 'S':	return 's'; break;
case 'H':	return 'h'; break;
case '_':	return 'L'; break;
case '@':   return 'f'; break;
default:
	return ch;
	}
}

struct kFlags
{
int n_back ;
int found;
int q_bit;

int f_bit ;
int s_bit ;
int p_bit ;

int g_bit ;
int c_bit ;
int o_bit ;

int x_bit ;
int so_bit ;
int b_bit;

int u_bit  ;
int ei_bit ;
int ipressed ;

int space_bit ;
int j_bit ;
int first_o ;

int derg_bit ;
int	derg_count ;
int spec_kgun ;

int spec_kgun_val;
int slash_bit ;
int i_flag ;

char previous_0 ;
char previous_1 ;
char previous_2 ;
char previous_3 ;

char last_consonant;
WPARAM lastglyph ;
int save_i;

int o_count ;
int y_bit  ;
int f_pressed_Once;
int ff_bit;

}kFlag = {
			-1,
			 0,
			 0,

			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 0,
			 0,
			 0,
			 
			 1,
			 0 ,
			 0,
			 
			 0,
			 0,
			 0,

			 NULL,
			 NULL,
			 NULL,
			 
			 NULL,
			 NULL,
			 0,

			 0,
			 0,
			 0
	
};


void vClear_All_Flags()
{
				              kFlag.q_bit  = 0;
                              kFlag.f_bit = 0;
                              kFlag.s_bit = 0;
                              kFlag.p_bit = 0;
                              kFlag.g_bit = 0;
                              kFlag.c_bit = 0;
                              kFlag.o_bit = 0;
                              kFlag.x_bit = 0;
                              kFlag.so_bit = 0;
                              kFlag.b_bit = 0;
                              kFlag.u_bit  = 0;
                              kFlag.ei_bit = 0;
                              kFlag.ipressed = 0;
                              kFlag.space_bit = 0;
                              kFlag.j_bit = 0;
                              kFlag.first_o = 0;
//                            kFlag.derg_bit = 1;
//                            kFlag.derg_count ;
                              kFlag.spec_kgun = 0;
                              kFlag.spec_kgun_val;
                              kFlag.slash_bit = 0;
							  kFlag.f_pressed_Once = 0;
                              ClearQueue();
		
}

int iVottaksharas[10] ={ -1 };

std::vector<int> g_keystoadd;

char buffer[256] = {'\0'};
static int buffer_index = 0;
FILE *fp ;


void flush(char *file_name)
{
  fp = fopen(file_name,"a");

  fprintf(fp,"%s",buffer);
  
  fclose(fp);

  //buffer_index = 0;
  while(buffer_index >=0)
  {
	  buffer[--buffer_index] ='\0';
  }
  buffer_index = 0;
}

void AddKey(int ch)
{
	if(ch == 8 || ch == VK_BACK)
		buffer[--buffer_index] = '\0';
	else
          buffer[buffer_index++] = ch;
}


void PushBackspaces()
{
      // buffer[--buffer_index] = '\0';
}


void PushKeys()
{
	
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
          buffer[--buffer_index] = '\0';
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
                 buffer[buffer_index++] = ' ';
    }
}

int isnumpad(WPARAM wParam)
{
	if(wParam == VK_SUBTRACT  ||
       wParam == VK_NUMPAD0   ||
	   wParam == VK_NUMPAD1   ||
	   wParam == VK_NUMPAD2   ||
	   wParam == VK_NUMPAD3   ||
	   wParam == VK_NUMPAD4   ||
	   wParam == VK_NUMPAD5   ||
	   wParam == VK_NUMPAD6   ||
	   wParam == VK_NUMPAD7   ||
	   wParam == VK_NUMPAD8   ||
	   wParam == VK_NUMPAD9   ||
	   wParam == VK_DIVIDE    ||
	   wParam == VK_ADD       ||
	   wParam == VK_MULTIPLY  ||
	   wParam == VK_DECIMAL   )
	{
		
		return 1;
	}
	else
		return 0;
}

//---Structure of anuswara and visarga----//
struct anv_tab
{
          char key;								//----holds the character 
          int k_val[3];							//---holds the glyph codes of the corresponding above character eg; 
          //---for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}anuswaranvisarga[5] = { 
						  '\\', {-1,-1}, 	
						  'M', {65,-1,-1 } ,
						  'H', {66,-1,-1 } ,
						  'F', {240,-1,-1} ,
						  ' ', {32 , -1}
						};


//---Structure of vowles ----//
struct val_tab
{
          char key;								//----holds the character 
          int k_val[11];							//---holds the glyph codes of the corresponding above character eg;  
          //---for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}vowels[16] =   { 'a', { 67, -1,-1,-1,-1,-1,-1,- 1,-1,-1} ,        
				  'A', { 68, -1,-1,193,-1 ,-1,-1,-1,-1 } ,
				  'i', { 69, -1,-1, -1,-1 ,-1,-1,-1,-1 } ,
				  'I', { 70, -1,-1, -1,-1 ,-1,-1,-1 ,-1} ,
				  'u', { 71, -1,-1,196,-1 ,-1,-1,197 ,-1} , 
				  'U', { 72, -1,-1,198,-1,-1,-1,199 ,-1} ,
				  'R', { 73,196,-1,200 ,-1,-1,-1,-1,-1} ,
				  'e', { 74, -1,-1,201,-1 ,-1,-1,-1 ,-1} ,
				  'E', { 75, -1,-1,201,195 ,-1,-1 ,-1} ,
				  'Y', { 76, -1,-1,201,202,-1,-1  ,-1} ,
				  'o', { 77, -1,-1,201,198 ,-1,-1 ,201,199,-1} ,
				  'O', { 78, -1,-1,201,198 ,195,-1,201,199,195,-1} ,
				  'V', { 79, -1,-1,203,-1,-1,-1,-1 ,-1} ,
				  'X', { 251, -1}
                };



//---Structure of consonants ----//
struct con_tab
{
          char key;								//----holds the character 
          int k_val[7];							//---holds the glyph codes of the corresponding above character eg; 
          //---- for a 67 (first 3 values)for vowel and 192 for consonants (last value)
}consonants[35] = {   'k', {80,192,-1,-1,-1,204 ,-1} ,            //---Kannada Character ka---//
					  'K', {82,-1,-1,-1,-1,205 ,-1} ,			//---Kannada Character Kha---//	
					  'g', {85,192,-1,-1,-1,206 ,-1} ,			//---Kannada Character ga---//	
					  'G', {87,192,-1,-1,-1,207,-1 } ,			//---Kannada Character Gha---//
					  'Z', {89,-1,-1,-1,-1,208,-1 } ,		    //---Kannada Character nya---//
					  'c', {90,192,-1,-1,-1,209 ,-1} ,			//---Kannada Character cha---//	
					  'C', {98,192,-1,-1,-1,210 ,-1} ,		    //---Kannada Character CHA---//
					  'j', {100,-1,-1,-1,-1,211,-1 } ,			//---Kannada Character ja---//	
					  'J', {103,192,104,196,-1,212,-1 } ,	    //---Kannada Character Jha---//  
					  'z', {107,-1,-1,-1,-1,213 ,-1} ,			//---Kannada Character Inya---//	
					  'q', {108,-1,-1,-1,-1,214 ,-1} ,			//---Kannada Character Ta---//
					  'Q', {111,192,-1,-1,-1,215 ,-1} ,			//---Kannada Character TA---//
					  'w', {113,192,-1,-1,-1,216,-1 } ,			//---Kannada Character dha---//
					  'W', {113,115,192,-1,-1,217 ,-1} ,		//---Kannada Character DHA---//
					  'N', {116,-1,-1,-1,-1,218,-1 } ,			//---Kannada Character NA---//
					  't', {118,192,-1,-1,-1,219 ,-1} ,			//---Kannada Character tha---//
					  'T', {120,192,-1,-1,-1,220 ,-1} ,			//---Kannada Character THA---//
					  'd', {122,192,-1,-1,-1,221 ,-1} ,			//---Kannada Character da---//
					  'D', {122,115,192,-1,-1,222,-1 } ,		//---Kannada Character DA---//
					  'n', {163,192,-1,-1,-1,223 ,-1} ,			//---Kannada Character na---//
					  'p', {165,192,-1,-1,-1,224,-1} ,			//---Kannada Character pa---//
					  'P', {165,115,192,-1,-1,225 ,-1} ,		//---Kannada Character PHA---//
					  'b', {167,-1,-1,-1,-1,226 ,-1} ,			//---Kannada Character ba---//
					  'B', {168,115,192,-1,-1,227,-1 } ,		//---Kannada Character BHA---//
					  'm', {170,192,196,-1,-1,228 ,-1} ,		//---Kannada Character Ma---//	
					  'y', {65,105,192,196,-1,229,-1 } ,        //---Kannada Character Ya---//
					  'r', {103,192,-1,-1,-1,230,-1} ,		    //---Kannada Character ra---//
					  'l', {174,-1,-1,-1,-1,232 ,-1} ,			//---Kannada Character la---// 	
					  'v', {170,192,-1,-1,-1,233 ,-1} ,			//---Kannada Character va---//
					  'S', {177,192,-1,-1,-1,234 ,-1} ,			//---Kannada Character SHA---//
					  'x', {181,192,-1,-1,-1,235 ,-1} ,			//---Kannada Character sha---//
					  's', {184,192,-1,-1,-1,236 ,-1} ,			//---Kannada Character sa---//
					  'h', {186,192,-1,-1,-1,237 ,-1} ,			//---Kannada Character ha---//
					  'L', {188,192,-1,-1,-1,238 ,-1} ,			//---Kannada Character LA---//
				};  


///---------------Structure for guntakshara---------------///
struct guni_tab
{
          char key;								//----holds the character 
          int k_val[4];							//---holds the glyph codes of the corresponding above character 
          //----eg;  for a 67 (first 3 values)for vowel and 192 for consonants (last value)
          }gunisu[35] = {     'k', {81,-1,-1,-1} ,          //---Kannada Character ki---//
							  'K', {84,-1,-1,-1} ,			//---Kannada Character Khi---//	
							  'g', {86,-1,-1,-1} ,			//---Kannada Character gi---//	
							  'G', {88,-1,-1,-1} ,			//---Kannada Character Ghi---//
							  'Z', {89,194,-1,-1} ,		    //---Kannada Character nyi---//
							  'c', {97,-1,-1,-1} ,			//---Kannada Character chi---//	
							  'C', {99,-1,-1,-1} ,		    //---Kannada Character CHi---//
							  'j', {102,-1,-1,-1} ,			//---Kannada Character ji---//	
							  'J', {106,104,196,-1} ,	    //---Kannada Character Jhi---//  
							  'z', {107,194,-1,-1} ,		//---Kannada Character Inyi---//	
							  'q', {110,-1,-1,-1} ,			//---Kannada Character Ti---//
							  'Q', {112,-1,-1,-1} ,			//---Kannada Character Ti---//
							  'w', {114,-1,-1,} ,			//---Kannada Character dhi---//
							  'W', {114,252,-1,-1} ,		//---Kannada Character DHi---//
							  'N', {116,194,-1,-1} ,		//---Kannada Character Ni---//
							  't', {119,-1,-1,-1} ,			//---Kannada Character thi---//
							  'T', {121,-1,-1,-1} ,			//---Kannada Character THi---//
							  'd', {162,-1,-1,-1} ,			//---Kannada Character di---//
							  'D', {162,252,-1,-1} ,		//---Kannada Character Di---//
							  'n', {164,-1,-1,-1} ,			//---Kannada Character ni---//
							  'p', {166,-1,-1,-1} ,			//---Kannada Character pi---//
							  'P', {166,252,-1,-1} ,		//---Kannada Character PHi---//
							  'b', {169,-1,-1,-1} ,			//---Kannada Character bi---//
							  'B', {169,252,-1,-1 } ,		//---Kannada Character BHi---//
							  'm', {171,196,-1,-1} ,		//---Kannada Character Mi---//	
							  'y', {172,196,-1,196} ,       //---Kannada Character Yi---//
							  'r', {106,-1,-1,-1} ,		    //---Kannada Character ri---//
							  'l', {176,-1,-1,-1} ,			//---Kannada Character li---// 	
							  'v', {171,-1,-1,-1} ,			//---Kannada Character vi---//
							  'S', {178,-1,-1,-1} ,			//---Kannada Character SHi---//
							  'x', {182,-1,-1,-1} ,			//---Kannada Character shi---//
							  's', {185,-1,-1,-1} ,			//---Kannada Character si---//
							  'h', {187,-1,-1,-1} ,			//---Kannada Character hi---//
							  'L', {189,-1,-1,-1} ,			//---Kannada Character Li---//
						};  


		  
void vProcess_Guntaksharas(int ch,int no_bs,int i,int glp_pos)
{
								  switch(ch)
                                      {	
                                                  case 'a':
                                                  kFlag.n_back = -1;
                                                  break;
                                                  case  'u' :
                                                  case  'U' :
                                                  case  'R' :
                                                  kFlag.n_back = -1;
												  break;

                                                  default :
                                                  kFlag.n_back = 1;
                                        }//-------------End of Switch------------//
                                                                                                                        
										if(kFlag.o_bit == 1)
                                        {
                                                  SendBackSpace(no_bs);
                                        }
                                        /////////////////////////////////////////////////////
                                                                                                                        
										if(ch == 'R')
                                        {

                                                  if(kFlag.o_bit == 1)  //-----------If an Ottakshara has to be processed-----------//
                                                  {
                                                            DisplayQueue();
                                                            ClearQueue();
                                                            kFlag.o_bit = 0;
                                                            vowels[i].k_val[3] = 248;
                                                            DisplayCharacters(i,VOWELS,3);
                                        
												  }//------------EnD of o_bit  == 1---------//
                                                  else
                                                  {
                                                            kFlag.s_bit = 1;
                                                            vowels[i].k_val[3] = 200;
															DisplayCharacters(i,VOWELS,3);
												  }
                                                  
										}//----------------End of if(ch == R)-----------------//
                                        else
                                        if(ch == 'i')                   //---If an i is pressed after a consonant---//
                                        {   
                                                  kFlag.n_back = -1;
                                                  DisplayGunisu(ch);
										}
                                        else
                                        if(ch == 'I')                   //---If an i is pressed after a consonant---//
                                        {   
                                                  kFlag.n_back = -1;
                                                  DisplayGunisu(ch);
										}
                                        else
                                        switch (kFlag.previous_0)   
                                        {
                                                  case 'Z' :
                                                  case 'z' :
                                                  kFlag.n_back = -1;
                                                  DisplayCharacters(i,VOWELS,3) ;
                                                  break ;
                                        
												  case 'b' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,167,i);					//This function sets the glyph 
                                                  break;
                                                  
												  case 'K' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,82,i);					//This function sets the glyph 
                                                  break;
                                                  
												  case 'j' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,100,i);
                                                  break;
                                                  
												  case 'q' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,108,i);
                                                  break;
                                                  
												  case 'N' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,116,i);
                                                  break;

                                                  case 'l' :
                                                  vSetGlyphs_Ka_Ja_Ba(ch,174,i);
                                                  break;
                                                  case 'J' :					//----For the characters ya ,ma,Jha,---//
                                                  case 'm' :
                                                  //---ch the character and i the position in the vowles tab
                                                  
												  vSetGlyphs_for_jmy(ch,i);
                                                  break;
                                                  
												  case 'y' :
                                                  vSetGlyphs_for_jmy(ch,i);
                                                  break;
                                                  
												  default :	
                                                  //---For all other characters---//
                                                  glp_pos = 3;
                                                  switch(kFlag.previous_0)  //---------For Characters hu,vu,pu,Pu-------//
                                                  {
                                                            case 'p':
                                                            case 'P':
                                                            case 'v':
                                                            case 'h':
                                                            if(ch=='u'||ch=='U'||ch=='o'||ch=='O')
                                                            glp_pos = 7;
                                                            else
                                                            glp_pos = 3;
                                                  }
        
												  if(kFlag.x_bit == 1)
                                                  {
                                                            if(kFlag.previous_0 == 'P')
                                                            DisplayCharacter_phi(ch,i);
                                                            kFlag.x_bit = 0 ;
												  }
                                                  if(ch ==  'E' || ch == 'O') //for displaying the ottakshara beforf the Deerga
                                                  {
															if(ch == 'O')
                                                            switch(kFlag.previous_0)  //---------For Characters hu,vu,pu,Pu-------//
                                                            {
                                                                      case 'p':
                                                                      case 'P':
                                                                      case 'v':
                                                                      case 'h':
                                                                      glp_pos = 7;
																	  //MessageBox(NULL,"fvbg","bgfb",MB_OK);
															}

                                                            if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                                                            {
                                                                      DisplayCharacters(i-1,VOWELS,glp_pos) ;	
                                                                      DisplayQueue();
                                                                      ClearQueue();
                                                                      kFlag.o_bit = 0;
                                                                      kFlag.c_bit = 0;									 //------------inserted --------now 
                                                                      DisplaySingleCharacter(195);
															} 
                                                            else
                                                            DisplayCharacters(i,VOWELS,glp_pos) ;	
												  }
                                                 else	
                                                  if(ch == 'Y')
                                                  {
                                                            DisplayDoubleCharacter(VK_BACK,201) ;	
                                                            if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                                                            {
                                                                      DisplayQueue();
                                                                      ClearQueue();
																	  DisplaySingleCharacter(246);
                                                                      kFlag.o_bit = 0;
                                                                      kFlag.c_bit = 0;
																	  kFlag.o_count = 0;//------------inserted --------now 
																	  kFlag.n_back = -1;
															} 
                                                            DisplaySingleCharacter(202) ;	
												  }
                                                  else	
                                                  DisplayCharacters(i,VOWELS,glp_pos) ;		    //---Display --Glyphs from 3----//
                                                  ///----------pevious_0 value put to next line of c_bit
                                                  }
                                        kFlag.c_bit = 0;									///-------------Changed from last 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void vFind_Kannada_Characters(char ch) 
{       
          //	HWND  myWnd;  //---------Window Handel---//
          
          int no_bs = kFlag.o_count;//-------number of back spae--------//
          int glp_pos = 0; //---Glyph position ----//
		  int i = 0;
          kFlag.found = FALSE;
                
		  copy_f(ch);
		  
		  switch(ch)
          {
                case 'f':
               // if(kFlag.c_bit == 1)
               // {
					kFlag.ff_bit = 1;
			   //}
               // return;     
			    break ;
				default:
					isPrevious_F(ch);
				//	return;
				break;
		   }


          for(i=0;i<=4;i++)
		  {
		    if(ch==anuswaranvisarga[i].key)
			  {   
						kFlag.found = TRUE;							//----if found then set the bit 
																//---so no comparision in the further loops
						kFlag.c_bit = 0;  
						if(kFlag.previous_0 == 'E' && kFlag.previous_1 == 'd'&& ch == 'F')
						{
								  SendBackSpace(1);
								  DisplayDoubleCharacter(240,195);
               			}
						else
						DisplayCharacters(i,ANUSWARA,0) ;		//---Display --Glyphs from 0-----
																//---if previos is consonant then reset the bit;
			  }
		  }
        

		 			  
		  if(!kFlag.found)	
			{
                    if(ch == 'X')			//---if an X is press after the keys  P and j this displays ".." and return no further processing---//
					{
							switch(kFlag.previous_0)
							{
									  case 'P':
		                              case 'j':
                                        kFlag.x_bit = 1;
                                        DisplayCharacters(13,VOWELS,0);
                    					return ;
                                        //break;
                    
							  }  
							return;
					}//------End of Switch(previous_0)----------//
			  //	else
			  for(i=0;i<=14;i++)
			  if(ch == vowels[i].key)		// ---search the structure for the key pressed
			   { 
                              kFlag.found = 1;

                              if(kFlag.c_bit == 1)							//--- if pevious_0 character is a consonant
                              { 
								  vProcess_Guntaksharas( ch, no_bs, i, glp_pos);
								  kFlag.n_back = -1;
                              }
							  else                              //---Displays ordinary Vowels---//
							  {
											if((kFlag.previous_0 == 'R')&&(kFlag.x_bit  == 1))
											{
													  if(kFlag.s_bit == 1) //--------To Display RX followed by a consonant ie;
													  {
																SendBackSpace(1);
																DisplaySingleCharacter(241);
																kFlag.s_bit = 0; 
																kFlag.x_bit = 0;
													  }//-----------End of s_bit == 1------------//
													  else
													  {
																kFlag.x_bit = 0;
																SendBackSpace(2);
																DisplaySingleCharacter(73) ;
																DisplaySingleCharacter(198) ;
													  }//-----------End of else ------------//
											}//----------End of previous_0-////-------End of if x_bit == 1 --------//
											else
											{
													  kFlag.n_back = 0;	
													  DisplayCharacters(i,VOWELS,0) ;
													  kFlag.c_bit = 0;                                  //---if Found display corresponding glyphs
											}//----------End Of Else--------//
								}


                              if(kFlag.o_bit)                        //---If an f f_bit was set ---//
                              {
                                        DisplayQueue();
                                        ClearQueue();
                                        kFlag.o_bit = 0;
                                        kFlag.c_bit = 0;									 //------------inserted --------now 
							  } 
			  }
		  }//----------------------End Of vowels ------------------//
          //------if found == 0 for vowels-----end------------//
          if(kFlag.found==0)
          {
                    for(i=0;i<=34;i++)
                    if(ch==consonants[i].key)		// ---search the structure for the key pressed
                    {         
						      kFlag.found = 1;
                              kFlag.c_bit = 1;
                              
						  if(kFlag.f_bit == 1)
                          {   
                                        SendBackSpace(no_bs);//------------for deleting previous ---and displaying --required glyphs
                                        Set_for_fbit(ch,i); 
                                        kFlag.f_bit = 0 ;
                                        switch(ch)
                                        {
                                                  case 'r':
                                                  if(kFlag.so_bit == 1)
                                                  {
                                                      kFlag.so_bit = 0;	
                                                      consonants[i].k_val[5] = 231;								  
												  }
                                                  else
                                                  consonants[i].k_val[5] = 230;
                                                  break;
                                                  default:
													  if(kFlag.so_bit)				//---------inserted at 1.48 p m now ---------//
													  {
														  kFlag.so_bit = 0;
														  iVottaksharas[kFlag.o_count++] = 246;		//---------inserted at 1.48 p m now ---------//
													  }
                                        //--------end of switch------------//
										}											

								  iVottaksharas[kFlag.o_count++] = consonants[i].k_val[5];
								  kFlag.o_bit  = 1;
								  kFlag.so_bit = 1;
								  DisplayQueue();
						  } 
						  else
							{
									  ClearQueue();    //---Clear the _Vottaksharas no-procesing further---//
									  kFlag.o_bit =  0;      //---Clear the bit so no-procesing further---//
									  DisplayCharacters(i,CONSONANTS,0) ;	//---if Found display corresponding glyphs
							}
					}
          kFlag.n_back = -1;
		  }

		  if(kFlag.ff_bit == 1 && kFlag.c_bit == 1)
		  {
			  	//	if(isPrevious_F(kFlag.previous_0))
					//	kFlag.ff_bit = 0;
				//	else
				//	  	kFlag.ff_bit = 1;


				if((kFlag.o_bit== 1)&&kFlag.c_bit == 1 )
                    {   
                              kFlag.so_bit = 1;
							  kFlag.f_bit = 1;
                              //SendBackSpace(no_bs);
                              //DisplayCharacters_f(ch) ;
                              //DisplayQueue();
						//	  ::MessageBox(NULL,"oc","oc",1);
					}
                    
		        else
                  if(kFlag.c_bit == 1)
				  {
                             // DisplayCharacters_f(ch) ;
                              kFlag.c_bit = 0;
                              kFlag.so_bit = 0;    
							  kFlag.f_bit = 1;
							 // ::MessageBox(NULL,"c","c",1);
				  }
				
					kFlag.ff_bit = 0;

		  }

		  if(isspace(ch))
		  kFlag.c_bit = 0 ;
		  
		  if(!(isalpha(ch))&&!(GetKeyState(VK_SHIFT))||isspace(ch))
		  {
          ClearQueue();
          kFlag.f_bit = 0;
		  kFlag.f_pressed_Once = 0;
		  }

if(isalpha(ch)&&(ch!='f')&&(ch!='X')&&!(kFlag.o_bit))
CopyPrevious(ch);
return ;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Finds The Character in The Tables in Found Calls     /////////////////////////////
/////////////////////////////  The Display Functions With Position (i),and The Starting Position  /////////////////////////////
/////////////////////////////  Of The Of The Message To Be Posted The Argument 					  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayCharacters(int nval,int indicator,int j)   //indictor value is 0 for anuswara ,1 for vowels , 2 for consonants
{    

int k = j ;   // --------index for glyph codes---// 

while(kFlag.n_back>=1)
	{
          
			  AddKey(VK_BACK);
			  kFlag.n_back--;
	}
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
kFlag.n_back = -1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// This Function Post the message for the ACTIVE window of the Specified Character  in "ch"  ////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--- ch ===>character ---//
struct chars_for_f
{
	char ch;
	int iVal[4];
}Chars_After_F[11] = {  'z' , {239 , -1 },
						'Z', {239,-1 },
						'K', {8,83,239,-1},
						'j', {8,101,239,-1},
						'J', {8,105,239,-1},
						'y', {8,105,239,-1},
						'm', {8,105,239,-1},
						'q', {8,109,239,-1},
						'b', {8,168,239,-1},
						'l', {8,175,239,-1},
						'N', {8,117,239,-1},
					};

void DisplayCharacters_f(char ch)  //-----While f is pressed
{    

int i = 0 ;
int j = 0 ;   // --------index for glyph codes---// 
int found = FALSE;

	for(j=0;j<11;j++)
	{
		if(ch/*kFlag.previous_0*/ == Chars_After_F[j].ch)
		{
			found = TRUE;
			while(Chars_After_F[j].iVal[i]!=-1) 
			{
				AddKey(Chars_After_F[j].iVal[i]);
				i++;
			}
		}
	}

	if(!found)
	{
		AddKey(8);
		AddKey(239);
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Set The Glypha For Kha,ja,.... ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ch ===>character , gval ===> pevious_0 GlypH value//


void vSetGlyphs_Ka_Ja_Ba(char ch,int gval,int i)
{

kFlag.n_back = -1;
switch (ch)
{

          case 'a' :
          return ;
          case 'A' :
          case 'e' :
          case 'o' :
          case 'V' :
			  if(kFlag.x_bit == 1)
			  {
				  SendBackSpace(1);
			  }
			  SendBackSpace(1);
			  DisplaySingleCharacter(gval+1);
			  if(kFlag.x_bit ==1)
			  {
			  DisplaySingleCharacter(243);
			  kFlag.x_bit = 0;
			  }
			  DisplayCharacters(i,VOWELS,3) ;
          break;
		  
		  case 'u':
		  case 'U':
		  DisplayCharacters(i,VOWELS,3);
          break;

		  case 'Y' :
          if(kFlag.x_bit == 1)
		     SendBackSpace(1);
        
		  SendBackSpace(1);
          
          DisplaySingleCharacter(gval+1);
          if(kFlag.x_bit ==1)
          {
		  DisplaySingleCharacter(243);
          kFlag.x_bit = 0;
		  }
		  DisplaySingleCharacter(201) ;	
          if(kFlag.o_bit)                           //---If an f f_bit was set ---//
          {
           
			        DisplayQueue();
					DisplaySingleCharacter(246);
                    ClearQueue();
                    kFlag.o_bit = 0;
                    kFlag.c_bit = 0;									 //------------inserted --------now 
		  } 
          DisplaySingleCharacter(202) ;	
          break;

          
          case 'E':
          case 'O':
          if(kFlag.x_bit == 1)
          SendBackSpace(1);

          SendBackSpace(1);
                    DisplaySingleCharacter(gval+1);
                    if(kFlag.x_bit ==1)
          DisplaySingleCharacter(243);
          
		  if(kFlag.x_bit == 1)
			kFlag.x_bit = 0;
          
		  if(kFlag.o_bit)                           //---If an f f_bit was set ---//
          {
                    DisplayCharacters(i-1,VOWELS,3) ;	
                    DisplayQueue();
                    ClearQueue();
                    kFlag.o_bit = 0;
                    kFlag.c_bit = 0;									 //------------inserted --------now 
                    DisplaySingleCharacter(195);
		  } 
          else
          DisplayCharacters(i,VOWELS,3) ;	
          break;
                    
		  default :
          break; 
          }
kFlag.n_back = -1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function Set The Glypha For ma,JHa,ya.... ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ch ===>character , gval ===> pevious_0 GlypH value//


void vSetGlyphs_for_jmy(char ch,int i)
{

switch(kFlag.previous_0)
{
          case 'y' :				//-----------For The Characters ya,ma-----------//
          case 'm' :
          switch(ch)
          {
                    case 'A' :
                    case 'V' :
                    DisplayDoubleCharacter(VK_BACK,105);
                    if(ch == 'A')
                    DisplaySingleCharacter(193);
                    else
                    DisplaySingleCharacter(203);
                    break;
                    
                    case 'u':
                    case 'U':
                    DisplayCharacters(i,1,3) ;
                    break;
                    
					case 'e' :
                    SendBackSpace(2);
                    DisplayDoubleCharacter(201,196);
                    break;
                                        
					case 'E' :
                    case 'Y' :
                    SendBackSpace(2);
                    DisplayDoubleCharacter(201,196);
                    
					if(ch == 'E')
                    {
                              if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                              {
								        DisplayQueue();
                                        ClearQueue();
                                        kFlag.o_bit = 0;
                                        kFlag.c_bit = 0;									 //------------inserted --------now 
							  } 
                              DisplaySingleCharacter(195);
					}
					else 
					if(ch == 'Y')
					{
                              if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                              {
								  
								        DisplayQueue();
										DisplaySingleCharacter(246);
                                        ClearQueue();
                                        kFlag.o_bit = 0;
                                        kFlag.c_bit = 0;									 //------------inserted --------now 
                              } 
                        DisplaySingleCharacter(202) ;	
                    }

                    break;
                    
                    case 'o' :
                    SendBackSpace(2);
                    DisplayDoubleCharacter(201,198);
                    break ;
          
										
			        case  'O' :
                    SendBackSpace(2);
                    if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                    {
                              DisplaySingleCharacter(198);
                              DisplayCharacters(i-1,VOWELS,3) ;	
                              DisplayQueue();
                              ClearQueue();
                              kFlag.o_bit = 0;
                              kFlag.c_bit = 0;									 //------------inserted --------now 
                              DisplaySingleCharacter(195);
                              } 
                    else
                                        
					DisplayTripleCharacter(201,198,195);
                    break;
                    }//---------End of Switch(ch)--for the characters ma,ya ------//
          break; //---------------End of the case y , m instance 1
          

		  case 'J' :				//-----------For The Characters JHA-----------//
		  switch(ch)
          {
                    case 'A' :
                    case 'V' :
						DisplayDoubleCharacter(VK_BACK,105);
						if(ch == 'A')
							DisplaySingleCharacter(193);
						else
							DisplaySingleCharacter(203);
					break;
                    
					case 'u':
                    case 'U':
                    DisplayCharacters(i,1,3) ;
                    break;
                    
					case 'e' :
                    SendBackSpace(3);
                    DisplayTripleCharacter(201,104,196);
                    break;
 
					case 'E' :
                    case 'Y' :
                    SendBackSpace(3);
					DisplayTripleCharacter(201,104,196);
                    if(ch == 'E')
                    {
						      if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                              {
                                        DisplayQueue();
                                        ClearQueue();
                                        kFlag.o_bit = 0;
                                        kFlag.c_bit = 0;									 //------------inserted --------now 
                               } 
                          DisplaySingleCharacter(195);
                     }
                    else 
                    if(ch == 'Y')
                    {
                              if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                              {
                                                                                
								        DisplayQueue();
										DisplaySingleCharacter(246);
                                        ClearQueue();
                                        kFlag.o_bit = 0;
                                        kFlag.c_bit = 0;									 //------------inserted --------now 
							  } 
                              DisplaySingleCharacter(202) ;	
					}
                    break;
                    
					case 'o' :
                    SendBackSpace(3);
                    DisplayTripleCharacter(201,104,198);
                    break ;
                    
					case  'O' :
                    SendBackSpace(3);
                    if(kFlag.o_bit)                           //---If an f f_bit was set ---//
                    {
                              DisplaySingleCharacter(201);
                              DisplayDoubleCharacter(104,198);
                              DisplayQueue();
                              ClearQueue();
                              kFlag.o_bit = 0;
                              kFlag.c_bit = 0;									 //------------inserted --------now 
                              DisplaySingleCharacter(195);
					} 
                    else
                         DisplayFourCharacter(201,104,198,195);
                    break;
                    }//-------------------End of Switch(ch)----for JHA ---------------//
                    break ;
          }//---------End of Switch(pevious_0)--------//
kFlag.n_back = -1;
}//-------End OF The function vSetGlyphs_for_jmy----------//


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// This Function Displays GuniSu for of the previosly entered character /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void DisplayGunisu(char ch)
{

int position = 0;
int k = 0;
char char_1 = kFlag.previous_0;

for(int i=0;i<=34;i++)
if(char_1== consonants[i].key)		// ---search the structure//for the key pressed 
{
          position = i;			

}
switch(char_1)
{

          case 'z' :				//---for these characters display 
          //---the corresponding Gunisu ---//
          case 'Z' :
          case 'N' :
          //	::PostMessage(myWnd,WM_CHAR,194,(LPARAM)1);
          DisplaySingleCharacter(194);
          break;

          case 'K':				//---for these characters send a single 
          //---back space and display the corresponding Gunisu---//
          case 'j':
          if(kFlag.x_bit == 1)
          DisplaySingleCharacter(VK_BACK);
          /*------common back space-----*/
          DisplaySingleCharacter(VK_BACK);
          
		  while(gunisu[position].k_val[k]!=-1)
          {
                    AddKey(gunisu[position].k_val[k]);
                    k++;
          }
          if(kFlag.x_bit == 1)
          {
                    DisplaySingleCharacter(251);
                    kFlag.x_bit = 0; 
          }
          break ;
          
		  case 'P':
          if(kFlag.x_bit == 1)
          SendBackSpace(1);

          SendBackSpace(3);
          DisplayDoubleCharacter(166,252);
          if(kFlag.x_bit == 1)
          {
                    DisplaySingleCharacter(251);
                    kFlag.x_bit = 0; 
		  }
          break;
          
		  case 'q':
          case 'b':
          case 'l':
          //::PostMessage(myWnd,WM_CHAR,VK_BACK,(LPARAM)1);
		  SendBackSpace(1);
          while(gunisu[position].k_val[k]!=-1)
          {
                    AddKey(gunisu[position].k_val[k]);
                   k++;
          }
          break;
 
		  case 'D' :
          SendBackSpace(3);
          DisplayDoubleCharacter(162,252);
          break;
          
		  case 'W' :
          SendBackSpace(3);
          DisplayDoubleCharacter(114,252);
          break;
          
		  case 'B' :
          case 'm' :	
          //---for these characters send a triple back 
          //---space and display the corresponding Gunisu---//
          SendBackSpace(3);
          while(gunisu[position].k_val[k]!=-1)
          {
                    AddKey(gunisu[position].k_val[k]);
                    k++;
          }
          break;
                    case 'J':		//---for these characters send a four back space 
          
						
						//---and display the corresponding Gunisu---//
          case 'y':
          SendBackSpace(4);
          while(gunisu[position].k_val[k]!=-1)
          {
                    AddKey(gunisu[position].k_val[k]);
                    k++;
          }
          break;
          case 'd':
          SendBackSpace(2);
          while(gunisu[position].k_val[k]!=-1)
          {
                    AddKey(gunisu[position].k_val[k]);
                    k++;
          }
          break;

          default :		//---for these characters send a double 
          //---back space and display the corresponding Gunisu---//
          SendBackSpace(2);//-----------replaced by 2 vk_back meassages-----------// 
          while(gunisu[position].k_val[k]!=-1)
          {
                    
                    AddKey(gunisu[position].k_val[k]);
                    k++;
		  }     
	}
	if(ch == 'I')
	{
          if(kFlag.o_bit)                        //---If an f f_bit was set ---//
          {
                    DisplayQueue();
                    ClearQueue();
                    kFlag.o_bit = 0;
                    kFlag.c_bit = 0;									 //------------inserted --------now 
		  } 
                    DisplaySingleCharacter(195);
	}
kFlag.n_back = -1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  This Function copies the character the in ch ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Set_for_fbit(char ch,int i)  //--------The Position i ,ch the character ---//
{

	int j = 0 ;
	switch(kFlag.previous_0)
	{
			  case 'K' :
			  case 'Z' :
			  case 'j' :
			  case 'z' :
			  case 'q' :
			  case 'N' :
			  case 'b' :
			  case 'l' :
			  kFlag.n_back = 2;
			  for(j=0;j<=34;j++)
			  if(kFlag.previous_0==consonants[j].key)
			  {
						DisplayCharacters(j,CONSONANTS,0);
			  }
			  break;

			  case 'J' :
			  case 'y' :
			  kFlag.n_back = 5;
			  for(j=0;j<=34;j++)
			  if(kFlag.previous_0==consonants[j].key)
			  {
						DisplayCharacters(j,CONSONANTS,0);
			  }
			  break;
			  
			  case 'm' :
			  kFlag.n_back = 4;
			  
			  for(j=0;j<=34;j++)
			  if(kFlag.previous_0==consonants[j].key)
			  {
						DisplayCharacters(j,CONSONANTS,0);
			  }
			  break;
			  
			  default:
			  kFlag.n_back = 1;
			  DisplayCharacters(0,CONSONANTS,1) ;
    }
kFlag.f_bit = 0;
kFlag.f_pressed_Once = 0;
kFlag.o_bit = 1;
kFlag.n_back = -1;
} 


//-----------------------For P with ..--------------------------//
void DisplayCharacter_phi(char ch,int i)
{
switch(ch)
{
          case 'A' :
          case 'V' :
          case 'e' :
          case 'E' :
          case 'o' :
          case 'O' :
          case 'Y' :
          SendBackSpace(4);
          DisplayFourCharacter(165,243,115,192);
          break;					
                    }//------End of Switch(ch)-----//
}




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

char copy_f(char ch)
{
	f_2 = f_1;
	f_1 = ch;

	return f_2;
}

int isSecondf(char ch)
{
	if (f_2 == 'f' && ch == 'f')
		return 1;
	else
		return 0;
}