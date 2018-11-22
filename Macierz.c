//author: Piotr Kurek 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define ROWS 2
#define COLS 2

void printfMatrix(float tab[ROWS][COLS], int startRow)
{
    printf("%f %f", tab[startRow][0], tab[startRow][1]);
    printf("\n");
    printf("%f %f", tab[startRow+1][0], tab[startRow+1][1]);
}
void main()
{
    float number;
    int i = 0;
    int j = 0;
    float tab[4][2];
    float matrix[2][2];
    char matrixString[] = "Matrix matrix";
    while(!feof(stdin))
    {   
        number = getchar();
        if( isdigit(number))
        {
            if(i == 0)
                {
                    tab[j][0] = number;
                }
                if(i == 1)
                {
                    tab[j][1] = number;
                }
                if(i == 2)
                {
                    tab[j+1][0] = number;
                }
                if(i == 3)
                {
                    tab[j+1][0+1] = number;
                }
            i++;
        }
        if(i == 4)
        {
            j = j + 2;
            i = 0;
        }
        printf("%i", i);
    }
    printf("matrixString%c%c", '1', ':');
    printfMatrix(tab, 0);
    if(j < 4)
    {
        printf("End of input!");
        
    }
    else
    {
        printf("\n");
        printf("matrixString%c%c", '2', ':');
        printfMatrix(tab, 2);

        matrix[0][0] = tab[0][0] + tab[2][0];
        matrix[0][1] = tab[0][1] + tab[2][1];
        matrix[1][0] = tab[1][0] + tab[3][0];
        matrix[1][1] = tab[1][1] + tab[3][1];

        printf("\n");
        printf("Matrix");
        printf("\n");
        printf("matrix1+matrix2:");
        printfMatrix(matrix, 0);

        matrix[0][0] = tab[0][0] * tab[2][0] + tab[0][1] + tab[3][0];
        matrix[0][1] = tab[0][0] * tab[2][1] + tab[0][1] * tab[3][1];
        matrix[1][0] = tab[1][0] * tab[2][0] + tab[1][1] + tab[3][0];
        matrix[1][1] = tab[1][0] * tab[2][1] + tab[1][1] * tab[3][1];
        
        printf("\n");
        printf("Matrix");
        printf("\n");
        printf("matrix1*matrix2:");
        printfMatrix(matrix, 0);
    }
}