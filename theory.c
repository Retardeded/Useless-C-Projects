#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>

# define N 5

int main()
{
	int i = 7;
	printf("%d\n", i/2);
	printf("%d\n", i << 1);// 111  1110
	printf("%d\n", i >> 1);// 111  11
	printf("%d\n", i & 8); // 1001  111
	printf("%d\n", i && 0);
	printf("%d\n", i++); // 7
	printf("%d\n", ++i); // 9
	printf("%d\n", i+2*5); // 19
	printf("%d\n", i+2^4); // 15
	printf("%d\n", i-= 2 << 2); // 9 2  10 1000  9-8
	printf("%d\n", i /= -3); // 9 -2   0 
	printf("%d\n", 1 | 4);
	printf("%x\n\n", i == 1 + 2 + 3 + 4 - 10); // 0 == 0, 1
	
	
	int tab[N] = {1};
	i = tab[0];
	tab[i++] = tab[0] & 7; // 1 111 -> 1 1
	tab[i++] = tab[0] | 4; // 1 1 5
	tab[i] = *(tab+i-2); // 1 1 5 1
	for(i = 0; i < N; ++i) printf("%d\n", tab[i]);
	
	printf("\n");
	char liczba = 3;
    printf("Liczba wynosi %u\n", liczba);
    liczba = liczba << 2;
    printf("liczba << 2 wynosi %u\n", liczba);
    liczba = liczba >> 3;
    printf("liczba >> 3 wynosi %u\n", liczba);
 
    liczba = liczba >> 0;
    printf("liczba >> 0 wynosi %u\n", liczba);
    /* liczba = liczba << -1; - to jest blad,
    mimo sygnalizacji warningiem na gcc, tego nie stosujemy! */
}
