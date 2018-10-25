//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

void main()
{
	double length;
	double a;
	double b;
	double radius;
	
	printf("Podaj dlugosc boku kwadratu \n");
	scanf("%lf", &length);
	
	double areaOfSquare = length * length;
	double circumferenceOfSquare = 4 * length;
	printf("Pole wynosi %lf , Obwod wynosi %lf \n", areaOfSquare, circumferenceOfSquare);
	
	printf("Podaj dlugosc bokow prostokata \n");
	scanf("%lf %lf", &a, &b);
	double areaOfRectangle = a * b;
	double circumferenceOfRectangle = 2*a + 2*b;
	printf("Pole wynosi %lf , Obwod wynosi %lf \n", areaOfRectangle, circumferenceOfRectangle);
	
	printf("Podaj promien kola \n");
	scanf("%lf", &radius);
	double areaOfCircle = 3.14 * pow(radius, 2);
	double circumferenceOfCircle = 2 * 3.14 * radius;
	printf("Pole wynosi %lf , Obwod wynosi %lf \n", areaOfCircle, circumferenceOfCircle);
	
}
