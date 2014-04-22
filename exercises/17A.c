/* Libraries */
#include <stdio.h>
#include <stdlib.h>

void C_SORT(int *A, int n, int k)
{
    int i, j, *C = malloc((k+1) * sizeof(*C));
    for(i = 0; i <= k; i++)
        C[i] = 0;
    for(j = 0; j < n; j++)
        C[A[j]]++;
    j = 0;
    for(i = 0; i <= k; i++)
        while(C[i] > 0)
        {
            A[j] = i;
            j++;
            C[i]--;
        }
}

int main()
{
    int i;
    int A[] = { 1, 42, 34, 14, 23, 21 };
    C_SORT(A, 6, 42);
    for(i = 0; i < 6; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
