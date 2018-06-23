#include <stdio.h>

int main()
{
    int i,j;
    char istring1[69][10],istring2[69][10],temp[10];
    FILE *fp,*fp1,*fp2;
    fp = fopen("Sample.txt","r");
    fp1 = fopen("Sample1.txt","w");
    fp2 = fopen("Sample2.txt","w");
        
   
    for(i=0;i<21000;i++)
    {
        fprintf(fp1,"%d      \{ fprintf(  yyout \, \"%d\" \)\;  \}\n",i,21000-i);
        //{ fprintf(yyout,"Read");
    }
   
    fclose(fp2);
    fclose(fp1);
    fclose(fp);
}
