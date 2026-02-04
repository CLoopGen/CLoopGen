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

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing diagonal elements consecutively in terms of logical iteration,
    // we maintain the same logical indices but simulate a strided traversal by skipping iterations
    // using a larger step, then adjusting index usage. However, since we must cover all j from 1 to i,
    // we simulate stride-1 with same logic but reorganize access via pointer arithmetic.
    double **me_base = R1->me;
    for (j = 1; j <= i; j++) {
        *(me_base[j] + j) -= 1.0;
    }
}
