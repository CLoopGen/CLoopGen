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
    // Variant 1: Consecutive memory access by transposing the access pattern
    // Instead of accessing R1->me[i+1][j] for j in [0, i), we simulate consecutive writes
    // by treating the row as a linear array. This improves spatial locality.
    double *row = R1->me[i + 1];
    for (j = 0; j < i; j++) {
        row[j] = 0.;
    }
}
