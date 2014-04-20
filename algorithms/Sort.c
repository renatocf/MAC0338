/* Default libraries */
#include <stdlib.h>
#include <stdio.h>

/* Libraries */
#include "SORT.h"

/* n*lgn auxiliars */
void MERGE           (int *A, int p, int q, int r);
void MAX_HEAPFY      (int *A, int p, int r, int i);
void BUILD_MAX_HEAP  (int *A, int p, int r);
int  PARTITION       (int *A, int p, int r);

/**
 * @func  INSERCTION_SORT
 * @brief Stable and quadratic sorting algorithm - θ(n²)
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be sorted
 * @param r End position of the subvector to be sorted
 */
void INSERCTION_SORT(int *A, int p, int r)
{
    int i, j;
    for(j = p+1; j <= r; j++) 
    {
        int key = A[j];
        for(i = j-1; i >= p && A[i] > key; i--)
            A[i+1] = A[i];
        A[i+1] = key;
    }
}

/**
 * @func  SELECTION_SORT
 * @brief Stable and quadratic sorting algorithm - θ(n²)
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be sorted
 * @param r End position of the subvector to be sorted
 */
void SELECTION_SORT(int *A, int p, int r)
{
    int i, j, max, aux;
    for(i = r; i >= p+1; i--)
    {
        max = i;
        for(j = i-1; j >= p; j--)
            if(A[max] < A[j]) max = j;
        aux = A[i]; A[i] = A[max]; A[max] = aux;
    }
}

/**
 * @func  MERGE
 * @brief Auxiliar function for Merge Sort - 6n+5 == θ(n)
 * @param A Vector to be merged
 * @param p Start position of the subvector to be merged
 * @param q Pivot which divide the subsubvectors to be merged
 * @param r End position of the subvector to be merged
 */
void MERGE(int *A, int p, int q, int r)
{
    int n = r-p+1, i=0, j=0, k=0;
    int *B = malloc(n * sizeof(*B));
    for(i = p; i <= q; i++)
        B[i-p] = A[i];
    for(j = q+1; j <= r; j++)
        B[(r+q+1-j)-p] = A[j];
    i = p; j = r;
    for(k = p; k <= r; k++)
        if(B[i-p] <= B[j-p])
            { A[k] = B[i-p]; i=i+1; }
        else
            { A[k] = B[j-p]; j = j-1; }
    free(B);
}

/**
 * @func  MERGESORT
 * @brief Stable and n*lgn sorting algorithm - θ(n*lgn)
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be sorted
 * @param r End position of the subvector to be sorted
 */
void MERGESORT(int *A, int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        MERGESORT(A,p,q);
        MERGESORT(A,q+1,r);
        MERGE(A,p,q,r);
    }
}

/**
 * @func  MAX_HEAPFY
 * @brief Auxiliar function for Heap Sort - O(lg(m/i))
 * @param A Vector to be max heapfied
 * @param m Size of the subvector to be max heapfied
 * @param i Radix of the subheap to be max heapfied
 */
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

/**
 * @func  BUILD_MAX_HEAP
 * @brief Auxiliar function for Heap Sort - θ(n)
 * @param A Vector to build max heap
 * @param n Size of the array in that the max heap will be built
 */
void BUILD_MAX_HEAP(int *A, int p, int r)
{
    int i = 0;
    for(i = (r-p+1)/2; i >= 0; i--)
        MAX_HEAPFY(A,p,r,i);
}

/**
 * @func  HEAPSORT
 * @brief n*lgn sorting algorithm - θ(n*lgn)
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be sorted
 * @param r End position of the subvector to be sorted
 */
void HEAPSORT(int *A, int p, int r)
{
    int i, m = r;
    BUILD_MAX_HEAP(A,p,r); /* pre-proc */
    for(i = r; i >= p; i--)
    {
        int aux = A[p]; A[p] = A[i]; A[i] = aux; 
        m = m-1;
        MAX_HEAPFY(A,p,m,p);
    }
}

/**
 * @func   PARTITION
 * @brief  Auxiliar function for Quick Sort - θ(n)
 * @param  A Vector to be sorted
 * @param  p Start position of the subvector to be partitioned
 * @param  r End position of the subvector to be partitioned
 * @return Pivot position (which divide the subvector in 2 subsets)
 */
int PARTITION(int *A, int p, int r)
{
    int x = A[r], i = p-1, j, aux;
    for(j = p; j <= r-1; j++)   
        if(A[j] <= x)
        {
            i = i+1;
            aux = A[i]; A[i] = A[j]; A[j] = aux;
        }
    aux = A[i+1]; A[i+1] = A[r]; A[r] = aux;
    return i+1;
}

/**
 * @func  QUICKSORT
 * @brief Stable and n*lgn sorting algorithm - θ(n*lgn)
 * Average/Best case: θ(n*lgn); Worst case: θ(n²).
 * @param A Vector to be sorted
 * @param n Number of elements in the vector
 * @param k Maximum number of A
 */
void QUICKSORT(int *A, int p, int r)
{
    if(p < r)
    {
        int q = PARTITION(A,p,r);
        QUICKSORT(A,p,q-1);
        QUICKSORT(A,q+1,r);
    }
}

/**
 * @func   FIND_MAX
 * @brief  Auxiliar function for Counting Sort - θ(n)
 * @param  A Vector to be sorted
 * @param  p Start position of the subvector to be partitioned
 * @param  r End position of the subvector to be partitioned
 * @return Maximum element of the subvector
 */
int FIND_MAX(int *A, int p, int r)
{
    int i, max = A[p];
    for(i = p+1; i <= r; i++)
        if(A[i] > max) max = A[i];
    return max;
}

/**
 * @func   FIND_MIN
 * @brief  Auxiliar function for Counting Sort - θ(n)
 * @param  A Vector to be sorted
 * @param  p Start position of the subvector to be partitioned
 * @param  r End position of the subvector to be partitioned
 * @return Maximum element of the subvector
 */
int FIND_MIN(int *A, int p, int r)
{
    int i, min = A[p];
    for(i = p+1; i <= r; i++)
        if(A[i] < min) min = A[i];
    return min;
}

/**
 * @func  COUNTING_SORT
 * @brief Stable and linear sorting algorithm - θ(n+k)
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be partitioned
 * @param r End position of the subvector to be partitioned
 */
void COUNTING_SORT(int *A, int p, int r)
{
    int i, j, k = FIND_MAX(A,p,r);
    int *B = (int *) malloc((r-p+1) * sizeof(*B));
    int *C = (int *) malloc((k+1) * sizeof(*C));
    
    /* 1: Zeroes the auxiliar vector - θ(k) */
    for(i = 0; i <= k; i++)
        C[i] = 0;
    /* 2: Count the occurences of the numbers - θ(n)*/
    for(j = p; j <= r; j++)
        C[A[j]]++;
    /* 3: Accumulate to find first position of an element - Θ(k) */
    for(i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    /* 4: Set the element on its position - θ(n) */
    for(j = r; j >= p; j--)
    {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
    /* 5: Resort the elements in the main vector - θ(n) */
    for(j = p; j <= r; j++)
        A[j] = B[j-p];
    
    free(B); free(C);
}

/**
 * @func   MAX_DIGITS
 * @brief  Auxiliar function for Radix Sort - θ(d*n)
 * @param  A Vector to be sorted
 * @param  p Start position of the subvector to be partitioned
 * @param  r End position of the subvector to be partitioned
 * @return Maximum number of digits of a number in the subvector
 */
int MAX_DIGITS(int *A, int p, int r)
{
    int i, j, b, max = 0;
    for(i = p; i <= r; i++)
    {
        for(j = A[i], b = 0; j; j/=10, b++);
        if(b > max) max = b;
    }
    return max;
}

/**
 * @func  RADIX_SORT
 * @brief Stable and linear sorting algorithm - θ(d(n+k))
 * @param A Vector to be sorted
 * @param p Start position of the subvector to be partitioned
 * @param r End position of the subvector to be partitioned
 */
void RADIX_SORT(int *A, int p, int r)
{
    int b = 0, i, j, d = MAX_DIGITS(A,p,r);
    
    /* Auxiliar vectors */
    int C[10], k = 9;
    int *B = (int *) malloc((r-p+1) * sizeof(*B));
    
    for(b = 0; b <= d; b++)
    {
        /* 1: Zeroes the auxiliar vector - θ(k) */
        for(i = 0; i <= k; i++)
            C[i] = 0;
        /* 2: Count the occurences of the digit - θ(n)*/
        for(j = p; j <= r; j++)
        {
            int dig = (A[j]/(10*b ? 10*b : 1)) % 10;
            C[dig]++;
        }
        /* 3: Accumulate to find first position of an element - Θ(k) */
        for(i = 1; i <= k; i++)
            C[i] = C[i] + C[i-1];
        /* 4: Set the element on its position - θ(n) */
        for(j = r; j >= p; j--)
        {
            int dig = (A[j]/(10*b ? 10*b : 1)) % 10;
            B[C[dig]-1] = A[j];
            C[dig]--;
        }
        /* 5: Resort the elements in the main vector - θ(n) */
        for(j = p; j <= r; j++)
            A[j] = B[j-p];
    }
    
    free(B);
}
