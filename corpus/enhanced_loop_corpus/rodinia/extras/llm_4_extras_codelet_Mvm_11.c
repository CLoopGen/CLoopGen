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
    if (tmp0 != 0.0 || tmp1 != 0.0) {
        for (i = 0; i < m4; i++) {
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
    } else {
        y += 4 * m4;
        Aref0 += 4 * m4;
        Aref1 += 4 * m4;
        y += m;
        Aref0 += m;
        Aref1 += m;
    }
}
}
