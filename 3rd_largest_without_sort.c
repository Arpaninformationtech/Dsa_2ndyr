#include<stdio.h>
#include<limits.h>
int main()
{
 int i,first = INT_MIN,second=INT_MIN,third=INT_MIN,num=0;
 printf("Enter the no. of elements of array ");
 scanf("%d",&num);
 int a[num];
 printf("Enter the elements ");
 for (int i = 0; i < num; i++)
 {
    scanf("%d",&a[i]);
 }

 for (int i = 0; i < num; i++)
 {
    if(first<a[i])
    {
       third=second;
       second=first;
       first=a[i];
    }
    else if(second<a[i] && first>a[i])
    {
        third=second;
        second=a[i];

    }
     else if (third<a[i] && second>a[i]){ third=a[i];}
    
        
    
 }

 printf("The Third Largest element is %d",third);
 
 
    return 0;
}