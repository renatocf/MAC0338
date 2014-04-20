/* Default libraries */
#include <stdio.h>

/* Libraries */
#include "SORT.h"

void print_array(int *A, int n)
{
    int i = 0;
    while(i < n) printf("%d ", A[i++]);
    printf("\n");
}

typedef void (*Sort)(int *,int,int);
typedef void (*Test)(Sort,char*);

void test1(Sort sort_func, char *sort_name)
{
    static int test = 1;
    int A[] = { 1, 42, 34, 14, 23, 21 };
    printf("\nTEST #%d: %s\n", test++, sort_name);
    sort_func(A,0,5);
    print_array(A,6);
}

void test_sort(Test test)
{
    static int testset = 1;
    printf("TESTSET #%d\n", testset++);
    printf("======================\n");
    test( INSERCTION_SORT, "Inserction sort" );
    test( SELECTION_SORT , "Selection_sort"  );
    test( MERGESORT      , "Mergesort"       );
    test( HEAPSORT       , "Heapsort"        );
    test( QUICKSORT      , "Quicksort"       );
    test( COUNTING_SORT  , "Counting sort"   );
    test( RADIX_SORT     , "Radix sort"      );
    printf("\n");
}

int main()
{
    test_sort(test1);
    
    return 0;
}
