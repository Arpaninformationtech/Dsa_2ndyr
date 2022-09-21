#include<stdio.h>
#include<stdlib.h>
int main()

{

char s[100];
printf("enter the string \n");
gets(s);
int n=strlen(s);

int l,i,j,k;

for(l=1;l<=n;l++)// length of substring.

{

for(i=0;i<=n-l;i++)// starting index

{

j=i+l-1;//ending index.

for(k=i;k<=j;k++)

{

printf("%c",s[k]);

}
printf("\n");
}

}

return 0;

}

