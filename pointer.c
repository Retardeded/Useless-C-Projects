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
	while(isspace((unsigned char) *text || *text == '\t') )
	{
		text++;
		i++;
	}
	copy = text;
	beforeSpaces = i;
	text = text-beforeSpaces+n-1;
	i = 0;
	while(isspace((unsigned char) *text) || *text == '\t')
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
	i = 0;
	while(i < n - beforeSpaces - afterSpaces)
	{
		printf("%c\n", *(text+i));
		i++;
	}
	return sum;
}
void remove_spaces(char* a){
  char* n = a;
  char* m = a;
  while(*m != 0){
    *n = *m++;
    if(*n != ' ')
      n++;
  }
  *n = 0;
}

char * trim_leading(char * s) {
     while(isspace((unsigned char) *s)) s++;
     
     int i = 0;
     while(*(s+i) != 0)
		{
			printf("%c\n", *(s+i) );
			i++;
		}
     return s;
}
 
int main() {
    
	char text[200] =  "	Rzady [...] jak wiadomo, bardzo pragna naszego dobra, bez wzgledu na to, ile go nam jeszcze pozostalo.";
	int howMany = trimText(&text);
	printf("%i\n", howMany);
}
