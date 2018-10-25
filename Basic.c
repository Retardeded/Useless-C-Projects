//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

void main()
{
	int toSeconds = 60*60;
	int toSecondsPerDay = toSeconds * 24;
	int toSecondsPerWeek = toSecondsPerDay * 7;
	int hours;
	int n;
	scanf("%d", &n);
	hours = n;
	printf("%d", hours);
	printf("\n");
	int seconds = hours * toSeconds;
	printf("%i hours = %i", hours, seconds);
	//printf("%i seconds = %i weeks %i days %i hours %i minutes %i seconds", seconds, seconds / toSecondsPerkWeek, hours * toSeconds)
}
