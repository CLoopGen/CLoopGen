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
extern int new_m;
extern int new_n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D access into a single loop with stride of 1
    double *base = A->base;
    double **me = A->me;
    int n = new_n;
    for (i = 0; i < new_m; i++) {
        me[i] = base + i * n;
    }
}
