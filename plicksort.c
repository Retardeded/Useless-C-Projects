#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    // const char* filename = "D:\\Desktop\\plik.txt";
    const char* filename = "/home/students/k/kurepiot/plik.txt";
    int numOfNumbers = 0;
    int numOfLetters = 0;

    FILE* file = fopen(filename, "r+");

    if(!file)
    {
        fprintf(stderr, "blad %s\n", filename);
        exit(1);
    }

    char buffer[256];
    int table[1001][100];
    while(!feof(file))
    {
        if(!fgets(buffer, sizeof(buffer), file))
            break;
        puts(buffer);
        int number;
        if (1 == sscanf(buffer, "%d", &number))
        {
            printf(" %d\n", number);
            numOfNumbers++;
        }
        else
        {
            numOfLetters++;
        }
        
    }

    fclose(file);

    FILE *f = fopen("plik2.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);

    int i = 1;
    float py = 3.1415927;
    fprintf(f, "Integer: %d, float: %f\n", i, py);

    char c = 'A';
    fprintf(f, "A character: %c\n", c);

    fclose(f);


}