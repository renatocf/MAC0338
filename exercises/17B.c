/* Libraries */
#include <stdio.h>
#include <stdlib.h>

void VITO_SORT(int *A, int n, int k)
{
    int a, i = 0, j;
    for(a = 1; a <= k; a++)
        for(j = i; j < n; j++)
            if(A[j] == a)
            {
                int aux = A[j]; A[j] = A[i]; A[i] = aux;
                i++;
            }
}

int main()
{
    int i;
    
    int A[] = { 1, 42, 34, 14, 23, 21 };
    int S[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    VITO_SORT(A, 6, 42);
    for(i = 0; i < 6; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    VITO_SORT(S, 10, 10);
    for(i = 0; i < 10; i++)
        printf("%d ", S[i]);
    printf("\n");
    
    return 0;
}
