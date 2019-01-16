//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <limits.h>

int main()
{
	char ch;
	char begin[256];
	char end[256];
	int i = 0;
	int j = 0;
	int k = 0;
	int num = 1;
	int index1;
	int index2;
	int wrong = 0;
	while(! feof(stdin) )
	{
		if( 1 != scanf("%c", &ch) )
		{
			if(j == 0)
			{
				wrong = 1;
			}
			break;
		}
		if(num == 1 && (isdigit(ch) || ch == 43 || ch == 45) )
		{
			 begin[j] = ch;
			 j++;
		}
		else if(j > 0)
		{
			num = 2;
		}
		if(num == 2 && (isdigit(ch) || ch == 43 || ch == 45) )
		{
			 end[k] = ch;
			 k++;
		}
		i++;
	}
	index1 = atoi(begin);
	index2 = atoi(end);
	if(wrong == 0)
	{
		if(index1 < index2)
		{	
			if(index1 < 0) {
				index1 = 0;
			}
			if(index2 > UCHAR_MAX) {
				index2 = UCHAR_MAX;
			}
			i = index1;
			while(i <= index2)
			{
				printf("%i = >>%c<<\n", i, i);
				i++;
			}
		}
		else
		{
			if(index2 < 0) {
				index2 = 0;
			}
			if(index1 > UCHAR_MAX) {
				index1 = UCHAR_MAX;
			}
			i = index2;
			while(i <= index1)
			{
				printf("%i = >>%c<<\n", i, i);
				i++;
			}
		}
	}
	return 0;
}
