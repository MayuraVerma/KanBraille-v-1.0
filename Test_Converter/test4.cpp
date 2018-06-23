#include <stdio.h>
#include <string.h>
           FILE *fp_o;
struct abc 
{
       char cvar1[10];
       char cvar2[10];
       int len;
} str[5] = {  {"sudheer1","sudheerHS",8} ,
              {"sudheer","sudheers",7 } ,
           }; 
         
         int open_file()
         {  

           fp_o = fopen("sample_out.txt","w");
           fclose(fp_o);
           }
           
int compsubstr(char var[10],char buffer[sizeof(long double)-2],int len,int k)
{
      for (int  i=0;i<len;i++)
     {
                    if(var[i]!=buffer[k+i])
                    return 0;
     }
     return 1;
}
int compstr(char buffer[sizeof(long double)-2],int k)
{
    for (int  i= 0;i<2;i++)
    { 
        int j = 0;
        j = compsubstr(str[i].cvar1,buffer,strlen(str[i].cvar1),k);
        if(j == 1)
        {
             fp_o = fopen("sample_out.txt","a");
        printf("%s \n",str[i].cvar1);
      //  fprintf(fp_o,"%s",str[i].cvar1);    
        fclose(fp_o);
        return strlen(str[i].cvar1);
        }
    }
    return 0;
}

int main()
{
    int i,j,k;
    char istring1[69][10],istring2[69][10],temp[10], buffer[sizeof(long double)-2],fchr;
    FILE *fp,*fp1,*fp2;

    fp = fopen("Sample.txt","r");
      open_file();  
 //   printf("%s   %s\n",str[0].cvar1,str[0].cvar2);
       
       i = 0;
			do 
			{
				fchr=fgetc(fp);
			
				buffer[i++] = fchr; //insert it to buffer
              
			}while(fchr!=EOF);
		
			buffer[i] = '\0'; //To represent End of String

			k = 0; // INDEX FOR BUFFER TRAVERSING 
  printf("%s \n",buffer);
  printf("%d \n",strlen(buffer));
  #if 1
			while(k <= strlen(buffer))
			{
                       j= 0;
                       j = compstr(buffer,k);
                 //   printf("%d",j);          
//                 if(strncmp(str[0].cvar1,buffer  
                 /*  for(i=0;i<2;i++)
                   {
                   j = 0;
                   j = compsubstr(str[i].cvar1,buffer,str[i].len,k);
//  j = compsubstr("sudheer","1sudheer",7,1);
*/
                   if(j>0)
                   {    
                        k = k+j; //change the k to point to current buffer 
                    //    printf("%s %d %d ",str[i].cvar1,str[i].len,k);    
                    //  printf ("j == 1");
                   }
                   else
                   {
                       k++;
                   }
                   
                   
            }
#endif
    fclose(fp);
  //  fclose(fp_o);
    printf("Successful Hit Enter\n");
    getchar();
}
