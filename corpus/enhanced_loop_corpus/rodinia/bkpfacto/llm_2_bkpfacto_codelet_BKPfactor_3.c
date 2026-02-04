#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We reverse the loop bounds and access pattern to promote spatial locality
    for (j = 0; j < A->m - 1; j++)
        for (i = j + 1; i < A->m; i++)
            ((A)->me[i][j] = (((A)->me[j][i])));
}
