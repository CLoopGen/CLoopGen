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
for (j = 0; j < n2; j += 2) {
    double tmp0_0, tmp1_0, tmp0_1, tmp1_1;
    double *Aref0_0, *Aref1_0, *Aref0_1, *Aref1_1;
    
    tmp0_0 = alpha * x[2 * j];
    tmp1_0 = alpha * x[2 * j + 1];
    Aref0_0 = &(A[2 * j][j0]);
    Aref1_0 = &(A[2 * j + 1][j0]);

    if (j + 1 < n2) {
        tmp0_1 = alpha * x[2 * (j + 1)];
        tmp1_1 = alpha * x[2 * (j + 1) + 1];
        Aref0_1 = &(A[2 * (j + 1)][j0]);
        Aref1_1 = &(A[2 * (j + 1) + 1][j0]);
    }

    for (i = 0; i < m4; i++) {
        yval0 = y[4 * i] + tmp0_0 * Aref0_0[4 * i];
        yval1 = y[4 * i + 1] + tmp0_0 * Aref0_0[4 * i + 1];
        yval2 = y[4 * i + 2] + tmp0_0 * Aref0_0[4 * i + 2];
        yval3 = y[4 * i + 3] + tmp0_0 * Aref0_0[4 * i + 3];

        y[4 * i] = yval0 + tmp1_0 * Aref1_0[4 * i];
        y[4 * i + 1] = yval1 + tmp1_0 * Aref1_0[4 * i + 1];
        y[4 * i + 2] = yval2 + tmp1_0 * Aref1_0[4 * i + 2];
        y[4 * i + 3] = yval3 + tmp1_0 * Aref1_0[4 * i + 3];

        if (j + 1 < n2) {
            yval0 = y[4 * i] + tmp0_1 * Aref0_1[4 * i];
            yval1 = y[4 * i + 1] + tmp0_1 * Aref0_1[4 * i + 1];
            yval2 = y[4 * i + 2] + tmp0_1 * Aref0_1[4 * i + 2];
            yval3 = y[4 * i + 3] + tmp0_1 * Aref0_1[4 * i + 3];

            y[4 * i] = yval0 + tmp1_1 * Aref1_1[4 * i];
            y[4 * i + 1] = yval1 + tmp1_1 * Aref1_1[4 * i + 1];
            y[4 * i + 2] = yval2 + tmp1_1 * Aref1_1[4 * i + 2];
            y[4 * i + 3] = yval3 + tmp1_1 * Aref1_1[4 * i + 3];
        }
    }

    y += 4 * m4;
    Aref0_0 += 4 * m4;
    Aref1_0 += 4 * m4;
    if (j + 1 < n2) {
        Aref0_1 += 4 * m4;
        Aref1_1 += 4 * m4;
    }

    for (i = 0; i < m; i++) {
        y[i] += tmp0_0 * Aref0_0[i] + tmp1_0 * Aref1_0[i];
        if (j + 1 < n2)
            y[i] += tmp0_1 * Aref0_1[i] + tmp1_1 * Aref1_1[i];
    }
}
}
