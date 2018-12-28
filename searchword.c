//author: Piotr Kurek
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

enum TextSearchingDirection
{
    TEXT_SEARCHING_DIRECTION_FROM_BEGINNING,
    TEXT_SEARCHING_DIRECTION_FROM_END
};
typedef enum TextSearchingDirection TextSearchingDirection;

int findWordInTextReturningPosition(const char text[], const char word[], TextSearchingDirection searchDirection)
{
	int n = strlen(text);
	int m = strlen(word);
	char lowerText[n];
	char lowerWord[m];
	int i = 0;
	while(i < n)
	{
		lowerText[i] = tolower(text[i]);
		i++;
	}
	i = 0;
	while(i < n)
	{
		lowerWord[i] = tolower(word[i]);
		i++;
	}
	i = 0;
	if(searchDirection == 0)
	{
		while(i < n)
		{
			int j = 0;
			int index = i;
			while(lowerText[i] == lowerWord[j] && j < m && i < n)
			{
				j++;
				i++;
			}
			if(j == m )
			{
				return index;
			}
		i = i - j;
		i++;
		}
	}
	if(searchDirection == 1)
	{
		i = n-1;
		while(i > 0)
		{
			int j = 0;
			int index = i;
			while(lowerText[i] == lowerWord[j] && j < m && i > 0)
			{
				j++;
				i++;
			}
			if(j == m)
			{
				return index;
			}
		i--;
		}
	}
	return -1;
}
void main()
{
	enum TextSearchingDirection direction; 
    direction = TEXT_SEARCHING_DIRECTION_FROM_BEGINNING; 
    printf("%d\n", direction); 
    
	char text[100] = "Ala ma Kota, ale ten Kot ma sie tak do kota jak krzeslo do krzesla elektrycznego";
	char word[10] = "KOT";
	int i = 0;
	while(i < strlen(text))
	{
		printf("%c", text[i]);
		i++;
	}
	printf("%d\n", direction);
	int answer = findWordInTextReturningPosition(text, word, direction);
	printf("%d\n", answer);
}
