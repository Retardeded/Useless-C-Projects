//author: Piotr Kurek 
#include<stdio.h>
#include<stdlib.h>
 
 int main ()
 {
 	int n;
 	int m;
 	scanf("%d", &n);
 	scanf("%d", &m);
 	char board[m][n];
 	int i = 0;
 	int j = 0;
 	int x = 0;
 	int y = 0;
 	int iteration = 0;
 	int tetrimoses = 0;
 	for(i = 0; i < m-1; i++)
 	{
 		for(j = 0; j < n; j++)
 		{
 			if(i == m-2)
 			{
 				board[i][j] = '-';
			}
 			else if(j == 0 || j == n-1)
 			{
 				board[i][j] = '|';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
	
	printf("Iteration: %i, tetrimoses: %i\n", iteration, tetrimoses);
	printf("-");
	for(i = 1; i < n-1; i++)
	{
		printf("%i", i);
	}
	printf("-\n");
	for(i = 0; i < m-1; i++)
	{
		for(j = 0; j <n; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	
	while(1)
	{
		x = 0;
		y = 0;
		while(x >= n-1 || x <= 0)
		{
			scanf("%d", &x);
		}
		if(board[y][x] != '*')
		board[y][x] = '*';
		else
		{
			printf("Game over!");
			break;
		}
		tetrimoses++;
		iteration++;
		printf("Iteration: %i, tetrimoses: %i\n", iteration, tetrimoses);
		printf("-");
		for(i = 1; i < n-1; i++)
		{
			printf("%i", i);
		}
		printf("-\n");
		for(i = 0; i < m-1; i++)
			{
				for(j = 0; j <n; j++)
				{
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
		while(y < m-3)
		{
			//Sleep(1000);
			if(board[y+1][x] != '*')
			{
				board[y+1][x] = '*';
				board[y][x] = ' ';
			}
			else
			{
				break;
			}
			y++;
			iteration++;
			printf("Iteration: %i, tetrimoses: %i\n", iteration, tetrimoses);
			printf("-");
			for(i = 1; i < n-1; i++)
			{
				printf("%i", i);
			}
			printf("-\n");
			for(i = 0; i < m-1; i++)
			{
				for(j = 0; j <n; j++)
				{
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
		}
	}
 }
