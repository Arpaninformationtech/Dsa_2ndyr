#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char c;
    fp=fopen("text.txt","r");
    int m=-1;
    do
    {
        c=getc(fp);
        m++;

    }while(c!=EOF);
    fclose(fp);

    FILE *fp1;
    fp1=fopen("text.txt","r");
    char ch;

    char string[m];

    memset(string,0,strlen(string));

    do
    {
        ch=getc(fp1);
        strncat(string,&ch,1);
    }while(ch!=EOF);

    int prev=0;
    if(string[0]=='0')
        prev=0;
    else
    {
        prev=1;
    }
    int countones=0,countzeros=0;

    int n;
    printf("Enter maximum number of characters you want in your substring:\n");
    scanf("%d",&n);

    char a[m][n];
    memset(a,0,sizeof(a));
    int k=0;
    strncat(a[k],&string[0],1);

    for(int i=1;i<m;i++)
    {
        if(string[i]=='0')
        {
            if(prev==1)
            {
                //i must terminate my string here;
                k++;
                countones=0;
                countzeros=0;
            }
            strncat(a[k],&string[i],1);
            countzeros++;
            prev=0;
            if(countzeros==n)
            {
                //terminate my string here;
                k++;
                countones=0;
                countzeros=0;
                prev=-1;
            }
        }
        else
        {
            if(prev==0)
            {
                //i have to terminate my string here
                strncat(a[k],&string[i],1);
                k++;
                countones=0;
                countzeros=0;
                prev=-1;
                continue;
            }
            strncat(a[k],&string[i],1);
            countones++;
            prev=1;
             if(countones==n)
            {
                //terminate the string here
                k++;
                countones=0;
                countzeros=0;
                prev=-1;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='0'||a[i][j]=='1')
            printf("%c",a[i][j]);
            else
                break;
        }
        printf("\n");
    }

    return 0;
}

