//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

void correctingNames(char name1[],int n, int numberOfSpaces1) 
{ 
int i = 0; 
i = n-1; 
name1[n] = '|'; 
 while(i >= 0) 
 { 
  if(i <= n - numberOfSpaces1) 
  { 
   name1[i + numberOfSpaces1-1] = name1[i]; 
  }
  i--; 
 } 
 i = 0; 
 while(i < numberOfSpaces1-1) 
  { 
   name1[i] = ' '; i++; 
  } 
 name1[0] = '|'; 
}

int main(void) {

 int n = 14; 
 char name1[n+1]; 
 char name3[n+10]; 
 char name4[n+10];
 char name2[n+1]; 
 char usefullString[] = "|  km/h|   m/h|"; 
 int numberOfSpaces1 = 0; 
 int numberOfSpaces2 = 0; 
 
 scanf("%s", &name3); 
 scanf("%s", &name4); 
 long long kmPH = 0; 
 long long miles;
 scanf("%lld", &kmPH);
 numberOfSpaces1 = n-strlen(name3)+1;
 numberOfSpaces2 = n-strlen(name4)+1;
 if(numberOfSpaces1 < 2)
 {
 	numberOfSpaces1 = 2;
 }
 if(numberOfSpaces2 < 2)
 {
 	numberOfSpaces2 = 2;
 }
 int i = 0;
while(i <= 14)
{
 	name1[i] = name3[i];
 	name2[i] = name4[i];
 	i++;
} 
 correctingNames(name1, n, numberOfSpaces1);
 correctingNames(name2, n, numberOfSpaces2);
 miles = (1/1.609344) * kmPH + 2; 
 miles -= miles %5;
 
 printf("---------------"); 
 printf("\n"); 
 printf("%s", name1); 
 printf("\n"); 
 printf("%s", name2); 
 printf("\n"); 
 printf("---------------"); 
 printf("\n");
 printf("%s", usefullString); 
 printf("\n");
 printf("---------------"); 
 printf("\n");
 printf("|%6lld|%6lld|\n", kmPH, miles); 
 printf("---------------"); 
}
