#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern int p;
extern double **A;
extern double **B;
extern double **C;
extern int Aj0;
extern int Bj0;
extern int Cj0;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing B[k][Bj0 + j] with unit stride in j, we reverse the inner loop to create a strided access pattern
    // This increases cache misses due to non-consecutive memory accesses in B.
    for (i = 0; i < m; i++)
        for (k = 0; k < p; k++)
            for (j = n - 1; j >= 0; j--)
                C[i][Cj0 + j] += A[i][Aj0 + k] * B[k][Bj0 + j];
}
