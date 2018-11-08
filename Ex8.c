//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>

int main()
{
 int n;
 scanf("%i", &n);
 int tab[n];
 int i = 0;
 float sum = 0;
 while(i < n)
 {
     int j;
     if(1 != scanf("%i", &j) )
     {
        break;
     }
     else
     {
        tab[i] = j;
        sum += j;
        i++;

     }
     
 }
 if(i > n)
 {
     return 0;
 }
 n = i;
 if(n != 0)
 {
     sum /= n;
 }
 else
 {
     sum = 0;
 }
 printf("average = %g, numbers:", sum);
 i = 0;
 while(i < n)
 {
     if(tab[i] % 2 == 1 || tab[i] % 2 == -1)
     {
         printf("\n");
         printf("%i", tab[i]);
     }
     i++;
 }
 return 0;
}
