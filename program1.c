//10000100100111110000100101000 ---> 1, 0000, 1, 001, 1111, 0000, 1, 001, 01, 0000
#include<stdio.h>
#include<string.h>
void fn_two(char* s);
void fn_three(char* s);
void fn_four(char* s);
void main(){

//reading string from the file:
	char s[100];
    FILE *filePointer ;
    filePointer = fopen("text.txt", "r") ;
    if ( filePointer == NULL ){
        printf( "file failed to open.") ;
    }
    else{
		int i=0;
        while( fgets ( s, 50, filePointer ) != NULL ){
            printf( "%s" , s ) ;
        }
        fclose(filePointer) ;
    }
//taking input of N value:
    int n;
    printf("Enter N(2/3/4):");
    scanf("%d", &n);
//Using functiond for different values of N:
    if(n==2){
        fn_two(s);
    }
    if(n==3){
        fn_three(s);
    }
    if(n==4){
        fn_four(s);
    }
}

//For N=4:

void fn_four(char* s){
    int len=strlen(s);
    int count=0,com=0;
    for(int i=0;i<len;i++){
        if(s[i]=='1'&& s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' &&count==0){
            //printf("%c%c%c%c,", s[i], s[i+1], s[i+2], s[i+3]); 
            i=i+4;
            com++;
        }
        //printf("%c", s[i]);
        count++;

        if(s[i]=='1'){
            //printf(",");
            count=0;
            com++;
        }
        if(s[i]=='0'){
            if(count==4){
            //printf(",");
            com++;
            count=0;
            }
        }
    }
//assignment 2: q.1, b:

	//storing the subarrays in a 2d matrix:
	int n=com+1;
	char arr[n][4];
	int k=0,l=0;
	count=0;
	for(int i=0;i<len;i++){
		if(s[i]=='1'&& s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' &&count==0){
			arr[k][l]=s[i];
			arr[k][l+1]=s[i+1];
			arr[k][l+2]=s[i+2];
			arr[k][l+3]=s[i+3];			
			i=i+4;
			k=k+1;
			l=0;
		}
		arr[k][l]=s[i];
		count++;
		l++;

		if(s[i]=='1'){
			k++;
			l=0;
			count=0;
		}
		if(s[i]=='0'){
			if(count==4){
			k++;
			l=0;
			count=0;
			}
		}
	}

	//modifying the matrix:
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j]!='1' && arr[i][j]!='0'){
			arr[i][j]=' ';
			}
		}
	}
	if(arr[n-1][1]==' ' && arr[n-1][0]=='0'){
				arr[n-1][1]='0';
			}
	if(arr[n-1][2]==' ' && arr[n-1][1]=='0'){
				arr[n-1][2]='0';
			}
	if(arr[n-1][3]==' ' && arr[n-1][2]=='0'){
				arr[n-1][3]='0';
			}

	printf("\nSubstrings are:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			printf("%c ",arr[i][j]);
			}
		printf("\n");
	}

   //comparing the rows of subarray with the possible cases:
	int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;  //1,01,001,0001,0000,1111
	for(int i=0;i<n;i++){
		if(arr[i][0]=='1' && arr[i][1]!='1'){
			c1++;
		}
		if(arr[i][0]=='0' && arr[i][1]=='1'){
			c2++;
		}
		if(arr[i][0]=='0' && arr[i][2]=='1'){
			c3++;
		}	
		if(arr[i][0]=='0' && arr[i][3]=='1'){
			c4++;
		}
		if(arr[i][0]=='0' && arr[i][3]=='0'){
			c5++;
		}	
		if(arr[i][0]=='1' && arr[i][3]=='1'){
			c6++;
		}
	}
	printf("Frequency:\n 1    : %d\n 01   : %d\n 001  : %d\n 0001 : %d\n 0000 : %d\n 1111 : %d\n", c1,c2,c3,c4,c5,c6);


//assignment 2: q.1, c:
    //Replacing substrings with charcters:
 	char new[n];
	for(int i=0;i<n;i++){
			if(arr[i][0]=='1' && arr[i][1]!='1'){
				new[i]='A';
			}
			if(arr[i][0]=='0' && arr[i][1]=='1'){
				new[i]='B';
			}
			if(arr[i][0]=='0' && arr[i][2]=='1'){
				new[i]='C';
			}	
			if(arr[i][0]=='0' && arr[i][3]=='1'){
				new[i]='D';
			}
			if(arr[i][0]=='0' && arr[i][3]=='0'){
				new[i]='E';
			}	
			if(arr[i][0]=='1' && arr[i][3]=='1'){
				new[i]='F';
			}
		}
		for(int i=0;i<n;i++){
			printf("%c", new[i]);
		}
        //storing the new character string in a new file:
        FILE *filePointer1 ;
        filePointer1 = fopen("new.txt", "w") ;
        if ( filePointer1 == NULL ){
            printf( "file failed to open.");
            }
        else{
            if ( strlen ( new ) > 0 ){
                fputs(new, filePointer1) ;
                fputs("\n", filePointer1) ;
            }
            fclose(filePointer1) ;
        
//assignment 2: q.1, c:
        int newlen=strlen(new);
        int p_reduc=(newlen*100/len);
        printf("\nPercent reduction in length : %d ", p_reduc);
        }
}

//For N=3:

void fn_three(char* s){
    int len=strlen(s);
int count=0,com=0;
for(int i=0;i<len;i++){
	if(s[i]=='1'&& s[i+1]=='1' && s[i+2]=='1' &&count==0){
		//printf("%c%c%c,", s[i], s[i+1], s[i+2]); 
		i=i+4;
		com++;
 	}
	//printf("%c", s[i]);
	count++;

	if(s[i]=='1'){
		//printf(",");
		count=0;
		com++;
	}
	if(s[i]=='0'){
		if(count==3){
		//printf(",");
		com++;
		count=0;
		}
	}
}
//assignment 2: q.1, b:

	//storing the subarrays in a 2d matrix:
	int n=com+1;
	char arr[n][3];
	int k=0,l=0;
	count=0;
	for(int i=0;i<len;i++){
		if(s[i]=='1'&& s[i+1]=='1' && s[i+2]=='1' &&count==0){
			arr[k][l]=s[i];
			arr[k][l+1]=s[i+1];
			arr[k][l+2]=s[i+2];			
			i=i+3;
			k=k+1;
			l=0;
		}
		arr[k][l]=s[i];
		count++;
		l++;

		if(s[i]=='1'){
			k++;
			l=0;
			count=0;
		}
		if(s[i]=='0'){
			if(count==3){
			k++;
			l=0;
			count=0;
			}
		}
	}

	//modifying the matrix:
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]!='1' && arr[i][j]!='0'){
			arr[i][j]=' ';
			}
		}
	}
	if(arr[n-1][1]==' ' && arr[n-1][0]=='0'){
				arr[n-1][1]='0';
			}
	if(arr[n-1][2]==' ' && arr[n-1][1]=='0'){
				arr[n-1][2]='0';
			}

	printf("\nSubstrings are:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			printf("%c ",arr[i][j]);
			}
		printf("\n");
	}

   //comparing the rows of subarray with the possible cases:	
	int c1=0,c2=0,c3=0,c4=0,c5=0;  //1,01,001,000,111
	for(int i=0;i<n;i++){
		if(arr[i][0]=='1' && arr[i][1]!='1'){
			c1++;
		}
		if(arr[i][0]=='0' && arr[i][1]=='1'){
			c2++;
		}
		if(arr[i][0]=='0' && arr[i][2]=='1'){
			c3++;
		}	
		if(arr[i][0]=='0' && arr[i][2]=='0'){
			c4++;
		}
		if(arr[i][0]=='1' && arr[i][2]=='1'){
			c5++;
		}	
	}
	printf("Frequency:\n 1    : %d\n 01   : %d\n 001  : %d\n 000 : %d\n 111 : %d\n", c1,c2,c3,c4,c5);
//assignment 2: q.1, c:
    //replacing substrings with characters:
 	char new[n];
	for(int i=0;i<n;i++){
			if(arr[i][0]=='1' && arr[i][1]!='1'){
				new[i]='A';
			}
			if(arr[i][0]=='0' && arr[i][1]=='1'){
				new[i]='B';
			}
			if(arr[i][0]=='0' && arr[i][2]=='1'){
				new[i]='C';
			}	
			if(arr[i][0]=='0' && arr[i][2]=='0'){
				new[i]='D';
			}	
			if(arr[i][0]=='1' && arr[i][2]=='1'){
				new[i]='E';
			}
		}
		for(int i=0;i<n;i++){
			printf("%c", new[i]);
		}
        //storing the new character string in a new file:
        FILE *filePointer1 ;
        filePointer1 = fopen("new.txt", "w") ;
        if ( filePointer1 == NULL ){
            printf( "file failed to open.");
            }
        else{
            if ( strlen ( new ) > 0 ){
                fputs(new, filePointer1) ;
                fputs("\n", filePointer1) ;
            }
            fclose(filePointer1) ;
        }
//assignment 2: q.1, c:
	int newlen=strlen(new);
	int p_reduc=(newlen*100/len);
	printf("\nPercent reduction in length : %d ", p_reduc);
}

//For N=2;

void fn_two(char* s){
    int len=strlen(s);
int count=0,com=0;
for(int i=0;i<len;i++){
	if(s[i]=='1'&& s[i+1]=='1' &&count==0){
		i=i+4;
		com++;
 	}
	//printf("%c", s[i]);
	count++;

	if(s[i]=='1'){
		//printf(",");
		count=0;
		com++;
	}
	if(s[i]=='0'){
		if(count==2){
		//printf(",");
		com++;
		count=0;
		}
	}
}
//assignment 2: q.1, b:
    //storing the subarrays in a 2d matrix:
	int n=com+1;
	char arr[n][2];
	int k=0,l=0;
	count=0;
	for(int i=0;i<len;i++){
		if(s[i]=='1'&& s[i+1]=='1' && s[i+2]=='1' &&count==0){
			arr[k][l]=s[i];
			arr[k][l+1]=s[i+1];			
			i=i+2;
			k=k+1;
			l=0;
		}
		arr[k][l]=s[i];
		count++;
		l++;

		if(s[i]=='1'){
			k++;
			l=0;
			count=0;
		}
		if(s[i]=='0'){
			if(count==2){
			k++;
			l=0;
			count=0;
			}
		}
	}

	//modifying the matrix:
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			if(arr[i][j]!='1' && arr[i][j]!='0'){
			arr[i][j]=' ';
			}
		}
	}
	if(arr[n-1][1]==' ' && arr[n-1][0]=='0'){
				arr[n-1][1]='0';
			}
	printf("\nSubstrings are:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			printf("%c ",arr[i][j]);
			}
		printf("\n");
	}

   //comparing the rows of subarray with the possible cases:
	int c1=0,c2=0,c3=0,c4=0;  //1,01,00,11
	for(int i=0;i<n;i++){
		if(arr[i][0]=='1' && arr[i][1]!='1'){
			c1++;
		}
		if(arr[i][0]=='0' && arr[i][1]=='1'){
			c2++;
		}
		if(arr[i][0]=='0' && arr[i][1]=='0'){
			c3++;
		}	
		if(arr[i][0]=='1' && arr[i][1]=='1'){
			c4++;
		}	
	}
	printf("Frequency:\n 1    : %d\n 01   : %d\n 00 : %d\n 11 : %d\n", c1,c2,c3,c4);
//assignment 2: q.1, c:
 	    char new[100];
        for(int i=0;i<n;i++){
                if(arr[i][0]=='1' && arr[i][1]!='1'){
                new[i]='A';
            }
            if(arr[i][0]=='0' && arr[i][1]=='1'){
                new[i]='B';
            }
            if(arr[i][0]=='0' && arr[i][1]=='0'){
                new[i]='C';
            }	
            if(arr[i][0]=='1' && arr[i][1]=='1'){
                new[i]='D';
            }	
            }
		for(int i=0;i<n;i++){
			printf("%c", new[i]);
		}
        //storing the new character string in a new file:
        FILE *filePointer1 ;
        filePointer1 = fopen("new.txt", "w") ;
        if ( filePointer1 == NULL ){
            printf( "GfgTest.c file failed to open.");
            }
        else{
            if ( strlen ( new ) > 0 ){
                fputs(new, filePointer1) ;
                fputs("\n", filePointer1) ;
            }
            fclose(filePointer1) ;
        }
//assignment 2: q.1, c:
	int newlen=strlen(new);
	int p_reduc=(newlen*100/len);
	printf("\nPercent reduction in length : %d ", p_reduc);
}
