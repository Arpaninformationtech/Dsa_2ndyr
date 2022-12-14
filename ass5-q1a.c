#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bsort(int[],int);
void main(int argc,char* argv[])
{	
	clock_t start,end;
	start=clock();
	int n=atoi(argv[1]);
	int *arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		arr[i]=rand()%10000;
    }
	printf("\n");
	bsort(arr,n);
	printf("Sorted insert in array:\n");
	for(int i=0;i<n-1;i++)
		printf("\n  %d  -\n",arr[i]);
	printf("\n  %d  \n",arr[n-1]);
	end = clock();
  	double duration = ((double)end - start)/CLOCKS_PER_SEC;
  	printf("Time taken to execute in seconds : %f\n", duration);
}

void bsort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
    }
}
	