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

    double sum_y0 = 0.0, sum_y1 = 0.0, sum_y2 = 0.0, sum_y3 = 0.0;
    for (i = 0; i < m4; i++) {
        sum_y0 += y[4 * i];
        sum_y1 += y[4 * i + 1];
        sum_y2 += y[4 * i + 2];
        sum_y3 += y[4 * i + 3];

        yval0 = tmp0 * Aref0[4 * i];
        yval1 = tmp0 * Aref0[4 * i + 1];
        yval2 = tmp0 * Aref0[4 * i + 2];
        yval3 = tmp0 * Aref0[4 * i + 3];

        y[4 * i] = yval0 + tmp1 * Aref1[4 * i];
        y[4 * i + 1] = yval1 + tmp1 * Aref1[4 * i + 1];
        y[4 * i + 2] = yval2 + tmp1 * Aref1[4 * i + 2];
        y[4 * i + 3] = yval3 + tmp1 * Aref1[4 * i + 3];
    }

    y[0] += sum_y0;
    y[1] += sum_y1;
    y[2] += sum_y2;
    y[3] += sum_y3;

    y += 4 * m4;
    Aref0 += 4 * m4;
    Aref1 += 4 * m4;

    for (i = 0; i < m; i++) {
        double temp = tmp0 * Aref0[i] + tmp1 * Aref1[i];
        y[i] += temp;
    }
}
}
