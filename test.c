//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    double random_value;

    srand ( time ( NULL));

    int a = 4;
    int* pointer = &a;
    printf("%d\n", *pointer);

    int tab[] = {3, 6, 9, 11};
    const size_t tabSize = sizeof(tab)/sizeof(tab[0]);
    pointer = tab;
    *pointer = *(pointer +3);
    printf("%d %d\n", *pointer, *tab);
    int i = 0;
    while(i < tabSize)
    {
        printf("%d ", *(pointer + i));
        i++;
    }
    printf("\n");
    double* dynamicArray = malloc(sizeof(double)*tabSize);
    i = 0;
    while(i < tabSize)
    {
        random_value = (double)rand()/(1.0 + RAND_MAX)*2.0;
        dynamicArray[i] = random_value;
        printf("%f ", dynamicArray[i]);
        i++;
    }
    free(dynamicArray);
    printf("\n");
    double* matrix[tabSize];
    for(size_t i = 0; i < tabSize; i++)
    {
        matrix[i] = malloc(sizeof(double)*tabSize);
    }

    for (size_t i = 0; i < tabSize; ++i)
    {
        for (size_t j = 0; j < tabSize; ++j)
        {
            matrix[i][j] = rand() % 11 + 10;
            printf("%f ", matrix[i][j]);
        }
    }
    free(matrix[2]);
    /*
    int r = 3, c = 4; 
    int *arr = (int *)malloc(r * c * sizeof(int)); 
  
    int j, count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         *(arr + i*c + j) = ++count; 
  
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         printf("%d ", *(arr + i*c + j)); 
    return 0;
    */
}