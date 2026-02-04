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
extern int n4;
extern double *Aref;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (i = 0; i < m; i += 2) {
    double tmp1 = (i < m) ? alpha * x[i] : 0.0;
    double tmp2 = (i + 1 < m) ? alpha * x[i + 1] : 0.0;
    double *Aref1 = &(A[i][j0]);
    double *Aref2 = (i + 1 < m) ? &(A[i + 1][j0]) : NULL;

    for (j = 0; j < n4; j++) {
        double yval0 = y[4 * j], yval1 = y[4 * j + 1], yval2 = y[4 * j + 2], yval3 = y[4 * j + 3];
        Aref1[4 * j] += tmp1 * yval0;
        Aref1[4 * j + 1] += tmp1 * yval1;
        Aref1[4 * j + 2] += tmp1 * yval2;
        Aref1[4 * j + 3] += tmp1 * yval3;
        if (i + 1 < m) {
            Aref2[4 * j] += tmp2 * yval0;
            Aref2[4 * j + 1] += tmp2 * yval1;
            Aref2[4 * j + 2] += tmp2 * yval2;
            Aref2[4 * j + 3] += tmp2 * yval3;
        }
    }
    Aref1 += 4 * n4;
    Aref2 = (i + 1 < m) ? (Aref2 + 4 * n4) : NULL;
    y += 4 * n4;

    for (j = 0; j < n; j++) {
        Aref1[j] += tmp1 * y[j];
        if (i + 1 < m)
            Aref2[j] += tmp2 * y[j];
    }
}
}
