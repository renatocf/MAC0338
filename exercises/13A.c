#include <stdio.h>
#include <stdlib.h>

void MAX_HEAPFY(int *A, int p, int r, int i)
{
    int e = 2*i, d = 2*i+1, biggest = i;
    biggest = (e >= p && e <= r && A[e] > A[i] ? e : i);
    if(d >= p && d <= r && A[d] > A[biggest])
        biggest = d;
    if(biggest != i)
    {
        int aux = A[i]; A[i] = A[biggest]; A[biggest] = aux;
        MAX_HEAPFY(A,p,r,biggest);
    }
}

void BUILD_MAX_HEAP(int *A, int p, int r)
{
    int i = 0;
    for(i = (r-p+1)/2; i >= 0; i--)
        MAX_HEAPFY(A,p,r,i);
}

int MAX_HEAP_DELETE(int *A, int m, int i)
{
    int aux = A[i]; A[i] = A[m-1]; A[m-1] = aux;
    MAX_HEAPFY(A, 0, m-2, i); /* θ(n*lgn) */
}

int main()
{
    int i;
    int A[] = { 1, 42, 34, 14, 23, 21 };
    
    BUILD_MAX_HEAP(A, 0, 5);
    for(i = 0; i < 6; i++)
        printf("%d:%d ", i+1, A[i]);
    printf("\n");
    
    MAX_HEAP_DELETE(A, 6, 1);
    for(i = 0; i < 5; i++)
        printf("%d:%d ", i+1, A[i]);
    printf("\n");
}
