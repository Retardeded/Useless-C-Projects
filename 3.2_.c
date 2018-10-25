//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

void main()
{
	double deegresC;
	double deegresF;
	printf("Podaj temperature w stopniach Celsjusza \n");
	scanf("%lf", &deegresC);
	
	deegresF = deegresC * 9/5 + 32;
	printf("Podana temperatura w stopniach Fahrenheita to %lf \n \n", deegresF);
	
	printf("Podaj temperature w stopniach Fahrenheita \n");
	scanf("%lf", &deegresF);
	
	deegresC = (deegresF -32 ) * 5/9;
	printf("Podana temperatura w stopniach Celsjusza to %lf", deegresC);
	
}
