#include <stdio.h>
#include <stdlib.h>

void r_inserction_sort(int *A, int p, int r);
int  r_find_max(int *A, int p, int r, int max);

int main()
{
    int size = 0, i = 0, *numbers;
    printf("How many numbers do you want? ");
    scanf("%d", &size);
    
    numbers = (int *) malloc(size * sizeof(*numbers));
    printf("Type %d numbers: ", size);
    for(i = 0; i < size; i++) scanf("%d", &numbers[i]);
    
    printf("Inputed vector:\n");
    for(i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n\n");
    
    r_inserction_sort(numbers, 0, size-1);
    
    printf("Sorted vector:\n");
    for(i = 0; i < size; i++) printf("%d ", numbers[i]);
    printf("\n\n");
    
    return 0;
}

void r_inserction_sort(int *A, int p, int r)
{
    if(p < r)
    {
        int j = r_find_max(A, p, r, p);
        int aux = A[r]; A[r] = A[j]; A[j] = aux;
        r_inserction_sort(A,p,r-1);
    }
}

int r_find_max(int *A, int p, int r, int max)
{
    if(p > r) return max;
    if(A[p] > A[max])
        return r_find_max(A,p+1,r,p);
    else
        return  r_find_max(A,p+1,r,max);
}
