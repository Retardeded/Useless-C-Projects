#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Array
{
    int num;
};

struct Array* constructArray(size_t size)
{
    struct Array *a = (struct Array*)calloc(size, sizeof(struct Array));
    /*
    int i = 0;
    while(i < 10)
    {
        a[i].num = i;
        printf("%i\n", a[i].num);
        i++;
    }
    */
    return a;
}

void Array* destruct(Array* array)
{
    free(array);
}

void main()
{
    struct Array *array = constructArray(10);
    int i = 0;
    while(i < 10)
    {
        printf("%i\n", array[i].num);
        i++;
    }
}