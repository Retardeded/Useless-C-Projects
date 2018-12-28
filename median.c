//author: Piotr Kurek
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>

void sort(int_fast64_t tab[], int_fast64_t n)
{
	int i = 0;
	while(i < n)
	{
		int_fast64_t value = tab[i];
		int index = i;
		while(index > 0 && tab[index-1] > value)
		{
			tab[index] = tab[index-1];
			index = index-1;
		}
		if(index < i)
		{
			tab[index] = value;
		}
	i++;
	}
}
void main()
{
	int_fast64_t n;
	int maxKB = 128*1024;
	if(2 != scanf("%lld", &n) )
	{	
		
	}
	if(n < 0)
	{
		n = 0;
	}
	int_fast64_t nums = n;
	int_fast64_t *numbers;
	size_t size = sizeof(int_fast64_t)*nums;
	int i = 0;
	if(nums > 0)
	{
		if( size > maxKB)
		{
			nums = maxKB/(sizeof(int_fast64_t));
		}
		numbers = (int *)malloc(sizeof(int_fast64_t)*nums);
	}
	while(i < nums && ! feof(stdin))
	{
		if(1 != scanf("%ldd", &numbers[i]))
		{
			break;
		}
		i++;
	}
	nums = i;
	i = 0;
	int_fast64_t sum = 0;
	float average = 0;
	float median = 0;
	while(i < nums)
	{
		sum += numbers[i];
		i++;
	}
	if(nums > 0)
	{
		average = (float)((float)sum / nums);
		sort(numbers, nums);
		if(n % 2 == 0)
		{
			median = ((float)(numbers[nums/2] +  numbers[nums/2-1])/2);
		}
		else
		{
			median = numbers[nums/2];
		}
	}
	
	printf("sum = %d,\n", sum);
	printf("average = %g,\n", average);
	printf("median = %g,\n", median);
	int space = 1+(int)(log10((double)nums));
	i = 0;
	
	printf("of %lld numbers:\n", n);
	while(i < nums)
	{
		printf("%*lld: %lld\n",space, i+1, numbers[i]);
		i++;
	}
	
}

/*
void main()
{
	char text[10];
	int i = 0;
	while(!feof(stdin) && i < 10)
	{
		scanf("%c", &text[i]);
		i++;
	}
	int howMany = trimText(text);
	printf("%i", howMany);
}
*/
