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
    // Variant 2: Strided memory access - traverse column by column with stride equal to number of rows
    // This results in non-consecutive access if stored in row-major order
    for (j = 0; j < A->n; j++)
        for (i = 0; i < A->m; i++)
            A->me[i][j] = 1.;
}
