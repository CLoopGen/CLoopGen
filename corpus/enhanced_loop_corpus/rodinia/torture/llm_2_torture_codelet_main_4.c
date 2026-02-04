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

extern MAT *C;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing diagonal elements (i,i), we access with a stride of 2 on both dimensions
    // Ensure bounds are respected to avoid out-of-bounds access
    u_int stride = 2;
    u_int bound = (C->m < C->n) ? C->m : C->n; // Use smaller dimension to stay in bounds
    for (i = 0; i < bound; i += stride)
        ((C)->me[i][i] = (((C)->me[i][i]) - 1.));
}
