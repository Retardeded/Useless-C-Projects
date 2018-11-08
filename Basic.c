//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

void main()
{
	int toSeconds = 60*60;
	float toDays = 0.04166666666;
	float toWeeks = 0.00595238095;
	int hours;
	int n;
	scanf("%d", &n);
	hours = n;
	int seconds = hours * toSeconds;
	float hoursFloat = (float)hours;
	printf("%i hours = %i seconds \n", hours, seconds);
	/*
	if(hours == 0)
	{
		printf("00:00:00");
	}
	else if(hours <= 24)
	{
		printf("%i hours", hours);
	}
	else if(hours <= 24*7)
	{
		printf("%g days", hoursFloat*toDays);
	}
	else
	{
		printf("%g weeks", hoursFloat*toWeeks);
	}
	*/
	printf("%i seconds = %g weeks %g days %i hours %i minutes %i seconds", seconds, hoursFloat*toWeeks,hoursFloat*toDays, hours, hours * 60, hours * toSeconds);
	
}
