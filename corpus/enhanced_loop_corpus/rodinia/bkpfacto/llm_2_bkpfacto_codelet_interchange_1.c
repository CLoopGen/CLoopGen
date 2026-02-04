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
extern double tmp;
extern int k;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D matrix into a 1D view
    double *base_j = (A)->me[j];
    double *base_i = (A)->me[i];
    for (k = j + 1; k < n; k++) {
        tmp = base_j[k];
        base_j[k] = base_i[k];
        base_i[k] = tmp;
    }
}
