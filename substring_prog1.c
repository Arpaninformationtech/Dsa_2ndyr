#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp=fopen("text.txt","r");
    char ch;

    int n=0;
    char s[100];
    while(ch!=EOF)
    {
        ch=fgetc(fp);
        s[n]=ch;
        n++;
    }

    n--;
    fclose(fp);
    printf("The available string is: %s\n",s);
    printf("The length of the given string is: %d\n",n);
    int m;
    printf("Enter number of consecutive zeros and ones:\n");
    scanf("%d",&m);

    char store[n+1][n+1];
    memset(store,0,sizeof(store));
    int pos=0;

    for(int i=0;i<n;)
    {
        if(s[i]=='0')
        {
            //check how many 0s exist in the string
            int j=i;
            int countzeros=0;
            int len=0;//calculates current length
            for(;j<n;j++)
            {
                if(s[j]=='0'&&countzeros<m)
                {
                    store[pos][len]=s[j];
                    len++;
                    countzeros++;
                    if(countzeros==m)
                    {
                        break;
                    }
                }
                else
                {
                    store[pos][len]=s[j];
                    len++;
                    break;
                }
            }
            store[pos][len]='\0';
            pos++;
            i=i+len;
        }
        else
        {
            //check how many 1s exist in the string
            int j=i;
            int countones=0;
            int len=0;
            for(;j<n;j++)
            {
                if(s[j]=='1'&&countones<m)
                {
                    store[pos][len]=s[j];
                    len++;
                    countones++;
                }
                else
                {
                   break;
                }
            }
            store[pos][len]='\0';
            pos++;
            i=i+len;
        }
    }

    for(int i=0;i<pos;i++)
    {
        printf("%s\n",store[i]);
    }

    int freq[pos+1];
    int visited[pos+1];
    memset(visited,0,sizeof(visited));

    for(int i=0;i<pos;i++)
    {
        int count_freq=1;
        for(int j=i+1;j<pos;j++)
        {
            if(strcmp(store[i],store[j])==0)
            {
                count_freq++;
                visited[j]=1;
            }
        }
        freq[i]=count_freq;
    }

    for(int i=0;i<pos;i++)
    {
        if(!visited[i])
        {
            printf("The frequency of %s is: %d\n",store[i],freq[i]);
        }
    }

    char newstring[pos+1];
    for(int i=0;i<pos;i++)
    {
        int length=strlen(store[i]);
        newstring[i]='A'+length-1;
    }

    FILE *fp1;
    fp1=fopen("output1.txt","w");

    printf("The new string is: %s\n",newstring);


    for(int i=0;i<pos;i++)
    {
        fputc(newstring[i],fp1);
    }
    fclose(fp1);

    double diff=n-pos;
    double percentage=(diff/n)*100.0;
    char c='%';

    printf("The percentage reduction in length is %lf%c.\n",percentage,c);

    return 0;
}