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
    // Variant 2: Consecutive Memory Access Pattern via Loop Interchange and Forward Sequential Access
    // Reorder loops to j-k-i and access arrays in row-major order to maximize spatial locality.
    // Ensures that C[i][*], A[i][*], and B[k][*] are accessed consecutively in memory.
    for (j = 0; j < n; j++)
        for (k = 0; k < p; k++)
            for (i = 0; i < m; i++)
                C[i][Cj0 + j] += A[i][Aj0 + k] * B[k][Bj0 + j];
}
