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
    for (i = 0; i < m4; i += 2) {
        double temp_yval0_0 = y[4 * i] + tmp0 * Aref0[4 * i];
        double temp_yval1_0 = y[4 * i + 1] + tmp0 * Aref0[4 * i + 1];
        double temp_yval2_0 = y[4 * i + 2] + tmp0 * Aref0[4 * i + 2];
        double temp_yval3_0 = y[4 * i + 3] + tmp0 * Aref0[4 * i + 3];
        double temp_yval0_1 = y[4 * i + 4] + tmp0 * Aref0[4 * i + 4];
        double temp_yval1_1 = y[4 * i + 5] + tmp0 * Aref0[4 * i + 5];
        double temp_yval2_1 = y[4 * i + 6] + tmp0 * Aref0[4 * i + 6];
        double temp_yval3_1 = y[4 * i + 7] + tmp0 * Aref0[4 * i + 7];

        y[4 * i] = temp_yval0_0 + tmp1 * Aref1[4 * i];
        y[4 * i + 1] = temp_yval1_0 + tmp1 * Aref1[4 * i + 1];
        y[4 * i + 2] = temp_yval2_0 + tmp1 * Aref1[4 * i + 2];
        y[4 * i + 3] = temp_yval3_0 + tmp1 * Aref1[4 * i + 3];
        y[4 * i + 4] = temp_yval0_1 + tmp1 * Aref1[4 * i + 4];
        y[4 * i + 5] = temp_yval1_1 + tmp1 * Aref1[4 * i + 5];
        y[4 * i + 6] = temp_yval2_1 + tmp1 * Aref1[4 * i + 6];
        y[4 * i + 7] = temp_yval3_1 + tmp1 * Aref1[4 * i + 7];
    }
    for (; i < m4; i++) {
        yval0 = y[4 * i] + tmp0 * Aref0[4 * i];
        yval1 = y[4 * i + 1] + tmp0 * Aref0[4 * i + 1];
        yval2 = y[4 * i + 2] + tmp0 * Aref0[4 * i + 2];
        yval3 = y[4 * i + 3] + tmp0 * Aref0[4 * i + 3];
        y[4 * i] = yval0 + tmp1 * Aref1[4 * i];
        y[4 * i + 1] = yval1 + tmp1 * Aref1[4 * i + 1];
        y[4 * i + 2] = yval2 + tmp1 * Aref1[4 * i + 2];
        y[4 * i + 3] = yval3 + tmp1 * Aref1[4 * i + 3];
    }
    y += 4 * m4;
    Aref0 += 4 * m4;
    Aref1 += 4 * m4;
    for (i = 0; i < m; i++)
        y[i] += tmp0 * Aref0[i] + tmp1 * Aref1[i];
}
}
