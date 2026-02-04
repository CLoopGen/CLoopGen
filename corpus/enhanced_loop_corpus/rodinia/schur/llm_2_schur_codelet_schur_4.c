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
extern int k;
extern int k_min;
extern int k_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing row pointers and accessing consecutive elements
    double **me = A->me;
    int k_start = k_min;
    int k_end = k_max - 2;

    for (k = k_start; k <= k_end; k++) {
        double *row_k_plus_2 = me[k + 2];
        row_k_plus_2[k] = 0.0;
        if (k < k_end) {
            double *row_k_plus_3 = me[k + 3];
            row_k_plus_3[k] = 0.0;
        }
    }
}
