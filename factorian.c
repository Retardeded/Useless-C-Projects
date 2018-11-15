//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include "factorian.h"

T factorial(int x)
{
    int i = 0;
    int factorial = 1;
    if(x < 0)
    {
        factorial = FACTORIAN_ERROR_NEGATIVE_VALUE;
    }
    else if (x <= 21)
    {
        for(int i = x; i > 1; i--)
        {
            factorial *= i;
        }
    }
    else
    {
        factorial = FACTORIAN_TOO_GREAT_VALUE;
    }

    return factorial;
}