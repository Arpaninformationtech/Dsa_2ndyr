#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//develop a tic-tac-toe game 

//check function
int check(char grid[3][3],char c1,char c2)
{
	//check who wins
	//at 0 0
	if(grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2])
	{
		if(grid[0][0]==c1)
		{
			return 1;
		}
		else if(grid[0][0]==c2)
		{
			return 2;
		}

	}
	else if(grid[0][0]==grid[0][1]&&grid[0][0]==grid[0][2])
	{
		if(grid[0][0]==c1)
		{
			return 1;
		}
		else if(grid[0][0]==c2)
		{
			return 2;
		}
	}
	else if(grid[0][0]==grid[1][0]&&grid[0][0]==grid[2][0])
	{
		if(grid[0][0]==c1)
		{
			return 1;
		}
		else if(grid[0][0]==c2)
		{
			return 2;
		}
	}

	//at 1 1
	if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])
	{
		if(grid[1][1]==c1)
		{
			return 1;
		}
		else if(grid[1][1]==c2)
		{
			return 2;
		}
	}
	else if(grid[1][0]==grid[1][1]&&grid[1][1]==grid[1][2])
	{
		if(grid[1][1]==c1)
		{
			return 1;
		}
		else if(grid[1][1]==c2)
		{
			return 2;
		}
	}
	else if(grid[0][1]==grid[1][1]&&grid[1][1]==grid[2][1])
	{
		if(grid[1][1]==c1)
		{
			return 1;
		}
		else if(grid[1][1]==c2)
		{
			return 2;
		}
	}
	else if(grid[2][0]==grid[1][1]&&grid[1][1]==grid[0][2])
	{
		if(grid[1][1]==c1)
		{
			return 1;
		}
		else if(grid[1][1]==c2)
		{
			return 2;
		}
	}

	//at 2 2
	if(grid[0][0]==grid[2][2]==grid[1][1])
	{
		if(grid[2][2]==c1)
		{
			return 1;
		}
		else if(grid[2][2]==c2)
		{
			return 2;
		}
	}
	else if(grid[2][2]==grid[1][2]==grid[0][2])
	{
		if(grid[2][2]==c1)
		{
			return 1;
		}
		else if(grid[2][2]==c2)
		{
			return 2;
		}

	}
	else if(grid[0][2]==grid[1][2]==grid[2][2])
	{
		if(grid[2][2]==c1)
		{
			return 1;
		}
		else if(grid[2][2]==c2)
		{
			return 2;
		}
	}

	return 0;

}

int main()
{
	printf("Two players will play the game.\n");
	char player1[100];
	char player2[100];
	printf("Enter the name of player 1:\n");
	scanf("%s",player1);
	printf("Enter the name of player 2:\n");
	scanf("%s",player2);

	char c1,c2;
	// printf("%s enter your choice: X or O.",player1);
	// scanf("%c",&c1);

	c1='X';
	c2='O';

	int countmoves=0;
	char grid[3][3];
	memset(grid,'.',sizeof(grid));
	int turn=0;

	while(countmoves<9)
	{
		if(turn==0)
		{
			printf("Turn of %s.\n",player1);
			printf("Current state of the grid is:\n");
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf("%c",grid[i][j]);
					printf(" ");
				}
				printf("\n");
			}

			int x,y;
			printf("Enter coordinates to place:\n");
			scanf("%d%d",&x,&y);
			if(grid[x][y]!='.')
			{
				printf("Invalid move. Retake.");
				continue;
			}
			grid[x][y]=c1;
			countmoves++;
			turn=1;
		}
		else
		{
			printf("Turn of %s.\n",player2);
			printf("Current state of the grid is:\n");
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf("%c",grid[i][j]);
					printf(" ");
				}
				printf("\n");
			}

			int x,y;
			printf("Enter coordinates to place:\n");
			scanf("%d%d",&x,&y);
			if(grid[x][y]!='.')
			{
				printf("Invalid move. Retake.");
				continue;
			}
			grid[x][y]=c2;
			countmoves++;
			turn=0;
		}
		if(check(grid,c1,c2)==1)
		{
			printf("Current state of the grid is:\n");
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf("%c",grid[i][j]);
					printf(" ");
				}
				printf("\n");
			}
			printf("%s wins.\n",player1);
			return 0;
		}
		else if(check(grid,c1,c2)==2)
		{
			printf("Current state of the grid is:\n");
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf("%c",grid[i][j]);
					printf(" ");
				}
				printf("\n");
			}
			printf("%s wins.\n",player2);
			return 0;
		}
		else
		{
			continue;
		}
	}

	printf("Current state of the grid is:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%c",grid[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	//check for who wins
	if(check(grid,c1,c2)==1)
	{
		printf("%s wins.\n",player1);
	}
	else if(check(grid,c1,c2)==2)
	{
		printf("%s wins.\n",player2);
	}
	else
	{
		printf("Draw.\n");
	}

}