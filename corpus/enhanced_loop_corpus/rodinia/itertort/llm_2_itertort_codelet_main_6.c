#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern VEC *x;
extern VEC *y;
extern int j;
extern MAT *Q;
extern MAT *H;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic for improved spatial locality
    double *h_ptr = &(H->me[0][0]);
    double *x_ve = x->ve;
    double *y_ve = y->ve;
    u_int m = Q->m - 1;

    for (j = 0; j < m; j++) {
        *(h_ptr + j * H->max_n + j) = x_ve[j];                    // H[j][j]
        *(h_ptr + j * H->max_n + j + 1) = y_ve[j];               // H[j][j+1]
        *(h_ptr + (j + 1) * H->max_n + j) = y_ve[j];             // H[j+1][j]
    }
}
