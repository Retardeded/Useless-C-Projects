// author: Piotr Kurek

#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "vector.h"


typedef struct Vector
{
	T * tab;
	size_t capicity;
	size_t size;
} Vector;

Vector* constructVector(void)
{
    
    Vector * vector;
    vector = malloc(sizeof(Vector));
    vector->capicity = 0;
    vector->size = 0;
    vector->tab = NULL;
    return vector;
}

//struct Array *a = (struct Array*)calloc(size, sizeof(struct Array));
    /*
    int i = 0;
    while(i < 10)
    {
        a[i].num = i;
        printf("%i\n", a[i].num);
        i++;
    }
    */

void destruct(Vector* v)
{
	v->tab = realloc(v->tab, 0 * sizeof(T));
	v->size = 0;
	v->capicity = 0;
}

Vector* cloneVector(const Vector* v)
{
	Vector * vector = NULL;
    vector = malloc(sizeof(Vector));
    vector->tab = malloc(sizeof(T)*(v->size) );
    vector->capicity = v->size;
    vector->size = v->size;
    int i = 0;
    T *pointerVector = vector->tab;
    T *pointerV = v->tab;
    while(i < v->size)
    {
    	*(pointerVector+i) = *(pointerV+i);
    	i++;
	}
	
	return vector;
}

size_t size(const Vector* v)
{
	return v->size;
}

void resize(Vector* v, size_t newSize)
{
	int oldSize = v->size;
	if(newSize > oldSize)
	{
		v->tab = realloc(v->tab, newSize * sizeof(T));
		v->size = newSize;
		int i = oldSize;
		T *pointerV = v->tab;
		while(i < newSize)
		{
			*(pointerV + i) = 0;
			i++;
		}
	}
	else
	{
		v->size = newSize;
		
	}
}

size_t capacity(const Vector* v)
{
	return v->capicity;
}

bool empty(const Vector* v)
{
	if(v->size == 0)
		return 1;
	else
		return 0;
}

bool reserve(Vector* v, size_t size)
{
	if(size > v->size)
	{
		v->tab = realloc(v->tab, size * sizeof(T));
		v->capicity = size;
		return 1;
	}
	else
	{
		return 0;
	}
}

T* at(Vector* v, size_t index)
{
	T *pointer = v->tab;
	return (pointer + index);
}

T* front(Vector* v)
{
	T *pointer = v->tab;
	return pointer;
}

T* back(Vector* v)
{
	T *pointer = v->tab;
	return (pointer + v->size - 1);
}

void push_back(Vector* v, T element)
{
	if(v->size < v->capicity)
	{
		T *pointer = v->tab;
		*(pointer+v->size) = element;
		v->size = v->size + 1;
	}
	else
	{
		v->capicity = v->capicity + 1;
		v->tab = realloc(v->tab, v->capicity * sizeof(T));
		T* pointer = v->tab;
		*(pointer+v->size) = element;
		v->size = v->size + 1;
	}
}

void pop_back(Vector* v)
{
	if(v->size > 0)
	{
		v->size = v->size - 1;
		T*pointer = v->tab;
		*(pointer + v->size) = 0;
	}
}

T* erase(Vector* v, size_t index)
{
	T*pointer = v->tab;
	
	if( (v->size -1) > index)
	{
		int i = index;
		while(i < v->size)
		{
			*(pointer+i) = *(pointer+i+1);
			i++;
		}
		v->size = v->size - 1;
		int size = v->size;
		*(pointer + size) = 0;
	}
	
	return (pointer+index);
}

T* insert(Vector* v, T element, size_t index)
{
	T*pointer = v->tab;
	v->size = v->size + 1;
	if(v->size > v->capicity)
	{
		v->capicity = v->capicity + 1;
		v->tab = realloc(v->tab, v->capicity * sizeof(T));
	}
	int i = v->size-1;
	while(i > index)
	{
		*(pointer+i) = *(pointer+i-1);
		i--;
	}
	*(pointer+i) = element;
	
	return (pointer+i);
}
