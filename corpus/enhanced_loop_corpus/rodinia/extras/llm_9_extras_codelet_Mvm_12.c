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
    Aref = &(A[2 * n2 + j][j0]);
    for (i = 0; i < m4; i++) {
        double a0 = Aref[4 * i], a1 = Aref[4 * i + 1];
        double a2 = Aref[4 * i + 2], a3 = Aref[4 * i + 3];
        y[4 * i] += tmp * a0;
        y[4 * i + 1] += tmp * a1;
        y[4 * i + 2] += tmp * a2;
        y[4 * i + 3] += tmp * a3;
    }
    for (i = m4 * 4; i < m; i++) {
        y[i] += tmp * A[i][j0];
    }
}
}
