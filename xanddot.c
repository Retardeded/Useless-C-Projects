//author: Piotr Kurek
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int m = 11;
	int n = 6;
	int len = 9;
	int asciLetter = 49;
	char name1[256];
	char name2[256];
	printf("Name of player 1:\n");
	scanf("%s", name1);
	puts("");
	printf("Name of player 2:\n");
	scanf("%s", name2);
	puts("");
	char board[n][m];
	
	int i;
	int j;
	for(i = 0; i < n; i++)
	{
		int jvalue = 1;
		for(j = 0; j < m; j++)
		{
			if(i % 2 == 0 && j == jvalue)
			{
				board[i][j] = asciLetter;
				asciLetter++;
				jvalue += 4;
			}
			else if(j == 3 || j == 7)
			{
				board[i][j] = '|';
			}
			else if(i % 2 == 1 && i < 5)
			{
				board[i][j] = '_';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
	printf("Welcome %s and %s\n", name1, name2);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%c", board[i][j]);
			if(board[i][j] < 58)
			{
				board[i][j] = ' ';
			}
		}
		printf("\n");
	}
	
	int rounds = 1;
	int usedValues[len];
	int values1[len];
	int values2[len];
	char mark;
	
	for(i = 0; i < len; i++)
	{
		usedValues[i] = 0;
		values1[i] = 0;
		values2[i] = 0;
	}
	while(1)
	{
		int didWin1 = 0;
		int didWin2 = 0;
		
		for(i = 0; i < len; i+=3)
		{
			int iCopy = i;
			while(iCopy < i+3 && values1[iCopy] == 1)
			{
				iCopy++;
			}
			if(iCopy == i + 3)
			{
				didWin1 = 1;
				break;
			}
			
			iCopy = i;
			while(iCopy < i+3 &&values2[iCopy] == 1)
			{
				iCopy++;
			}
			if(iCopy == i + 3)
			{
				didWin2 = 1;
				break;
			}
		}
		
		for(i = 0; i < 3; i++)
		{
			int iCopy = i;
			while(iCopy < i+9 && values1[iCopy] == 1)
			{
				iCopy += 3;
			}
			if(iCopy == i + 9)
			{
				didWin1 = 1;
				break;
			}
			
			iCopy = i;
			while(iCopy < i+9 && values2[iCopy] == 1)
			{
				iCopy += 3;
			}
			if(iCopy == i + 9)
			{
				didWin2 = 1;
				break;
			}
		}
		
			if(values1[0] == 1 && values1[4] == 1 && values1[8] == 1)
			{
				didWin1 = 1;
			}
			if(values1[2] == 1 && values1[4] == 1 && values1[6] == 1)
			{
				didWin1 = 1;
			}
			if(values2[0] == 1 && values2[4] == 1 && values2[8] == 1)
			{
				didWin2 = 1;
			}
			if(values2[2] == 1 && values2[4] == 1 && values2[6] == 1)
			{
				didWin2 = 1;
			}
		
		if(didWin1)
		{
			printf("%s (%c) won!", name1, mark);
			break;
		}
		if(didWin2)
		{
			printf("%s (%c) won!", name2, mark);
			break;
		}
		
		if(rounds > len)
		{
			printf("Neigher %s nor %s won, it's a draw!", name1, name2);
			break;
		}
		int number;
		if(rounds % 2 == 1)
		{
			printf("%s put your X [1, 9]:\n", name1);
			mark = 'X';
		}
		else
		{
			printf("%s put your O [1, 9]:\n", name2);
			mark = 'O';
		}
		
		
		while(1)
		{
			if(scanf("%i", &number) != 1)
			{
				printf("Not a number!");
				return 0;
			}
			else
			{
				puts("");
				if(number > 9 || number < 1)
				{
					if(rounds % 2 == 1)
					{
						printf("%s put your X [1, 9]:\n", name1);
					}
					else
					{
						printf("%s put your O [1, 9]:\n", name2);
					}
				}
				else if(usedValues[number-1] == 1)
				{
					if(rounds % 2 == 1)
					{
						printf("%s put your X [1, 9]:\n", name1);
					}
					else
					{
						printf("%s put your O [1, 9]:\n", name2);
					}
				}
				else
				{
					usedValues[number-1] = 1;
					if(rounds % 2 == 1)
					{
						values1[number-1] = 1;
					}
					else
					{
						values2[number-1] = 1;
					}
					break;
				}
			}
		}
		
		int current = 0;
		int isPlaced = 0;
		for(i = 0; i < n; i++)
		{
			int jvalue = 1;
			for(j = 0; j < m; j++)
			{
				if(!isPlaced)
				{
					if(i % 2 == 0 && j == jvalue)
					{
						current++;
						jvalue += 4;
					}
					if(current == number)
					{
						board[i][j] = mark;
						isPlaced = 1;
					}
				}
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
		rounds++;
	}
}
