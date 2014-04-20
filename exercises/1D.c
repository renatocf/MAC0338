#include<stdio.h>

int main(int argc, char **argv)
{
    int s = 0, i = atoi(argv[1]), j;
    while(i > 0)
    {
        for(j = 1; j <= i; j++)
        {
            printf("i: %d, j: %d\n", i, j);
            s = s+1;
        }
        i = i/2;
    }
    
    printf("Soma = %d\n", s);
    return 0;
}
