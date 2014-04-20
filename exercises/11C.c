#include<stdio.h>

int LIMPA(int *A, int p, int r)
{
    printf("LIMPA(A,%d,%d)\n", p, r);
    if(p == r)
        return r;
    else
    {
        int q = LIMPA(A, p, r-1);
        if(A[r] != 0)
        {
            q++;
            A[q] = A[r];
        }
        return q;
    }
}

int main()
{
    int A[] = { 5, 6, 9, 3, 2, 4 };
    int B[] = { 42, 34, 32, 68, 97, 5, 1, 6, 73, 59 };
    
    printf("===========\n");
    LIMPA(A, 0, 5);
    printf("===========\n");
    LIMPA(B, 0, 10);
}
