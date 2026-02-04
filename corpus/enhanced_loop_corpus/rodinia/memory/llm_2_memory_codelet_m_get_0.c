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

extern int m;
extern int n;
extern MAT *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    double *base_ptr = matrix->base;
    double **me_ptr = matrix->me;
    for (i = 0; i < m; i++) {
        me_ptr[i] = base_ptr;
        base_ptr += n;
    }
}
