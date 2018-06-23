#include <stdio.h>
struct abc 
{
       char cvar1[10];
       char cvar2[10];
} str[5] = { "sudheer","sudheer1" }; 
int main()
{
    int i,j;
    char istring1[20188][10],istring2[20188][10],temp[10];
    FILE *fp,*fp1,*fp2;
    fp = fopen("RaW_Conv.txt","r");
    fp1 = fopen("Formatted_Kan_Brail.txt","w");
    fp2 = fopen("Fromatted_Brail_Kan.txt","w");
    int count1 = 0;
    int count2 = 0;
  
    for(i=0;i<20188;i++)
    {
        fscanf(fp,"%s\t%s",istring1[i],istring2[i]);
        printf("%s\t%s",istring1[i],istring2[i]);
    }
    #if 0
    for(i=0;i<20188;i++)
    {
                     for(j=0;j<20188;j++)
                     {
                                        if(strlen(istring1[i]) < strlen(istring1[j]) )
                                        {
                                           strcpy(temp,istring1[j]);
                                           strcpy(istring1[j],istring1[i]);
                                           strcpy(istring1[i],temp);
                                                                                   
                                           strcpy(temp,istring2[j]);
                                           strcpy(istring2[j],istring2[i]);
                                           strcpy(istring2[i],temp);
                                        }
                     }
    }
    for(i=0;i<20188;i++)
    {
        fprintf(fp1,"\{ \"%s\"      \,       \"%s\"   \, %d \}  \,\n",istring1[i],istring2[i],strlen(istring1[i]));
        //{ fprintf(yyout,"Read");
    }
    for(i=0;i<20188;i++)
    {
                     for(j=0;j<20188;j++)
                     {
                                        if(strlen(istring2[i]) < strlen(istring2[j]) )
                                        {
                                           strcpy(temp,istring2[j]);
                                           strcpy(istring2[j],istring2[i]);
                                           strcpy(istring2[i],temp);
                                                                                   
                                           strcpy(temp,istring1[j]);
                                           strcpy(istring1[j],istring1[i]);
                                           strcpy(istring1[i],temp);
                                        }
                     }
    }
    for(i=0;i<20188;i++)
    {
        fprintf(fp2,"\{ \"%s\"      \,       \"%s\"   \, %d \}  \,\n",istring2[i],istring1[i],strlen(istring2[i]));
        //{ fprintf(yyout,"Read");
    }
    fclose(fp2);
    fclose(fp1);
    fclose(fp);
    #endif
    printf("Exit\n");
}
