#include<stdio.h>


void display(int array[], int length){
  for(int i=0; i<length; i++){
    printf("%d ",array[i]);
  }
  printf("\n"); 
}
 
int main(){

 
  int temp, length = 5;
  printf("Enter the size of array ");
  scanf("%d",&length);
 int array[length];
  printf("Enter the elements array ");
  for (int i = 0; i < length; i++)
  {
    scanf("%d",&array[i]);
  }
  
  int i=0;         
  int j=length-1;  


  printf("Original array:   ");
  display(array, length);


  while(i<j){
   
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;

   
    i++;  
    j--;  
  }

 
  printf("Reverse of array: ");
  display(array, length);

  return 0;
}