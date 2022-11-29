//4. Write a C program to
//find the frequency of a character present in the text given in a file.

#include <stdio.h>

int main()
{
    FILE *file1;
    file1=fopen("text.txt", "r");


    int size=0;

    while(fgetc(file1)!= EOF)
    {
        size++;
    }

    fclose(file1);

    FILE *file2;
    file2=fopen("text.txt", "r");

    char arr[size];
    int arr1[size];

    char ch = fgetc(file2);
    if(ch== EOF)
    {
    printf("The file is empty\n");
    return;
    }

    int i=0;
    while(ch!= EOF)
    {
        int temp=0;
        for(int j=0; j<i; j++)
        {
            if(arr[j]==ch)
            {
                arr1[j]++;
                temp=1;
                break;
            }
        }

        if(temp ==0)
        {
            arr[i]=ch;
            arr1[i]=1;
            i++;
        }
        ch=fgetc(file2);
    }
    arr[i]= NULL;
    arr1[i]='\0';
    printf("The frequency of different characters in the text file is:\n");
    for(int i=0; arr[i]!='\0';i++)
    {
        printf("%c: %d\n",arr[i],arr1[i]);
    }

    fclose(file2);
}