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

extern MAT *QR;
extern VEC *y;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via pointer arithmetic to improve spatial locality
    double *base_y = y->ve;
    double **me_QR = QR->me;
    for (i = limit - 1; i >= 0; i--) {
        sum = 0.;
        double *row_ptr = me_QR[i] + i + 1;
        double *y_ptr = base_y + i + 1;
        for (j = i + 1; j < limit; j++) {
            sum += (*row_ptr++) * (*y_ptr++);
        }
        double yi_val = (sum >= 0.) ? 1. : -1.;
        y->ve[i] = (me_QR[i][i] >= 0.) ? yi_val : -yi_val;
    }
}
