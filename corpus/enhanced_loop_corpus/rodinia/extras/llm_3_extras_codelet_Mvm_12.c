#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern int _usr_j0;
extern double alpha;
extern double **A;
extern double *x;
extern double *y;
extern int i;
extern int j;
extern int m4;
extern int n2;
extern double *Aref;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (j = 0; j < n; j++) {
    tmp = alpha * x[2 * n2 + j];
    for (i = 0; i < m4; i++) {
        int base_idx_A = (2 * n2 + j) * m + j0 + 4 * i;
        int base_idx_y = 4 * i;
        y[base_idx_y] += tmp * A[2 * n2 + j][j0 + 4 * i];
        y[base_idx_y + 1] += tmp * A[2 * n2 + j][j0 + 4 * i + 1];
        y[base_idx_y + 2] += tmp * A[2 * n2 + j][j0 + 4 * i + 2];
        y[base_idx_y + 3] += tmp * A[2 * n2 + j][j0 + 4 * i + 3];
    }
    for (i = 0; i < m; i++) {
        y[4 * m4 + i] += tmp * A[2 * n2 + j][j0 + 4 * m4 + i];
    }
}
}
