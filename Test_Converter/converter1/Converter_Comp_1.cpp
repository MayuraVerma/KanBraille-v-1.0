#include <stdio.h>
#include <string.h>
#include "windows.h"
#include "converter.h"


FILE *fp_o;


struct abc 
{
       char cvar1[11];
       char cvar2[11];
       int len;
} str[1] = { "fgb","hn",2 }; 
         
int open_file(char *name)
{  
    fp_o = fopen(name,"w");
    fclose(fp_o);
	return 1;
}

int compsubstr(char var[11],char buffer[sizeof(long double)-2],int len,int k)
{
    int i;
     for (i=0;i<len;i++)
     {
                    if(var[i]!=buffer[k+i])
                    return 0;
     }
     return 1;
}
int compstr(char buffer[sizeof(long double)-2],int k,char *file_name)
{
    int i;
    for (i= 0;i<20186;i++)
    { 
        int j = 0;
        j = compsubstr(str[i].cvar1,buffer,strlen(str[i].cvar1),k);
        if(j == 1)
        {
			fp_o = fopen(file_name,"a");
		//	printf("%d %s \n",i+1,str[i].cvar2);
			fprintf(fp_o,"%s",str[i].cvar2);    
			fclose(fp_o);
			return strlen(str[i].cvar1);
        }
    }
    return 0;
}

int main(int argc,char *argv[])
{
    int i,j,k;
    char istring1[69][10],istring2[69][10],temp[10], buffer[65000],fchr;
    FILE *fp,*fp1,*fp2;
	char argv_1[2][255] = { "input.txt","output.txt" };
	char input_file[255],output_file[255];
TCHAR  Buffer[255]; int next_line = 0;
	char c;

	GetSystemDirectory(Buffer,255);

    strcat(Buffer,"\\File_names.txt");

    fp2 = fopen(Buffer,"r");
	
	i = 0;
	while(EOF != (c = getc(fp2)))
	{
		if(c == '|')
		{
			next_line = 1;
			input_file[i] = '\0';
			i = 0;
			continue;
		}

		if(next_line)
			output_file[i++] = char(c);
		else
			input_file[i++] = char(c);
	}

	output_file[i] = '\0';
	
	
	printf("Before Conversion %s%s\n",input_file,output_file);

	for(i=0;input_file[i]!='\0';i++)
	{

	    if(isupper(input_file[i]))
		input_file[i] = tolower(input_file[i]);
	}

	for(i=0;output_file[i]!='\0';i++)
	{

	    if(isupper(output_file[i]))
		output_file[i] = tolower(output_file[i]);
	}

	
	printf("After Coversion %s%s",input_file,output_file);
	
    fp = fopen(input_file,"r");

       open_file(output_file);  
  //   printf("dfv"); 
       i = 0;
			do 
			{
				fchr=fgetc(fp);
			
			    if(fchr!=' ')
				{
				vFind_Kannada_Characters(get_kan(fchr));
				}
				else
				{
				AddKey(32);
				flush(output_file);
				}

				//k++;
            }while(fchr!=EOF);
//#endif

			flush(output_file);

    fclose(fp);
    fclose(fp2);
   // printf("Successful Hit Enter\n");
   // getchar();
}
