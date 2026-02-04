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

extern int kk;
extern int j;
extern MAT *H1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array access into 1D with stride
    double *base = H1->base;
    u_int max_n = H1->max_n;
    for (j = 0; j < kk; j++) {
        base[j * (max_n + 1)] -= 1.0;  // Accessing diagonal elements via flattened base assuming row-major
    }
}
