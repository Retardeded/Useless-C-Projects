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


long * FindAllDivs(long n)
{
	int m = 3*(int)sqrtl(n);
	long *divs = malloc (sizeof (long) * m);
	int i = 2;
	int j = 0;
	int half = 0;
	while(i <= (int)sqrtl(n) )
	{
		if(n % i == 0)
		{
			divs[j] = i;
			j++;
		}
		i++;
	}
	i = 0;
	if(divs[j-1] == sqrtl(n))
	{
		half = j-1;
	}
	else
	{
		half = j;
	}
	while(i < half)
	{
		long number = n / divs[half-i-1];
		divs[j] = number;
		j++;
		i++;
	}

	*(divs+m-1) = j;
	return divs;
}
int isFactorial(long n)
{
	long factorial = 1;
	int i = 2;
	while(factorial < n)
	{
		factorial *= i;
		i++;
	}
	
	if(factorial == n)
		return 1;
	else
		return 0;
}
int isFib(long n)
{
	long n1 = 0;
	long n2 = 1;
	while(n > n1)
	{
		long temp = n2;
		n2 = n2+n1;
		n1 = temp;
	}
	if(n1 == n)
		return 1;
	else
		return 0;
}
int isAutoMorfic(long n)
{
	long square = n*n;
	int len1 = ceil(log10((double)n));
	int len2 = ceil(log10((double)square));
	char string1[len1];
	sprintf(string1, "%d", n);
	char string2[len2];
	sprintf(string2, "%d", square);
	int i = 1;
	
	while(i <= len1 )
	{
		if(string1[len1-i] != string2[len2-i])
				break;
		i++;
	}
	if(i == len1+1 && len1 != len2 || n == 1  || n == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	if( 1 != scanf("%i", &n) )
	{
		return 0;
	}
	else
	{
		printf("%i = 0%o = 0x%x\n", n, n, n);
	
		if(n > 0)
		{
			int m = 3*(int)sqrtl(n);
			
			long *divisors = FindAllDivs(n);
			int i = 0;
			if(divisors[m-1] > 0)
			{
				printf("divisors: ");
			}
			while(i < divisors[m-1])
			{
				printf("%i,", *(divisors+i));
				i++;
			}
			if(divisors[m-1] == 0 && n > 1)
			{
				printf("prime number\n");
			}
			else
			{
				printf("\n");
			}
			if(isFactorial(n))
			{
				printf("factorial number\n");
			}
			if(isFib(n))
			{
				printf("fibonacci number\n");
			}
			if(isAutoMorfic(n))
			{
				printf("automorphic number");
			}
		}
		if(n == 0)
		{
			if(isFib(n))
			{
				printf("fibonacci number\n");
			}
			
			printf("automorphic number");
		}
	}
	
	
}
