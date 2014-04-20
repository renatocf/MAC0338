#ifndef H_SORT_DEFINED
#define H_SORT_DEFINED

/* Quadratic algorithms */
void INSERCTION_SORT (int *A, int p, int r);
void SELECTION_SORT  (int *A, int p, int r);

/* n*lgn algorithms */
void MERGESORT       (int *A, int p, int r);
void HEAPSORT        (int *A, int p, int r);
void QUICKSORT       (int *A, int p, int r);

/* Linear algorithms */
void COUNTING_SORT   (int *A, int p, int r);
void RADIX_SORT      (int *A, int p, int r);

#endif
