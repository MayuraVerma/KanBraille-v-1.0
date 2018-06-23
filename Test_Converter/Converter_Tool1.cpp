#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std;
struct conv
{
    char istring1[12];
    char istring2[12];
}conv_raw[20186];

int main()
{
    int i,j;
    conv temp;
    char fchr;

   FILE *fp,*fp1,*fp2,*fp3;
   fp = fopen("RaW_Conv.txt","r");
   fp1 = fopen("RaW_Conv_Fromatted_New.txt","w");
   fp2 = fopen("Fromatted_Brail_Kan.txt","w");
   fstream in ("RaW_Conv.txt" , ios::in  );
   fp3 = fopen("Fromatted_Brail_Kan_Test.txt","w");

    int count1 = 0;
    int count2 = 0;
    int space  = 0;
    int k = 0;
    i = 0;
    j = 0;
    
    while(in.read((char * ) &fchr , sizeof fchr))
    {
                     
			if(fchr == '\n')
               {
                     space = 0;
                     j++;
                     i = 0;
                        k++;
               }
               else
               if(isspace(fchr))
               {
                               space = 1;
                               i = 0;
               }
               else
               {
                   if(space!=1)
                   {
                   conv_raw[j].istring1[i++] = fchr;
                   }
                   if(space == 1)
                   {
                   conv_raw[j].istring2[i++] = fchr;
                   }
               }
	
		 }
			 
	for(i=k;i>=0;i--)
    {
  //      fscanf(fp,"%s\t%s\n",(char *)conv_raw[i].istring1,(char *)conv_raw[i].istring2);
      //  if(strcmp("xÉÝöÊ",istring1[i])==0)
         //   fprintf(fp3,"%s\t%s\n",conv_raw[i].istring1,conv_raw[i].istring2);
         
               fprintf(fp1,"\{ \"%s\"          \,                          \"%s\"         \,  %d \}  \,   //  %d\n",conv_raw[i].istring1,conv_raw[i].istring2,strlen(conv_raw[i].istring1),k-i+1);
               
    }
    	 
   #if 0 
    do
    {
              fchr=fgetc(fp);// fchr = fget(fp);
               if(fchr == '\n')
               {
                     space = 0;
                     j++;
                     i = 0;
               }
               else
               if(isspace(fchr))
               {
                               space = 1;
                               i = 0;
               }
               else
               {
                   if(space!=1)
                   {
                   conv_raw[j].istring1[i++] = fchr;
                   }
                   if(space == 1)
                   {
                   conv_raw[j].istring2[i++] = fchr;
                   }
               }
    }while(fchr!=EOF);
  
    for(i=0;i<20186;i++)
    {
  //      fscanf(fp,"%s\t%s\n",(char *)conv_raw[i].istring1,(char *)conv_raw[i].istring2);
      //  if(strcmp("xÉÝöÊ",istring1[i])==0)
         //   fprintf(fp3,"%s\t%s\n",conv_raw[i].istring1,conv_raw[i].istring2);
         
               fprintf(fp1,"\{ \"%s\"          \,                          \"%s\"         \,  %d \}  \,   //  %d\n",conv_raw[i].istring1,conv_raw[i].istring2,strlen(conv_raw[i].istring1),i+1);
               
    }
  
   // fclose(fp3);
   #endif
   
   
    #if 0
      printf("1 Second\n");
    for(i=0;i<20186;i++)
    {
                     for(j=i+1;j<20186;j++)
                     {
                                        if(strlen(conv_raw[i].istring1) < strlen(conv_raw[j].istring1) )
                                        {
                                        //  printf("%s\t%s\n",conv_raw[i].istring1,conv_raw[i].istring2);                                                                        
                                           strcpy(temp.istring1,conv_raw[i].istring1);
                                           strcpy(conv_raw[i].istring1,conv_raw[j].istring1);
                                           strcpy(conv_raw[j].istring1,temp.istring1);
                                                                                   
                                           strcpy(temp.istring2,conv_raw[i].istring2);
                                           strcpy(conv_raw[i].istring2,conv_raw[j].istring2);
                                           strcpy(conv_raw[j].istring2,temp.istring2);
                                  //      printf("%s\t%s\n",conv_raw[j].istring1,conv_raw[j].istring2); 
                                        }
                     }
    }
    for(i=0;i<20186;i++)
    {
        fprintf(fp1,"\{ \"%s\"          \,                          \"%s\"         \,  %d \}  \,   //  %d\n",conv_raw[i].istring1,conv_raw[i].istring2,strlen(conv_raw[i].istring1),i+1);
        //{ fprintf(yyout,"Read");
    }
        printf("Sorting Second\n");
     //   getchar();
    for(i=0;i<20186;i++)
    {
                     for(j=i+1;j<20186;j++)
                     {
                                        if(strlen(conv_raw[i].istring2) < strlen(conv_raw[j].istring2) )
                                        {
                                        //  printf("%s\t%s\n",conv_raw[i].istring1,conv_raw[i].istring2);                                                                        
                                           strcpy(temp.istring1,conv_raw[i].istring1);
                                           strcpy(conv_raw[i].istring1,conv_raw[j].istring1);
                                           strcpy(conv_raw[j].istring1,temp.istring1);
                                                                                   
                                           strcpy(temp.istring2,conv_raw[i].istring2);
                                           strcpy(conv_raw[i].istring2,conv_raw[j].istring2);
                                           strcpy(conv_raw[j].istring2,temp.istring2);
                                  //      printf("%s\t%s\n",conv_raw[j].istring1,conv_raw[j].istring2); 
                                        }
                     }
    }
    for(i=0;i<20186;i++)
    {
        fprintf(fp2,"\{ \"%s\"          \,                          \"%s\"         \,  %d \}  \,   //  %d\n",conv_raw[i].istring2,conv_raw[i].istring1,strlen(conv_raw[i].istring2),i+1);
        //{ fprintf(yyout,"Read");
    }
    fclose(fp2);
    fclose(fp1);
    fclose(fp);
    #endif
        printf("Exit\n");
    getchar();

}
