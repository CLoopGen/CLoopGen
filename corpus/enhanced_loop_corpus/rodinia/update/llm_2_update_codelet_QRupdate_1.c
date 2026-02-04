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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *R;
extern VEC *v;
extern int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This changes the access pattern to strided and processes two elements per iteration
    u_int n = R->n;
    u_int remainder = n % 2;
    double *base_R0 = R->me[0];
    double *base_v = v->ve;
    
    for (j = 0; j < n - remainder; j += 2) {
        base_R0[j]     += temp * base_v[j];
        base_R0[j + 1] += temp * base_v[j + 1];
    }
    // Handle remaining element if n is odd
    if (remainder && j < n) {
        base_R0[j] += temp * base_v[j];
    }
}
