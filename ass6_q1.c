#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swapp(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void insertsort(int arr[],int n)
{
	int key,j;
	for(int i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	printf("After sorting through Insertion Sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void selectsort(int arr[],int n)
{
	int min_index;
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if (arr[j]<arr[min_index]) min_index=j;
		}
		swapp(&arr[i],&arr[min_index]);
	}
	printf("After sorting through Selection Sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
		
		
void main(int argc,char* argv[])
{
	int n=atoi(argv[1]);
	int *arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("Enter the %d th element:",i+1);
		scanf("%d",&arr[i]);
	}
	insertsort(arr,n);
	selectsort(arr,n);
}
