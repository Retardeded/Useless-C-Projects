//author: Piotr Kurek
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "trimming.h"

int_least32_t trimText(char text[])
{
	int n = strlen(text);
	int i = 0;
	int beforeSpaces;
	int afterSpaces;
	char* copy;
	char* begin = text;
	while(isspace((unsigned char) *text) || ((unsigned char) *text) == '\t')
	{
		text++;
		i++;
	}
	copy = text;
	beforeSpaces = i;
	text = text-beforeSpaces+n-1;
	i = 0;
	while(isspace((unsigned char) *text) || ((unsigned char) *text) == '\t')
	{
		text--;
		i++;
	}
	afterSpaces = i;
	i = 0;
	text = begin;
	while(i < n)
	{
		if(i < n - beforeSpaces - afterSpaces)
		{
			*(text+i) = *(copy+i);
		}
		else
		{
			*(text+i) = 0;
		}
		i++;
	}
	int_least32_t sum = afterSpaces + beforeSpaces;
	if(sum == n*2)
	{
		sum = sum / 2;
	}
	return sum;
}
