#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int _usr_j0;
extern double alpha;
extern double **A;
extern double *x;
extern double *y;
extern int i;
extern int j;
extern int m4;
extern int n2;
extern double *Aref0;
extern double *Aref1;
extern double tmp0;
extern double tmp1;
extern double yval0;
extern double yval1;
extern double yval2;
extern double yval3;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (j = 0; j < n2; j++) {
    tmp0 = alpha * x[2 * j];
    tmp1 = alpha * x[2 * j + 1];
    Aref0 = &(A[2 * j][j0]);
    Aref1 = &(A[2 * j + 1][j0]);
    for (i = 0; i < m4; i++) {
        int base_idx = 4 * i;
        double a0_0 = Aref0[base_idx],     a0_1 = Aref0[base_idx + 1],
               a0_2 = Aref0[base_idx + 2], a0_3 = Aref0[base_idx + 3];
        double a1_0 = Aref1[base_idx],     a1_1 = Aref1[base_idx + 1],
               a1_2 = Aref1[base_idx + 2], a1_3 = Aref1[base_idx + 3];
        double y_0 = y[base_idx]     + tmp0 * a0_0,
               y_1 = y[base_idx + 1] + tmp0 * a0_1,
               y_2 = y[base_idx + 2] + tmp0 * a0_2,
               y_3 = y[base_idx + 3] + tmp0 * a0_3;
        y[base_idx]     = y_0 + tmp1 * a1_0;
        y[base_idx + 1] = y_1 + tmp1 * a1_1;
        y[base_idx + 2] = y_2 + tmp1 * a1_2;
        y[base_idx + 3] = y_3 + tmp1 * a1_3;
    }
    y += 4 * m4;
    Aref0 += 4 * m4;
    Aref1 += 4 * m4;
    for (i = 0; i < m; i++)
        y[i] += tmp0 * Aref0[i] + tmp1 * Aref1[i];
}
}
